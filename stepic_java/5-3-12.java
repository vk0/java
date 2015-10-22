// Реализуйте метод, который зачитает данные из InputStream и преобразует их в строку, используя заданную кодировку.

// Пример

// InputStream последовательно возвращает четыре байта: 48 49 50 51.

// Метод, вызванный для такого InputStream и кодировки ASCII, должен вернуть строку "0123".

import java.io.*;
import java.nio.charset.Charset;

public class Main {
    public static void main(String[] args) throws IOException {
        byte[] bytes = {48, 49, 50, 51};
        InputStream inputStream = new ByteArrayInputStream(bytes);
        String sout = readAsString(inputStream, Charset.forName("ASCII"));
        System.out.println(sout);
    }

    public static String readAsString(InputStream inputStream, Charset charset) throws IOException {
        Reader reader = new InputStreamReader(inputStream, charset);
        String str = "";
        int i;
        while ( (i = reader.read()) != -1) {
                str += (char)i;
        }
        return str;
    }
}
