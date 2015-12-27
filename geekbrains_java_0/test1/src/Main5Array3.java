import java.util.Arrays;

/**
 * Created by igor on 17.05.15.
 */
public class Main5Array3 {
    public static void main(String[] args) {
        char[][] cells;
        cells = new char[3][4];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                cells[j][i] = '.';
            }
        }

        cells[1][1] = 'O';
        cells[2][1] = 'X';

//        System.out.println(Arrays.toString(cells)); // не красиво
        System.out.println(Arrays.deepToString(cells)); // не красиво

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(cells[j][i]);
            }
            System.out.println();
        }

    }
}

// 0 1 2 -- x ось абцисс
//
// . . .   0
// . O X   1
// . . .   2
// . . .   3

