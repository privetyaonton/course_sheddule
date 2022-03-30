#include "group.h"

Group::Group()
{
    numberGroup = "";
    yearOfAdmission = "";
    faculty = "";
    speciality = "";
}

QString Group::getNumberGroup()
{
    return numberGroup;
}

QString Group::getYearOfAdmission()
{
    return yearOfAdmission;
}

QString Group::getFaculty()
{
    return faculty;
}

QString Group::getSpeciality()
{
    return speciality;
}

void Group::setFaculty(QString fac)
{
    faculty = fac;
}

void Group::setNumberGroup(QString number)
{
    numberGroup = number;
}

void Group::setSpeciality(QString spec)
{
    speciality = spec;
}

void Group::setYearOfAdmission(QString year)
{
    yearOfAdmission = year;
}

Group& Group::operator=(const Group &group)
{
    numberGroup = group.numberGroup;
    faculty = group.faculty;
    speciality = group.speciality;
    yearOfAdmission = group.yearOfAdmission;
    return *this;
}
