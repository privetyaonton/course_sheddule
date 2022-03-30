#ifndef GROUP_H
#define GROUP_H
#include <QString>

class Group
{
private:
    QString numberGroup;
    QString yearOfAdmission;
    QString faculty;
    QString speciality;
public:
    Group();
    QString getNumberGroup();
    QString getYearOfAdmission();
    QString getFaculty();
    QString getSpeciality();
    void setNumberGroup(QString number);
    void setYearOfAdmission (QString year);
    void setFaculty (QString fac);
    void setSpeciality (QString spec);
    Group& operator= (const Group& group);
};

#endif // GROUP_H
