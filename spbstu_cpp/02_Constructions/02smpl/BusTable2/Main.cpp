#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

const int minInHour = 60; // минут в часе

void printTime(int time)
{
	cout<<setw(2)<<time/minInHour<<":";
	cout<<setw(2)<<time%minInHour;
}

int main(void)
{
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
		printTime(currTime);
		cout<<"->";
		currTime += inWayTime;
		printTime(currTime);
		cout<<"   ";
		currTime += restTime;
		printTime(currTime);
		cout<<"->";
		currTime += inWayTime;
		printTime(currTime);
		cout<<endl;
		currTime += restTime;
	}
	return 0;
}
	