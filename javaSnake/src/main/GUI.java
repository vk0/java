package main;

import org.lwjgl.LWJGLException;
import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.DisplayMode;

import java.util.Random;

import static main.Constants.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Created by dokel on 5/9/16.
 */

public class GUI {
    ///CELLS_COUNT_X и CELLS_COUNT_Y -- константы
    //Cell -- класс, который реализует main.GUIElement; им займёмся немного позже
    private static Cell[][] cells;


    public static void init(){
        initializeOpenGL();

        cells = new Cell[CELLS_COUNT_X][CELLS_COUNT_Y];

        Random rnd = new Random();

        for(int i=0; i<CELLS_COUNT_X; i++){
            for(int j=0; j<CELLS_COUNT_Y; j++){
                cells[i][j]=new Cell(i*CELL_SIZE, j*CELL_SIZE,rnd.nextInt(100)<INITIAL_SPAWN_CHANCE?-1:0);
                //TODO randomize objects
            }
        }
    }


    //Этот метод будет вызываться извне
    public static void update(boolean have_to_decrease) {
        updateOpenGL();

        for(Cell[] line:cells){
            for(Cell cell:line){
                cell.update(have_to_decrease);
            }
        }
    }

    ///Рисует все клетки
    public static void draw(){
        ///Очищает экран от старого изображения
        glClear(GL_COLOR_BUFFER_BIT);

        for(Cell[] line:cells){
            for(Cell cell:line){
                drawElement(cell);
            }
        }
    }

    ///Рисует элемент, переданный в аргументе
    private static void drawElement(Cell elem){
        if(elem.getSprite()==null) return;

        elem.getSprite().getTexture().bind();

        glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex2f(elem.getX(),elem.getY()+elem.getHeight());
        glTexCoord2f(1,0);
        glVertex2f(elem.getX()+elem.getWidth(),elem.getY()+elem.getHeight());
        glTexCoord2f(1,1);
        glVertex2f(elem.getX()+elem.getWidth(), elem.getY());
        glTexCoord2f(0,1);
        glVertex2f(elem.getX(), elem.getY());
        glEnd();
    }

    public static int getState(int x, int y){
        return cells[x][y].getState();
    }

    public static void setState(int x, int y, int state){
        cells[x][y].setState(state);
    }

    ///А этот метод будет использоваться только локально,
    /// т.к. базовым другие классы должны работать на более высоком уровне
    private static void updateOpenGL() {
        Display.update();
        Display.sync(FPS);
    }

    private static void initializeOpenGL(){
        try {
            //Задаём размер будущего окна
            Display.setDisplayMode(new DisplayMode(SCREEN_WIDTH, SCREEN_HEIGHT));

            //Задаём имя будущего окна
            Display.setTitle(SCREEN_NAME);

            //Создаём окно
            Display.create();
        } catch (LWJGLException e) {
            e.printStackTrace();
        }

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,SCREEN_WIDTH,0,SCREEN_HEIGHT,1,-1);
        glMatrixMode(GL_MODELVIEW);

        /*
         * Для поддержки текстур
         */
        glEnable(GL_TEXTURE_2D);

        /*
         * Для поддержки прозрачности
         */
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


        /*
         * Белый фоновый цвет
         */
        glClearColor(1,1,1,1);
    }
}
