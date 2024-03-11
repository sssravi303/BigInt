#include <iostream>
#include <fstream>
#include "proj1.h"
#include <string>
using namespace std;
Date2023::Date2023() // default constructor

{
  m = 1;
  d = 1;
}
Date2023::Date2023(int dd) // single constructor
{
  if (dd < 0 || dd > 365)
  {
    cout << "The entry of date and month is not legitemate";
    exit(0);
  }
  next = dd;
  int da[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  string dow[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  string mon[12] = {"January", "Febrauary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  for (int i = 1; i < 12; i++)
  {
    if (da[i] > next && next >= da[i - 1])
    {
      m = i;
    }
  }
  d = next - da[m - 1];
}
Date2023::Date2023(int mm, int dd) // two parametrised constructor

{
  m = mm;
  d = dd;
}
void Date2023::setDate(int month, int n) // function to set date
{
  m = month;
  d = n;
}
void Date2023::plusDay(int day) // adds the date and defines m and d again

{
  int dy;
  int next1 = 0;
  int da[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  string dow[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  string mon[12] = {"January", "Febrauary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  for (int i = 1; i <= 12; i++)
  {
    if (da[i] > next && next >= da[i - 1])
    {
      m = i;
      d = next - da[i - 1];
    }
  }
  cout << dow[(next - 1) % 7] << ", " << mon[m - 1] << " " << d << ",2023" << endl;
  next = 0;
  m = 1;
  d = 1;
}
void Date2023::print(int day)
{

  int c = 0;

  if (m > 12 || m <= 0)

  {

    c = 1;
  }

  else if (m == 4 || m == 6 || m == 9 || m == 11)

  {

    if (d == 31)

      c = 1;
  }

  else if (m == 2 && d > 28)

    c = 1;

  else if (d > 31 || d <= 0)

    c = 1;

  if (c == 1)

  {

    cout << "   The entry of date and month is not legitemate";

    exit(0);
  }

  int dy;
  int next1 = 0;
  int da[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  string dow[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  string mon[12] = {"January", "Febrauary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  next = da[m - 1] + d;
  if (m == 1)
  {
    cout << "   " << day << " days after " << dow[(next - 1) % 7] << ", " << mon[m - 1] << " " << d << ",2023 is ";
    next = next + day;
  }
  else if (m != 1)
  {
    cout << "   " << day << " days after " << dow[(next - 1) % 7] << ", " << mon[m - 1] << " " << d << ",2023 is ";
    next1 = day;
    next = next1 + d + da[m - 1];
  }
  if (next > 365)
  {
    cout << "a date not in 2023" << endl;
    return;
  }
  plusDay(day);
}