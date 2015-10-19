// Реализуйте метод, который зачитает данные из InputStream и преобразует их в строку, используя заданную кодировку.

// Пример

// InputStream последовательно возвращает четыре байта: 48 49 50 51.

// Метод, вызванный для такого InputStream и кодировки ASCII, должен вернуть строку "0123".

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Reader {
    public static void main(String[] args) throws Exception {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            for (;;) {
                System.out.println(">> ");
                String expr = reader.readLine();
                String result = "OK";
                System.out.println(result);
            }
        }
    }
}

