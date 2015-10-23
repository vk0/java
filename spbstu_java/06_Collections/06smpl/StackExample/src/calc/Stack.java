/*
 * $Id:$
 */

package calc;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.NoSuchElementException;

/**
 * Класс "стек"
 * @author Mike
 */
public class Stack<E> {
    /**
     * Здесь храним содержимое стека
     */
    private final Deque<E> stack = new ArrayDeque<E>();

    /**
     * Затолкнуть элемент в стек
     * @param x заталкиваемый элемент
     */
    public void push(E elem) {
        stack.push(elem);
    }

    /**
     * Вытолкнуть элемент из стека
     * @return вытолкнутый элемент
     * @throws NoSuchElementException если стек пуст
     */
    public E pop() throws NoSuchElementException {
        return stack.pop();
    }

    /**
     * Получить вершину стека (не выталкивая ее)
     * @return вершина стека
     * @throws NoSuchElementException если стек пуст
     */
    public E top() throws NoSuchElementException {
        return stack.getFirst();
    }
}
