package ru.csc.java2014.networking.uri;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.nio.charset.StandardCharsets;

public class HttpConnectionDemo {

    public static void main(String[] args) throws Exception {
        URL url = new URL("http://ya.ru/");
        try (InputStream inputStream = url.openStream()) {
            new BufferedReader(new InputStreamReader(inputStream, StandardCharsets.UTF_8))
                    .lines()
                    .forEach(System.out::println);
        }
    }
}
