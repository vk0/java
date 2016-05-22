package main;
import static main.Constants.*;

public class Cell implements GUIElement {

	private int x;
	private int y;
	private int state;
	private boolean isHiden=true;
	private boolean isMarked=false;
	
	public Cell (int x, int y, int state){
		this.x=x;
		this.y=y;
		this.state=state;
	}	

	@Override
	public int getWidth() {
		return CELL_SIZE;
	}

	@Override
	public int getHeight() {
		return CELL_SIZE;
	}

	@Override
	public int getY() {
		return this.y;
	}

	@Override
	public int getX() {
		return this.x;
	}

	@Override
	public Sprite getSprite() {
		if(this.isMarked){
			if(!this.isHiden && this.state!=-1){
				///Если эта клетка не скрыта, и на ней
				///ошибочно стоит флажок...
				return Sprite.BROKEN_FLAG;
			}
			///В другом случае --
			return Sprite.FLAG;				
		}else if(this.isHiden){
			///Если клетка не помечена, притом скрыта...
			return Sprite.HIDEN;
		}else{
			///Если не помечена и не скрыта, выводим как есть:
			switch (state){
			case -2:
				return Sprite.EXPLOSION;
			case -1:
				return Sprite.BOMB;
			default:
				assert (state>=0 && state<=8): "Some crap :c";
				///Сделал массив для удобства. Можете, конечно,
				///Писать 9 кейсов -- ваш выбор ;)
				return  skin_by_number[state];
			}
		}
	}

	@Override
	public int recieveClick(int x, int y, int button) {
		if(isHiden){
			///Нет смысла обрабатывать клики по уже открытым полям
			if(button==0 && !this.isMarked){
				///Здесь обработаем щелчки левой кнопкой
				///Заметим, что щёлкать левой кнопкой по влагам
				///абсолютно бессмысленно
				
				///Открываем клетку
				this.isHiden = false;
				
				if(this.state==-1){
					///Если это была мина, меняем состояние
					///на взорванную и передаём сигнал назад
					this.state=-2;
					return -1;
				}
				
				if(this.state == 0){
					///Если мы попали в нолик, нужно открыть
					///Все соседние ячейки. Этим займётся GUI :)
					return 1;
				}
				
			}else if(button==1){
				///В любой ситуации, щелчок правой кнопкой
				///либо снимает отметку, либо ставит её
				this.isMarked = ! this.isMarked;
			}
		}
		
		return 0;
	}

	public void incNearMines() {
		if(state<0){
			//ignore
		}else{		
			state++;
		}
	}
	
	public void show() {
        this.isHiden=false;
    }
}
