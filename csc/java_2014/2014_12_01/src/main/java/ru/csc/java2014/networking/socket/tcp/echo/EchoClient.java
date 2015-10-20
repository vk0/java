package ru.csc.java2014.networking.socket.tcp.echo;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

public class EchoClient {

    public static void main(String[] args) throws Exception {
        try (Socket socket = new Socket("localhost", 11111)) {

            DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());
            outputStream.writeUTF("Hello!");
            outputStream.flush();

            DataInputStream inputStream = new DataInputStream(socket.getInputStream());
            String response = inputStream.readUTF();

            System.out.println(response);
        }
    }
}
