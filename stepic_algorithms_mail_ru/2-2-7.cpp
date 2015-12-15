// Жадина.

// Вовочка ест фрукты из бабушкиной корзины. В корзине лежат фрукты разной массы. Вовочка может поднять не более K грамм. Каждый фрукт весит не более K грамм. За раз он выбирает несколько самых тяжелых фруктов, которые может поднять одновременно, откусывает от каждого половину и кладет огрызки обратно в корзину. Если фрукт весит нечетное число грамм, он откусывает большую половину. Фрукт массы 1гр он съедает полностью.
// Определить за сколько подходов Вовочка съест все фрукты в корзине.

// Напишите свой класс кучи, реализующий очередь с приоритетом.

// Формат входных данных. Вначале вводится n - количество фруктов и строка с целочисленными массами фруктов через пробел. Затем в отдельной строке K - "грузоподъемность".

// Формат выходных данных. Неотрицательное число - количество подходов к корзине.

// Sample Input:

// 3
// 1 2 2
// 2

// Sample Output:

// 4


#include <iostream>
#include <cassert>

// Класс динамического массива целых чисел
class CHeap
{
public:
    CHeap(): buffer(0), size(0), count(0) {}
    CHeap(int _size): size(_size), count(0) {
        buffer = new int[size];
    }
    ~CHeap() { delete[] buffer; }

    int PeekAtNext();
    int ExtractMax();
    void Add(int elem);
    void SiftUp(int index);
    void SiftDown(int index);
    int Count() { return count; }

private:
    int* buffer;
    int size;
    int count;
};

// Показать наибольний элемент
int CHeap::PeekAtNext(){
    return count > 0 ? buffer[0] : 0;
}

// Извлечь наибольший элемент
int CHeap::ExtractMax(){
    assert(count > 0);
    int result = buffer[0];
    std::swap(buffer[0], buffer[--count]);
    if(count > 0) SiftDown(0);
    return result;
}

// Добавить элемент в кучу
void CHeap::Add(int elem){
    assert(count != size);
    buffer[count] = elem;
    SiftUp(count);
    count++;
}

// Проталкивание элемента наверх
void CHeap::SiftUp(int index){
    int parent = 0;
    while(index > 0){
        parent = (index - 1) / 2;
        if(buffer[index] <= buffer[parent])
            return;
        std::swap(buffer[index], buffer[parent]);
        index = parent;
    }
}

// Проталкивание элемента вниз
void CHeap::SiftDown(int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    // Ищем большего сына, если такой есть
    int largest = index;
    if(left < count && buffer[left] > buffer[index])
        largest = left;
    if(right < count && buffer[right] > buffer[largest])
        largest = right;
    // Если больший сын есть, то проталкиваем корень в него
    if( largest != index){
        std::swap(buffer[index], buffer[largest]);
        SiftDown(largest);
    }
}

int main()
{
    int heap_size = 0; // Размер корзины
    std::cin >> heap_size;

    CHeap heap(heap_size); // Исходная корзина

    int weight = 0; // Вес фрукта
    for(int i = 0; i < heap_size; ++i){
        std::cin >> weight;
        heap.Add(weight);
    }

    int max_capacity = 0; // Грузоподъемность
    std::cin >> max_capacity;

    int steps = 0; // Количество подходов
    int total_weight = 0; // Общий поднятый вес данном подходе
    int current_weight = 0; // Вес текущего фрукта
    CHeap buf(heap_size); // Буфер

    // Пока обе корзины не пусты, берем из первой корзины фрукт, если он подходит, то
    // откусываем от него часть и кладем в буфер, когда мы забрали все фрукты из корзины
    // или не можем больше поднять фрукты, то перекладываем все фрукты из буфера в корзину
    // и повторяем действия.
    while(true){
        current_weight = heap.PeekAtNext();
        if(heap.Count() > 0 && total_weight + current_weight <= max_capacity){
            total_weight += heap.ExtractMax();
            if(current_weight != 1) buf.Add(current_weight / 2);
        } else{
            while(buf.Count() > 0) heap.Add(buf.ExtractMax());
            total_weight = 0;
            steps++;
        }
        if(heap.Count() == 0 && buf.Count() == 0){
            steps++;
            break;
        }
    }

    std::cout << steps << std::endl; // Вывод количества подходов

    return 0;
}