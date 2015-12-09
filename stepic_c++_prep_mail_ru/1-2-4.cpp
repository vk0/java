// Одномерные массивы примеры

#include <stdio.h>

int main() {
    int a[] = {1,2,3}; // = int a[3] = {1,2,3};
    int b[5] = {1,2,3}; // = int b[5] = {1,2,3,0,0};
    int c[7] = {1,[5] = 10,20, [1] = 2}; // = int c[7] = {1,2,0,0,0,10,20};
}

// Нахождение максимальное элемента в массиве

int findmax(int *arr, int count) {
    int idx = 0;
    for (int i = 1; i<count;++i){
        if (arr[i]>arr[idx]){
            idx = i;
        }
        return idx;
    }
}

// Нахождение второго максимального элемента в массиве

int getmax2(const int *arr, int count){
    int prev_max=arr[0], curr_max = arr[1];
    if (arr[1]<arr[0]){
        curr_max = arr[0];
        prev_max = arr[1];
    }
    for (int i = 2; i<count;i++){
        if (arr[i]>=curr_max){
            prev_max = curr_max;
            curr_max = arr[i];
        }
        return prev_max;
    }
}

// Функция конкатенации строк

char *strcat(char *str1, const char *str2){
    char *cp = str1; // указатель на начало строки
    while(*cp) cp++;
    while(*cp++ = *str2++);
    return str1;
}

// Функция длины строк

int strlen(const char *str) {
    const char *eos = str; // указатель на начало строки
    while(*eos++); // доходим до конца строки
    return(int)(eos - str - 1); //длина = разница между указателями начала и конца строки - 1
}

// Функция сравнения строк

int strcmp(const char *str1, const char *str2){
    while(*str1==*str2 && *str1){ // сравнение в цикле 2х строк
        str1++;
        str2++;
    }
    return *str1-*str2; // вернем 0 и 1
}

// Функция копирования строк str2 => str1

char * strcpy(char * str1, const char * str2){
    char * d = str1; //начало первой строки
    while(*d++ = *str2++); //перемещаем указатель
    return str1;
}

// Функция нахождение подстроки в строке

int * substr(char* str, char* sub){
    int i,j;
    for(i=j=0;str[i]!='\0';i++){ // цикл по строке
        while((str[i+j]!='\0') && (sub[j]==str[i+j])) j++;
        if(sub[j]=='\0') return &str[i];
        j=0;
    }
    return NULL;
}

// Функция нахождение символа в строке

char *strchr(const char *str, int ch) {
    while(*str && *str != (char) ch) str++;
    if(*str == (char)ch) return (char *) str;
    return NULL;
}