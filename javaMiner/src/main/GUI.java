package main;
import static main.Constants.*;
import static org.lwjgl.opengl.GL11.*;

import org.lwjgl.LWJGLException;
import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.DisplayMode;

public class GUI{

	private static Cell[][] cells;

	public static void init(){
		initializeOpenGL();
		
		cells = Generator.generate();
	}
	
	public static void draw(){
		glClear(GL_COLOR_BUFFER_BIT);
		
		for(GUIElement[] line:cells){
			for(GUIElement cell:line){
				drawElement(cell);
			}
		}
	}

	private static void drawElement(GUIElement elem){
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
	
	public static int recieveClick(int x, int y, int button){
		int cell_x = x/CELL_SIZE;
		int cell_y = y/CELL_SIZE;
		
		int result =  cells[cell_x][cell_y].recieveClick(x,y,button);
		
		if(result==1){
			///Делаем вид, что тыкнули в клетки
			///Сверху, снизу, справа и слева
			try{
				recieveClick(x+CELL_SIZE,y,button);
			}catch(java.lang.ArrayIndexOutOfBoundsException e){
				//ignore
			}
			try{
				recieveClick(x-CELL_SIZE,y,button);
			}catch(java.lang.ArrayIndexOutOfBoundsException e){
				//ignore
			}
			try{
				recieveClick(x,y+CELL_SIZE,button);
			}catch(java.lang.ArrayIndexOutOfBoundsException e){
				//ignore
			}
			try{
				recieveClick(x,y-CELL_SIZE,button);
			}catch(java.lang.ArrayIndexOutOfBoundsException e){
				//ignore
			}
			return 0;
		}
		
		return result;
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

	///Этот метод будет вызываться извне
	public static void update() {
	        updateOpenGL();
	      /// Сюда можно ещё чего-нибудь добавить
	}
	 
	///А этот метод будет использоваться только локально,
	/// т.к. базовым другие классы должны работать на более высоком уровне
	private static void updateOpenGL() {
	        Display.update();
	        Display.sync(60);    
	}

	public static void gameover() {
		for(Cell[] line:cells){
			for(Cell cell:line){
				cell.show();
			}
		}		
	}
}
