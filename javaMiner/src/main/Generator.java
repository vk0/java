package main;

import java.util.Random;
import static main.Constants.*;

public class Generator {

	public static Cell[][] generate() {
		{
			Random rnd = new Random();
			
			///Карта, которую мы вернём
			Cell[][] map = new Cell[CELLS_COUNT_X][CELLS_COUNT_Y];
			
			///Матрица с пометками, указывается кол-во мин рядом с каждой клеткой
			int[][] counts = new int[CELLS_COUNT_X][CELLS_COUNT_Y];
			
			for(int x=0; x<CELLS_COUNT_X; x++){
				for(int y=0; y<CELLS_COUNT_Y; y++){
					boolean isMine = rnd.nextInt(100)<15;
					
					if(isMine){
						map[x][y] = new Cell(x*CELL_SIZE, y*CELL_SIZE, -1);
						
						for(int i=-1; i<2; i++){
							for(int j=-1; j<2; j++){
								try{
									if(map[x+i][y+j]==null){
										///Если кдетки там ещё нет, записываем сведение
										///о мине в матрицу
										counts[x+i][y+j]+=1;
									}else{
										///Если есть, говорим ей о появлении мины
										map[x+i][y+j].incNearMines();
									}
								}catch(java.lang.ArrayIndexOutOfBoundsException e){
									//ignore
								}
							}
						}
					}else{
						///Если была сгенерирована обычная клетка, создаём её, со
						///state равным значению из матрицы
						map[x][y] = new Cell(x*CELL_SIZE, y*CELL_SIZE, counts[x][y]);
					}
				}
			}
			
			return map;
		}
	}

}
