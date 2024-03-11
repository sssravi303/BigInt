#include <iostream>
#include <fstream>
#include "proj1.h"
#include <string>
using namespace std;
int main()
{
  cout << endl;
  cout << "Using Double Parameterised constructor" << endl;
  Date2023 d(2, 3);
  d.print(100);
  cout << "Using Parameterised constructor" << endl;
  Date2023 d1;
  d1.print(10);
  cout << "Using Singly Parameterised constructor" << endl;
  Date2023 d2;
  d2.print(120);
  cout << "Using Input File and setDate function" << endl;
  string s;
  ifstream in;
  int i = 0, j = 0;
  string dat, m, y;
  int da, mo, yr;
  Date2023 d10[10];
  int mt = 0;
  in.open("input.txt");
  while (getline(in, s))
  {
    i = 0;
    dat = "";
    m = "";
    y = "";
    int n = s.length();
    while (s[i] != ' ')
    {
      m = m + s[i];
      i++;
    }
    i++;
    mo = stoi(m);

    while (s[i] != ' ')
    {
      dat = dat + s[i];
      i++;
    }
    i++;
    da = stoi(dat);
    while (s[i] != '\0')
    {
      y = y + s[i];
      i++;
    }
    yr = stoi(y);
    d10[mt].setDate(mo, da);
    d10[mt].print(yr);
    mt++;
  }
  return 0;
}