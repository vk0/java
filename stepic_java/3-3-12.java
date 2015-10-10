// На игровом поле находится робот. Позиция робота на поле описывается двумя целочисленным координатами: X и Y. Ось X смотрит слева направо, ось Y — снизу вверх. (Помните, как рисовали графики функций в школе?)

// В начальный момент робот находится в некоторой позиции на поле. Также известно, куда робот смотрит: вверх, вниз, направо или налево. Ваша задача — привести робота в заданную точку игрового поля.

// Робот описывается классом Robot. Вы можете пользоваться следующими его методами (реализация вам неизвестна):

// public class Robot {

//     public Direction getDirection() {
//         // текущее направление взгляда
//     }

//     public int getX() {
//         // текущая координата X
//     }

//     public int getY() {
//         // текущая координата Y
//     }

//     public void turnLeft() {
//         // повернуться на 90 градусов против часовой стрелки
//     }

//     public void turnRight() {
//         // повернуться на 90 градусов по часовой стрелке
//     }

//     public void stepForward() {
//         // шаг в направлении взгляда
//         // за один шаг робот изменяет одну свою координату на единицу
//     }
// }
// Direction, направление взгляда робота,  — это перечисление:
// public enum Direction {
//     UP,
//     DOWN,
//     LEFT,
//     RIGHT
// }
// Пример

// В метод передано: toX == 3, toY == 0; начальное состояние робота такое: robot.getX() == 0, robot.getY() == 0, robot.getDirection() == Direction.UP

// Чтобы привести робота в точку (3, 0), надо дать роботу следующие команды:

// robot.turnRight();
// robot.stepForward();
// robot.stepForward();
// robot.stepForward();
// P.S. Если вам понравилось это задание, то вам может прийтись по душе игра Robocode, в которой надо написать алгоритм управления танком. Алгоритмы, написанные разными людьми, соревнуются между собой.

public static void moveRobot(Robot robot, int toX, int toY) {
    int x = robot.getX();
    int y = robot.getY();

    if (x > toX){
        while(robot.getDirection() != Direction.LEFT){
            robot.turnLeft();
        }
        while(x != toX){
            robot.stepForward();
            x--;
        }
    }
    else if (x < toX){
        while (robot.getDirection() != Direction.RIGHT){
            robot.turnLeft();
        }
        while (x != toX){
            robot.stepForward();
            x++;
        }
    }
    if (y > toY){
        while (robot.getDirection() != Direction.DOWN){
            robot.turnLeft();
        }
        while (y != toY){
            robot.stepForward();
            y--;
        }
    }
    else if (y < toY) {
        while (robot.getDirection() != Direction.UP){
            robot.turnLeft();
        }
        while(y != toY){
            robot.stepForward();
            y++;
        }
    }
}

// 4 TEST класс Robot для проверки программки
// public class Robot {
//     int x=0;
//     int y=0;
//     Direction direction = Direction.UP;

//     public Direction getDirection() {
//         return direction;
//     }

//     public int getX() {
//         return x;
//     }

//     public int getY() {
//         return y;
//     }

//     public void turnLeft() {
//         System.out.println("Поворот против часовой стрелки");
//         if (direction == Direction.DOWN){
//             this.direction = Direction.RIGHT;
//             return;
//         }

//         if (direction == Direction.UP){
//             this.direction = Direction.LEFT;
//             return;
//         }

//         if (direction == Direction.LEFT){
//             this.direction = Direction.DOWN;
//             return;
//         }

//         if (direction == Direction.RIGHT){
//             this.direction = Direction.UP;
//             return;
//         }
//     }

//     public void turnRight() {
//         System.out.println("поворот по часовой стрелке");
//         if (this.direction == Direction.DOWN){
//             System.out.println("Вниз -> влево");
//             this.direction = Direction.LEFT;
//             return;
//         }

//         if (this.direction == Direction.UP){
//             System.out.println("Вверх -> вправо");
//             this.direction = Direction.RIGHT;
//             return;
//         }

//         if (this.direction == Direction.LEFT){
//             System.out.println("Влево -> вверх");
//             this.direction = Direction.UP;
//             return;
//         }

//         if (this.direction == Direction.RIGHT){
//             System.out.println("Вправо -> вниз");
//             this.direction = Direction.DOWN;
//             return;
//         }
//     }

//     public void stepForward() {
//         System.out.println("движение");
//         if (direction == Direction.DOWN){
//             System.out.println("вниз");
//             this.y--;
//         }

//         if (direction == Direction.UP){
//             System.out.println("вверх");
//             this.y++;
//         }

//         if (direction == Direction.LEFT){
//             System.out.println("налево");
//             this.x--;
//         }

//         if (direction == Direction.RIGHT){
//             System.out.println("направо");
//             this.x++;
//         }
//     }