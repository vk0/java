package ru.csc.java2014.networking.uri;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class HttpConnectionDemo2 {

    public static void main(String[] args) throws Exception {
        URL url = new URL("http://ya.ru/");

        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        try {
            connection.setConnectTimeout(1000);

            connection.connect();

            System.out.printf("Response code: %d\n", connection.getResponseCode());
            System.out.printf("Response message: %s\n", connection.getResponseMessage());
            System.out.printf("Content type: %s\n", connection.getContentType());
            System.out.printf("Content length: %d\n", connection.getContentLength());

            try (InputStream inputStream = connection.getInputStream()) {
                new BufferedReader(new InputStreamReader(inputStream, "UTF-8"))
                        .lines()
                        .forEach(System.out::println);
            }
        } finally {
            connection.disconnect();
        }
    }
}
