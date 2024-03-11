#include <iostream>
#include<string>
#include<fstream>
class Date2023
{
private:
    int m;
    int d;
    int next;
    int m1;
    int d1;
public:
    Date2023(); // constructor;
    Date2023(int dd);// parameterised constructor
    Date2023(int dd, int mm);//parameterised constructor

    void setDate(int dd, int mm);
    void print(int days);
    void plusDay(int d);
};
