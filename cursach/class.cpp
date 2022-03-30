#include "class.h"

Class::Class()
{
    numberAuditory = "";
    numberClass = 0;
    Group group;
    nameItem = "";
    nameTeacher = "";
    typeClass = "";
    weekOne = 0;
    weekTwo = 0;
    weekThree = 0;
    weekFour = 0;
    subGroupFirst = 0;
    subGroupSecond = 0;
    monday = 0;
    tuesday = 0;
    wednesday = 0;
    thursday = 0;
    friday = 0;
    saturday = 0;
}

int Class::getNumberClass()
{
    return numberClass;
}

QString Class::getNumberAuditory()
{
    return numberAuditory;
}

QString Class::getNameItem()
{
    return nameItem;
}

QString Class::getNameTeacher()
{
    return nameTeacher;
}

QString Class::getTypeClass()
{
    return typeClass;
}

QString Class::getNumberGroup()
{
    return numberGroup;
}

int Class::getSubGroupFirst()
{
    return subGroupFirst;
}

int Class::getSubGroupSecond()
{
    return subGroupSecond;
}

int Class::getWeekOne()
{
    return weekOne;
}

int Class::getWeekTwo()
{
    return weekTwo;
}

int Class::getWeekThree()
{
    return weekThree;
}

int Class::getWeekFour()
{
    return weekFour;
}

int Class::getMonday()
{
    return monday;
}

int Class::getTuesday()
{
    return tuesday;
}

int Class::getWednesday()
{
    return wednesday;
}

int Class::getThursday()
{
    return thursday;
}

int Class::getFriday()
{
    return friday;
}

int Class::getSaturday()
{
    return saturday;
}

void Class::setNumberAuditory(QString auditory)
{
    numberAuditory = auditory;
}

void Class::setNumberClass(int classNum)
{
    numberClass = classNum;
}

void Class::setNumberGroup(QString group)
{
    numberGroup = group;
}

void Class::setNameItem(QString item)
{
    nameItem = item;
}

void Class::setNameTeacher(QString teacher)
{
    nameTeacher = teacher;
}

void Class::setTypeClass(QString classType)
{
    typeClass = classType;
}

void Class::setSubGroupFirst(int first)
{
    subGroupFirst = first;
}

void Class::setSubGroupSecond(int second)
{
    subGroupSecond = second;
}

void Class::setWeekOne(int one)
{
    weekOne = one;
}

void Class::setWeekTwo(int two)
{
    weekTwo = two;
}

void Class::setWeekThree(int three)
{
    weekThree = three;
}

void Class::setWeekFour(int four)
{
    weekFour = four;
}

void Class::setMonday(int mon)
{
    monday = mon;
}

void Class::setTuesday(int tue)
{
    tuesday = tue;
}

void Class::setWednesday(int wed)
{
    wednesday = wed;
}

void Class::setThursday(int thu)
{
    thursday = thu;
}

void Class::setFriday(int fri)
{
    friday = fri;
}

void Class::setSaturday(int sat)
{
    saturday = sat;
}

Class& Class::operator=(const Class &obj)
{
    numberClass = obj.numberClass;
    numberGroup = obj.numberGroup;
    numberAuditory = obj.numberAuditory;
    nameItem = obj.nameItem;
    nameTeacher = obj.nameTeacher;
    typeClass = obj.typeClass;
    weekOne = obj.weekOne;
    weekTwo = obj.weekTwo;
    weekThree = obj.weekThree;
    weekFour = obj.weekFour;
    subGroupFirst = obj.subGroupFirst;
    subGroupSecond = obj.subGroupSecond;
    monday = obj.monday;
    tuesday = obj.tuesday;
    wednesday = obj.wednesday;
    thursday = obj.thursday;
    friday = obj.friday;
    saturday = obj.saturday;
    return *this;
}

bool operator== (Class& temp1, Class& temp2)
{
    return temp1.numberClass == temp2.numberClass && temp1.weekOne == temp2.weekOne && temp1.weekTwo == temp2.weekTwo &&
            temp1.weekThree == temp2.weekThree && temp1.weekFour == temp2.weekFour && temp1.subGroupFirst == temp2.subGroupFirst &&
            temp1.subGroupSecond == temp2.subGroupSecond && temp1.nameItem == temp2.nameItem && temp1.nameTeacher == temp2.nameTeacher &&
            temp1.numberAuditory == temp2.numberAuditory && temp1.numberGroup == temp2.numberGroup && temp1.typeClass == temp2.typeClass &&
            temp1.monday == temp2.monday && temp1.tuesday == temp2.tuesday && temp1.wednesday == temp2.wednesday && temp1.thursday == temp2.thursday &&
            temp1.friday == temp2.friday && temp1.saturday == temp2.saturday;
}

int Class::getId()
{
    return id;
}

void Class::setId(int ID)
{
    id = ID;
}
