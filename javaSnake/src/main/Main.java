package main;

import org.lwjgl.input.Keyboard;
import org.lwjgl.opengl.Display;

import java.util.Random;

import static main.Constants.*;

/**
 * Created by dokel on 5/9/16.
 */



public class Main {
    private static boolean isExitRequested=false;
    private static int x=-1,y=0, direction=1, length=3;
    private static boolean have_to_decrease = true;

    public static void main(String[] args) {
        GUI.init();
        generate_new_obj();

        while(!isExitRequested){
            input();

            move();

            GUI.draw();
            GUI.update(have_to_decrease);

        }
    }

    private static void move() {
        have_to_decrease=true;

        switch(direction){
            case 0:
                y++; break;
            case 1:
                x++; break;
            case 2:
                y--; break;
            case 3:
                x--; break;
        }

        if(x<0 || x>=CELLS_COUNT_X || y<0 || y>=CELLS_COUNT_Y){
            //TODO gameover
            System.exit(1);
        }

        int next_cell_state = GUI.getState(x,y);

        if(next_cell_state>0){
            //TODO gameover
            System.exit(1);

        }else{
            if(next_cell_state<0){
                length++;
                generate_new_obj();
                have_to_decrease=false;
            }
            GUI.setState(x,y,length);
        }
    }

    private static void generate_new_obj() {
        int point = new Random().nextInt(CELLS_COUNT_X*CELLS_COUNT_Y-length);

        for(int i=0; i<CELLS_COUNT_X; i++){
            for(int j=0; j<CELLS_COUNT_Y; j++){
                if(GUI.getState(i,j)<=0) {
                    if (point == 0) {
                        GUI.setState(i, j, -1); //TODO randomize objects
                        return;
                    }else {
                        point--;
                    }
                }
            }
        }

    }


    private static void input(){
        while(Keyboard.next()){
            if(Keyboard.getEventKeyState()){
                switch(Keyboard.getEventKey()) {
                    case Keyboard.KEY_ESCAPE:
                        isExitRequested = true;
                        break;
                    case Keyboard.KEY_UP:
                        if(direction!=2) direction=0;
                        break;
                    case Keyboard.KEY_RIGHT:
                        if(direction!=3) direction=1;
                        break;
                    case Keyboard.KEY_DOWN:
                        if(direction!=0) direction=2;
                        break;
                    case Keyboard.KEY_LEFT:
                        if(direction!=1) direction=3;
                        break;
                }
            }
        }

        ///Обрабатываем клик по кнопке "закрыть" окна
        isExitRequested=isExitRequested || Display.isCloseRequested();
    }

}
