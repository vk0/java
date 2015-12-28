// Вам дан словарь, состоящий из пар слов. Каждое слово является синонимом к парному ему слову. Все слова в словаре различны. Для одного данного слова определите его синоним.

// Входные данные

// Программа получает на вход количество пар синонимов N. Далее следует N строк, каждая строка содержит ровно два слова-синонима. После этого следует одно слово.

// Выходные данные

// Программа должна вывести синоним к данному слову.

// Sample Input:

// 3
// Hello Hi
// Bye Goodbye
// List Array
// Goodbye

// Sample Output:

// Bye

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
        map <string, string> words;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            string t1, t2;
            cin >> t1 >> t2;
            words[t1] = t2;
            words[t2] = t1;
        }
        string word;
        cin >> word;
        cout << words[word];
}