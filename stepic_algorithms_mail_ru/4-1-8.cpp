// Дан фрагмент последовательности скобок, состоящей из символов (){}[].

// Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную последовательность.

// Если возможно - выведите минимальную корректную последовательность, иначе - напечатайте "IMPOSSIBLE".

// Максимальная длина строки 10^6 символов.

// Sample Input 1:

// }[[([{[]}

// Sample Output 1:

// {}[[([{[]}])]]


// Sample Input 2:

// {][[[[{}[]

// Sample Output 2:

// IMPOSSIBLE

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "assert.h"

const char sym[] = {'(', '[', '{', ')', ']', '}'};  //Массив возможных входных данных

//Класс Стек
class CStack
{
private:
    char* mas;
    int size;
    int last;       //Указатель на следующей после последнего
    void Grow();
public:
    CStack() { last = 0; size = 1; mas = (char*)malloc( size*sizeof(char) ); };
    void Push_Back(char);
    char Pop_Back();
    int Size() {return last; };
    ~CStack() { free(mas); };
};

//Увеличение размера массива
void CStack::Grow()
{
    size *= 2;
    mas = (char*)realloc(mas, size * sizeof(char) ) ;
    if ( mas == NULL ) printf("ups\n");
}

//Внесение элемент в стек
void CStack::Push_Back(char c)
{
    if ( last + 1 == size )
    {
        Grow();
    }
    assert( mas != NULL );
    mas[last++] = c;
}

//Получение последнего элемента из стека
char CStack::Pop_Back()
{
    assert( last > 0 );
    char temp = mas[--last];
    if ( last == size/2 - 1 )
    {
        size /= 2;
        mas = (char*)realloc(mas, size * sizeof(char) ) ;
    if ( mas == NULL ) printf("ups\n");
    }
    return temp;
}

//Получение данных
CStack* input()
{
    char c;
    CStack *temp = new (CStack);
    while( (c=getchar()) != '\n' )
    {
        temp->Push_Back(c);
    }
    return temp;
}

//Вывод стека
void output(CStack* Sequence)
{
    CStack* Temp = new CStack;
    while( Sequence->Size() != 0 )
        Temp->Push_Back(Sequence->Pop_Back());
    while( Temp->Size() != 0 )
        printf("%c",Temp->Pop_Back());
    putchar('\n');
}

//Зеркальное отображение элементов
CStack* ReverseIt(CStack* Sequence)
{
    CStack* Reverse = new CStack;
    char temp;
    int i;
    while ( Sequence->Size() != 0 )
    {
        temp = Sequence->Pop_Back();
        i = -1;
        while ( i < 5 && temp != sym[++i] );
        Reverse->Push_Back( sym[ ( i + 3 ) % 6 ] );
    }
    delete Sequence;
    return Reverse;
}

//Дополнение недостающими элементами по левому краю
CStack* MakeItFull(CStack *Sequence)
{
    CStack* ToAdd = new CStack;
    CStack* Reverse = new CStack;
    char temp;
    int i;

    while ( Sequence->Size() != 0 )
    {
        temp = Sequence->Pop_Back();
        Reverse->Push_Back(temp);

        i = -1;
        while ( i < 5 && temp != sym[++i] );
        if ( i < 3 )
        {
            if (ToAdd->Size() != 0)
            {
                if( ToAdd->Pop_Back() != temp )
                        return NULL;
            }
        }
        else
        {
            ToAdd->Push_Back(sym[i-3]);
        }
    }
    while ( ToAdd->Size() != 0 )
        Reverse->Push_Back(ToAdd->Pop_Back());
    while ( Reverse->Size() != 0 )
        Sequence->Push_Back(Reverse->Pop_Back());
    delete Reverse;
    delete ToAdd;
    return Sequence;
}

int main()
{
    CStack *Sequence = input();
    if ((Sequence = MakeItFull(Sequence)) == NULL)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    Sequence = ReverseIt(Sequence);
    Sequence = MakeItFull(Sequence);
    Sequence = ReverseIt(Sequence);
    output(Sequence);
    delete Sequence;
    return 0;
}