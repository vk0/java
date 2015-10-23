#include <iostream>
#include <locale.h>
using namespace std;
// ‘ормирование названи€ оценки
// по ее численному значению:
// 5 - отлично, 4 - хорошо,
// 3 - удовлетворительно,
// 2 - неудовлетворительно
int main(void)
{
   setlocale(LC_ALL, "Russian");
   int mark; // оценка
   cout<<"¬ведите оценку: ";
   cin>>mark;
   switch(mark)
   {
      case 5: 
         cout<<"ќценка отлично"<<endl;
         break;
      case 4:
         cout<<"ќценка хорошо"<<endl;
         break;
      case 3:
         cout<<"ќценка удовлетворительно"<<endl;
         break;
      case 2:
         cout<<"ќценка неудовлетворительно"<<endl;
         break;
      default:
         cout<<"ќценки "<<mark<<" не бывает"<<endl;
   }
   return 0;
}
