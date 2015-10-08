// Напишите функцию поиска первого вхождения шаблона в текст. В качестве первого параметра функция принимает текст (C-style строка), в которой нужно искать шаблон. В качестве второго параметра строку-шаблон (C-style строка), которую нужно найти. Функция возвращает позицию первого вхождения строки-шаблона, если он присутствует в строке (помните, что в C++ принято считать с 0), и -1, если шаблона в тексте нет.
// Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.
// Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам нужны. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int strstr(const char *text, const char *pattern) {

    int estr=0,epattern=0,k=0;

    for (int i=0;i>=0;i++){
        if (text[i]=='\0'){
            estr=i;
            break;
        }
    }

    for (int i=0;i>=0;i++){
        if (pattern[i]=='\0'){
            epattern=i;
            break;
        }
    }
    if (epattern==0) return 0;

    if (epattern>estr) return -1;

    for (int i=0;i<(estr-epattern+1);i++){
        k=0;
        for (int j=0;j<(epattern);j++){
            if (text[i+j]==pattern[j]) k++;
            else break;
        }
        if (k==(epattern)) return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    const char s1[]="abcdefg";
    const char s2[]="fg";
    cout<<strstr2(s1, s2)<<endl;
    return 0;
}