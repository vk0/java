package main;

import static main.Constants.CELL_SIZE;

/**
 * Created by dokel on 5/9/16.
 */
public class Cell {

    private int x;
    private int y;
    private int state;/* 0 -> ячейка пуста
                        >0 -> в ячейке тело змеи, которое будет там ещё N фреймов
                        <0 -> Что-то необычное:
                            -1: Ягоды
                        */

    ///Конструктор просто выставляет начальные значения координат и состояния
    public Cell (int x, int y, int state){
        this.x=x;
        this.y=y;
        this.state=state;
    }

    ///==== Ничем не примечательные геттеры и сеттеры

    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }

    public int getHeight(){
        return CELL_SIZE;
    }

    public int getWidth(){
        return CELL_SIZE;
    }

    public int getState(){
        return this.state;
    }

    public void setState(int state){
        this.state = state;
    }

    ///====

    ///Метод обновления клетки. Уменьшаем время "горения", если это необходимо
    public void update(boolean have_to_decrease){
        if (have_to_decrease && this.state>0){
            this.state--;
        }
    }

    ///Ячейка "думает" как она должна выглядеть
    public Sprite getSprite(){
        if(this.state>0){
            ///Если в ней тело змеи -- как змея
            return Sprite.BODY;
        }else if(this.state==0){
            ///Если в ней нет ничего -- никак выглядеть и не должна
            return null;
        }else{
            ///Иначе проходимся свитчем по возможным объектам.
            ///Так как это демо -- я добавил только ягоды
            switch(this.state){
                default: return Sprite.CHERRIES;
            }
        }
    }


}
