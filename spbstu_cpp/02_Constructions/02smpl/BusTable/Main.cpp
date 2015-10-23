#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;
int main(void)
{
	const int minInHour = 60; // минут в часе
	const int startTime = 7*minInHour; // время начала
	const int endTime = 19*minInHour; // время окончания
	int inWayTime, restTime; // время в пути, время отдыха
	setlocale(LC_ALL, "Russian");
	cout<<"Построение расписания движения автобусов"<<endl;
	cout<<"Введите время в пути от A до B в минутах: ";
	cin>>inWayTime;
	cout<<"Введите время отдыха на остановках в минутах: ";
	cin>>restTime;
	cout<<endl<<"Расписание движения"<<endl;
	cout<<"Пункт A        Пункт B"<<setfill('0')<<endl<<endl;
	int currTime = startTime;
	while (currTime + 2*inWayTime + restTime < endTime)
	{
		cout<<setw(2)<<currTime/minInHour<<":";
		cout<<setw(2)<<currTime%minInHour<<"->";
		currTime += inWayTime;
		cout<<setw(2)<<currTime/minInHour<<":";
		cout<<setw(2)<<currTime%minInHour<<"   ";
		currTime += restTime;
		cout<<setw(2)<<currTime/minInHour<<":";
		cout<<setw(2)<<currTime%minInHour<<"->";
		currTime += inWayTime;
		cout<<setw(2)<<currTime/minInHour<<":";
		cout<<setw(2)<<currTime%minInHour<<endl;
		currTime += restTime;
	}
	return 0;
}
	