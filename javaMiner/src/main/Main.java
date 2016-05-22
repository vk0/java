package main;

import org.lwjgl.input.Keyboard;
import org.lwjgl.input.Mouse;
import org.lwjgl.opengl.Display;

public class Main {

	static boolean end_of_game=false;
	
	public static void main(String[] args) {
		GUI.init();
		
		while(!end_of_game){
			
			input();
			
			GUI.draw();
			
			GUI.update();
		}
		
		Display.destroy();
	}

	private static void input() {
		///Если за последний такт произошли какие-то события с мышью,
		///перебираем их по очереди
		while(Mouse.next()){
		                ///Если это было нажатие кнопки мыши, а не
		                ///перемещение...
		        if(Mouse.getEventButton()>=0 && Mouse.getEventButtonState()){
		            int result;
		                    ///Отсылаем это на обработку в GUI
		            result = GUI.recieveClick(Mouse.getEventX(), Mouse.getEventY(), Mouse.getEventButton());
		            
		            switch(result){
		            case 0:
		                //отличнео!
		                break;
		            case -1:
		                //не очень :c                
		                GUI.gameover();
		                break;
		            }
		        }
		    }
		    
		        ///То же самое с клавиатурой
		    while(Keyboard.next()){
		        if(Keyboard.getEventKeyState()){
		            if(Keyboard.getEventKey()==Keyboard.KEY_ESCAPE){
		                end_of_game = true;
		            }
		        }
		    }
		 
		        ///Обрабатываем клик по кнопке "закрыть" окна
		        end_of_game=end_of_game || Display.isCloseRequested();
	}

}
