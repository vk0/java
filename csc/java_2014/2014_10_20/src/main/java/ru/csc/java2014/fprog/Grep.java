package ru.csc.java2014.fprog;

import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Grep {

    public static void main(String[] args) throws Exception {
        Path dir = Paths.get(args[0]);
        String keyword = args[1];

        try (Stream<Path> files = Files.walk(dir)) {
            long count = files.filter(Grep::isTextFile)
                    //.peek(System.out::println)
                    .flatMap(Grep::readLines)
                    .filter((s) -> s.contains(keyword))
                    //.peek(System.out::println)
                    .count();
            System.out.println(count);
        }
    }

    private static boolean isTextFile(Path file) {
        String name = file.getFileName().toString();
        return name.endsWith(".tex") || name.endsWith(".txt");
    }

    private static Stream<String> readLines(Path file) {
        try {
            return Files.lines(file, StandardCharsets.UTF_8);
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }
}
