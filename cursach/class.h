#ifndef CLASS_H
#define CLASS_H
#include <QString>
#include "group.h"

class Class
{
private:
    int numberClass;
    QString typeClass;
    QString nameItem;
    QString nameTeacher;
    QString numberAuditory;
    QString numberGroup;
    int subGroupFirst;
    int subGroupSecond;
    int weekOne;
    int weekTwo;
    int weekThree;
    int weekFour;
    int monday;
    int tuesday;
    int wednesday;
    int thursday;
    int friday;
    int saturday;
    int id;
public:
    Class();
    int getNumberClass ();
    QString getTypeClass ();
    QString getNameItem ();
    QString getNameTeacher ();
    QString getNumberAuditory ();
    QString getNumberGroup ();
    int getSubGroupFirst ();
    int getSubGroupSecond ();
    int getWeekOne ();
    int getWeekTwo ();
    int getWeekThree ();
    int getWeekFour ();
    int getMonday ();
    int getTuesday ();
    int getWednesday();
    int getThursday ();
    int getFriday ();
    int getSaturday ();
    int getId ();
    void setNumberClass (int classNum);
    void setTypeClass (QString classType);
    void setNameItem (QString item);
    void setNameTeacher (QString teacher);
    void setNumberAuditory (QString auditory);
    void setNumberGroup (QString group);
    void setSubGroupFirst (int first);
    void setSubGroupSecond (int second);
    void setWeekOne (int one);
    void setWeekTwo (int two);
    void setWeekThree (int three);
    void setWeekFour (int four);
    void setMonday (int mon);
    void setTuesday (int tue);
    void setWednesday (int wed);
    void setThursday (int thu);
    void setFriday (int fri);
    void setSaturday (int sat);
    void setId (int ID);
    Class& operator= (const Class& obj);
    friend bool operator== (Class& temp1, Class& temp2);
};

#endif // CLASS_H
