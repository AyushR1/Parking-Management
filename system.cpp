#include"parking.h"

void System::enterParking(Car& car, int currentTime)
{
    extern QString msg;
    string id = car.getNumber();
    if (par.findCar(id, false))
        msg+=("Error: car" + QString::fromStdString(id) + "Already in the parking lot!");
    else if (pas.findCar(id, false))
        msg+=("Error: car" + QString::fromStdString(id) + "Already in the parking lot!");
    else if (par.isFull())
    {
        pas.enterWay(&car);
        msg+=("Full" + QString::fromStdString(car.getNumber())
              + "Entererd sidewalk and waiting");
    }
    else
        par.enterPar(car, currentTime);
}

void System::leaveParking(Car& car, int currentTime)
{
    extern QString msg;
    string id = car.getNumber();
    if (!par.findCar(id, false) && !pas.findCar(id, false))
        msg+=("Error: car" + QString::fromStdString(id) + "Not in the parking lot");
    else if (pas.findCar(id, false))
        msg+=("Error: car" + QString::fromStdString(id) + "Not in the parking lot");
    else
    {
        bool flag = par.isFull();
        par.remove(car.getPlace());
        car.leave(currentTime);
        earnings += car.lastFee();
        if (flag && pas.countCar())
            passToPark(currentTime);
        extern QLabel* l4;
        l4->setText(QString::number(earnings));
    }
}

void System::enterPassageway(Car& car)
{
    pas.enterWay(&car);
}

void System::passToPark(int currentTime)
{
    Car* car = pas.getFront();
    pas.leaveWay();
    par.enterPar(*car, currentTime);
}
