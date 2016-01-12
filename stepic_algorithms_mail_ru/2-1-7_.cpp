// Реализуйте дек с динамическим зацикленным буфером.
// Для тестирования дека на вход подаются команды.
// В первой строке количество команд. Затем в каждой строке записана одна команда.

// Каждая команда задаётся как 2 целых числа: a b.

// a = 1 - push front,

// a = 2 - pop front,

// a = 3 - push back,

// a = 4 - pop back.

// Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”.

// Требуется напечатать YES, если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

// Sample Input:

// 5
// 1 44
// 3 50
// 2 44
// 2 50
// 2 -1

// Sample Output:

// YES

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define START_BUFFER_SIZE 32

class deque {
public:
    deque();
    virtual ~deque();
    void pushBack(int element);
    int popBack();
    void pushFront(int element);
    int popFront();
private:
    int* buffer;
    int buffer_size;
    int front_index;
    int back_index;
    void growBack();
    void growFront();
};

deque::deque() {
    buffer = new int[START_BUFFER_SIZE];
    buffer_size = START_BUFFER_SIZE;
    back_index = -1;
    front_index = -1;
}

deque::~deque() {
    delete[] buffer;
}

void deque::growBack() {
    if (back_index != 0) {
        return;
    }

    int to_add = buffer_size;
    int *new_buffer = new int[buffer_size + to_add];

    for (int i = 0; i < buffer_size; i++) {
        new_buffer[i + to_add] = buffer[i];
    }

    delete[] buffer;

    buffer = new_buffer;
    buffer_size += to_add;
    back_index += to_add;
    front_index += to_add;
}

void deque::growFront() {
    if (front_index != buffer_size - 1) {
        return;
    }

    int to_add = buffer_size;
    int *new_buffer = new int[buffer_size + to_add];

    for (int i = 0; i < buffer_size; i++) {
        new_buffer[i] = buffer[i];
    }

    delete[] buffer;

    buffer = new_buffer;
    buffer_size += to_add;
}

void deque::pushBack(int element) {
    if (back_index != -1) {
        if (back_index == 0) {
            growBack();
        }
    } else {
        back_index = buffer_size / 2;
    }

    buffer[--back_index] = element;

    if (front_index == -1) {
        front_index = back_index;
    }
}

int deque::popBack() {
    if (back_index == front_index && back_index == -1) {
        return -1;
    }

    int result = buffer[back_index];

    back_index++;

    if (back_index > front_index) {
        back_index = -1;
        front_index = -1;
    }

    return result;
}

void deque::pushFront(int element) {
    if (front_index != -1) {
        if (front_index == buffer_size - 1) {
            growFront();
        }
    } else {
        front_index = buffer_size / 2 - 1;
    }

    buffer[++front_index] = element;

    if (back_index == -1) {
        back_index = front_index;
    }
}

int deque::popFront() {
    if (back_index == front_index && back_index == -1) {
        return -1;
    }

    int result = buffer[front_index];

    front_index--;

    if (front_index < back_index) {
        back_index = -1;
        front_index = -1;
    }

    return result;
}

int main(int argc, char *argv[]) {
    deque d;

    int commands_num, a, b;
    bool correct = true;

    scanf("%d", &commands_num);

    for (int i = 0; i < commands_num; i++) {
        scanf("%d %d", &a, &b);

        if (a == 1) {
            d.pushBack(b);
        } else if (a == 2 && correct) {
            int popped = d.popBack();
            if (popped != b || popped == -1) correct = false;
        } else if (a == 3) {
            d.pushFront(b);
        } else if (a == 4 && correct) {
            int popped = d.popFront();
            if (popped != b || popped == -1) correct = false;
        }
    }

    if (correct) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}