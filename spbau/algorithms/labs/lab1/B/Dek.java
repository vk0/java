import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * User: Dmitriy Bandurin
 */
public class Dek {

    public static void main(String[] args) throws IOException {
        InputStreamReader in = new InputStreamReader(System.in);

        BufferedReader bufferedReader = new BufferedReader(in);

        Deque deque = new Deque();
        String command;
        while ((command = bufferedReader.readLine()) != null) {
            char ch = command.charAt(1);
            switch (ch) {
                case 'u':  //push
                    if (command.charAt(5) == 'f') { //front
                        deque.pushFront(command.substring(11));
                    } else {                        //back
                        deque.pushBack(command.substring(10));
                    }
                    break;
                case 'o': //pop
                    if (command.charAt(4) == 'f') { //front
                        deque.popFront();
                    } else {                      //back
                        deque.popBack();
                    }
                    break;
                case 'r':  //front
                    deque.front();
                    break;
                case 'a':  //back
                    deque.back();
                    break;
                case 'i':  //size
                    deque.size();
                    break;
                case 'l':  //clear
                    deque.clear();
                    break;
                case 'x':  //exit
                    System.out.println("bye");
                    return;
                default:
                    break;
            }
        }
    }
}

class Deque {

    private class Entry {
        Entry previous;
        Entry next;
        String object;
    }

    private int count = 0;
    // next - front; previous - back
    private Entry entry = new Entry();

    public void pushFront(String object) {
        Entry newEntry = new Entry();
        newEntry.object = object;
        newEntry.previous = entry.next;
        if (newEntry.previous != null) {
            newEntry.previous.next = newEntry;
        }
        entry.next = newEntry;
        if (count == 0) {
            entry.previous = newEntry;
        }
        count++;
        System.out.println("ok");
    }

    public void pushBack(String object) {
        Entry newEntry = new Entry();
        newEntry.object = object;
        newEntry.next = entry.previous;
        if (newEntry.next != null) {
            newEntry.next.previous = newEntry;
        }
        entry.previous = newEntry;
        if (count == 0) {
            entry.next = newEntry;
        }
        count++;
        System.out.println("ok");
    }

    public void popFront() {
        if (count == 0) {
            System.out.println("error");
        } else {
            Entry result = entry.next;
            entry.next = result.previous;
            if (entry.next != null) {
                entry.next.next = null;
            } else {
                entry.previous = null;
            }
            count--;
            System.out.println(result.object);
        }

    }

    public void popBack() {
        if (count == 0) {
            System.out.println("error");
        } else {
            Entry result = entry.previous;
            entry.previous = result.next;
            if (entry.previous != null) {
                entry.previous.previous = null;
            } else {
                entry.next = null;
            }
            count--;
            System.out.println(result.object);
        }
    }

    public void front() {
        if (count == 0) {
            System.out.println("error");
        } else {
            System.out.println(entry.next.object);
        }
    }

    public void back() {
        if (count == 0) {
            System.out.println("error");
        } else {
            System.out.println(entry.previous.object);
        }
    }

    public void size() {
        System.out.println(count);
    }

    public void clear() {
        count = 0;
        entry.next = null;
        entry.previous = null;
        System.out.println("ok");
    }
}