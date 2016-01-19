// Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией. Хранимые строки непустые и состоят из строчных латинских букв. Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте в случае, когда коэффициент заполнения таблицы достигает 3/4.

// Структура данных должна поддерживать операции добавления строки в множество, удаления строки из множества и проверки принадлежности данной строки множеству.

// Для разрешения коллизий используйте квадратичное пробирование. i-ая проба
// g(k, i)=g(k, i-1) + i (mod m). m - степень двойки.

// Каждая строка входных данных задает одну операцию над множеством. Запись операции состоит из типа операции и следующей за ним через пробел строки, над которой проводится операция.

// Тип операции  – один из трех символов:
//    +  означает добавление данной строки в множество;
//    -  означает удаление  строки из множества;
//    ?  означает проверку принадлежности данной строки множеству.
// При добавлении элемента в множество НЕ ГАРАНТИРУЕТСЯ, что он отсутствует в этом множестве. При удалении элемента из множества НЕ ГАРАНТИРУЕТСЯ, что он присутствует в этом множестве.

// Программа должна вывести для каждой операции одну из двух строк OK или FAIL, в зависимости от того, встречается ли данное слово в нашем множестве.

// Sample Input:

// + hello
// + bye
// ? bye
// + bye
// - bye
// ? bye
// ? hello

// Sample Output:

// OK
// OK
// OK
// FAIL
// OK
// FAIL
// OK

#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int InitialHashTableSize = 30;
const int HashParameter = 28;

template<class T> int Hash(const T &data, int m, int probe);

template<> int Hash(const string &data, int m, int probe) {
    int hash = 0;

    for (size_t i = 0; i < data.length(); ++i) {
        hash = (hash * HashParameter + data[i]) % m;
    }

    int c1 = 1;
    int c2 = 1;

    return (hash + c1 * probe + c2 * probe * probe) % m;
}

template<class T> struct CHashTableNode {
    T Data;
    bool isDeleted;
    CHashTableNode(const T &data) : Data(data), isDeleted(false) { }
};

template<class T> class CHashTable {
public:
    CHashTable() {
        table.assign(InitialHashTableSize, NULL);
        count = 0;
    }

    bool Has(const T &key) const {
        for (size_t probe = 0; probe < table.size(); ++probe) {
            int hash = Hash<T>(key, table.size(), probe);

            if (table[hash] != NULL && table[hash]->Data == key && !table[hash]->isDeleted) return true;
            else if (table[hash] == NULL) break;
        }

        return false;
    }

    bool Add(const T &key) {
        int hash;
        int insert_place = -1;

        for (size_t probe = 0; probe < table.size(); ++probe) {
            hash = Hash<T>(key, table.size(), probe);

            if (table[hash] != NULL && table[hash]->Data == key && !table[hash]->isDeleted) {
                return false;
            } else if (table[hash] == NULL) {
                if (insert_place == -1) insert_place = hash;
                break;
            } else if (table[hash]->isDeleted) {
                if (insert_place == -1) insert_place = hash;
            }
        }

        if (insert_place == -1) {
            return false;
        }

        if (table[insert_place] != NULL) {
            delete table[insert_place];
        }

        table[insert_place] = new CHashTableNode<T>(key);
        ++count;

        if (count >= table.size() * 2 / 3) {
            Rehash();
        }

        return true;
    }

    bool Delete(const T &key) {
        int hash;

        for (size_t probe = 0; probe < table.size(); ++probe) {
            hash = Hash<T>(key, table.size(), probe);

            if (table[hash] != NULL && table[hash]->Data == key && !table[hash]->isDeleted) break;
            else if (table[hash] == NULL) return false;
        }


        if (table[hash] == NULL) {
            return false;
        }

        table[hash]->isDeleted = true;
        --count;

        return true;
    }

private:
    vector<CHashTableNode<T>*> table;
    size_t count;

    void Rehash() {
        vector<CHashTableNode<T>*> old_table = table;

        table.assign(table.size() * 2, NULL);
        count = 0;

        for (size_t i = 0; i < old_table.size(); ++i) {
            if (old_table[i] != NULL && !old_table[i]->isDeleted) {
                Add(old_table[i]->Data);
                delete old_table[i];
            }
        }
    }
};

int main() {
    CHashTable<string> strings;

    while (true) {
        if (cin.eof()) {
            break;
        }

        char command;
        string str;

        cin >> command;
        cin >> str;

        if (str.empty()) break;

        if (command == '+') {
            cout << (strings.Add(str) ? "OK" : "FAIL") << endl;
        } else if (command == '-') {
            cout << (strings.Delete(str) ? "OK" : "FAIL") << endl;
        } else if (command == '?') {
            cout << (strings.Has(str) ? "OK" : "FAIL") << endl;
        }
    }

    return 0;
}
