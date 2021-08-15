#include"parking.h"

Car::Car()
{
	id = "";
	parkingPlace = -1;
}

Car::Car(const string& ID)
{
	id = ID;
	parkingPlace = -1;
}

void Car::enter(int place, int currentTime)
{
    extern QString msg;
    enterTime.push_back(currentTime);
    if (currentTime>23){
        msg+=("Time greater than 23 taking it as 23  only \n");
    currentTime=23;}
    parkingPlace = place;
    msg+=("Car " + QString::fromStdString(id) + " Entered at "
          + QString::number(currentTime) + " hours in Parking space " +
          QString::number(place) + "。");
}

void Car::leave(int currentTime)
{
    extern QString msg;
    int i = enterTime.size();
	leaveTime.push_back(currentTime);
	parkedPlace.push_back(parkingPlace);
	costMoney.push_back(cost(enterTime[i - 1], leaveTime[i - 1]));
    msg+=("Car " + QString::fromStdString(id) + " left at "
          + QString::number(currentTime) +
          " From Parking space " + QString::number(parkingPlace) + "，");
    msg+=("\nCost :- " + QString::number(cost(enterTime[i - 1], leaveTime[i - 1]))+"₹\n");
	parkingPlace = -1;
}

double Car::cost(int start, int end) const
{
    int delta = end - start;
	double s;
    if (delta <= 0)
        s = 10;
	else
        s = delta * 10;
	return s;
}

void Car::reset()
{
	id = "";
	enterTime.clear();
	leaveTime.clear();
	parkedPlace.clear();
	costMoney.clear();
	parkingPlace = -1;
}
