/*
javac.exe HelloWorld.java
java HelloWorld
javap -v HelloWorld.class
jar cfe hw.jar HelloWorld HelloWorld.class
jar tf hw.jar
jar xf hw.jar
java -jar hw.tar
java -classpath lib.jar:hw.jar Helloworld
*/
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
        System.exit(-1);
    }
}
