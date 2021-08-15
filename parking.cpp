#include<iostream>
#include<ctime>
#include"parking.h"
using std::cout;
using std::endl;

bool Parking::isFull() const
{
	if (occupiedPlaces == MAX_CAR)
		return true;
	return false;
}

void Parking::enterPar(Car& car, int currentTime)
{
	srand(time(0));
	int p = (int)(rand() % MAX_CAR + 1);
	while (parking[p].getPlace() != -1)
		p = (int)(rand() % MAX_CAR + 1);
	occupiedPlaces++;
	car.enter(p, currentTime);
	parking[p] = car;

    extern QLabel *l1,*l2;
    l1->setText(QString::number(occupiedPlaces));
    l2->setText(QString::number(MAX_CAR-occupiedPlaces));
}

void Parking::remove(int place)
{
	parking[place].reset();
	occupiedPlaces--;

    extern QLabel *l1,*l2;
    l1->setText(QString::number(occupiedPlaces));
    l2->setText(QString::number(MAX_CAR-occupiedPlaces));
}

bool Parking::findCar(const string& id, bool print) const
{
    extern QString state;
    for (int i = 1; i <= MAX_CAR; i++)
	{
		if (id == parking[i].getNumber())
		{
			int place = parking[i].getPlace();
			if (print)
                state=QString::number(place);
            return true;
		}
	}
	return false;
}
