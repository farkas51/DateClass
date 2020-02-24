#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define kaif 30

using namespace std;

class Date {
public:
  Date();
  Date(int _d, int _m, int _y);
  Date(string s);
  string s1;
  string s4;

  friend ostream& operator<<(ostream& stream,const Date& c); //перегрузка вывода
  friend istream& operator>>(istream& stream, Date& c); //перегрузка ввода
  Date operator+(const Date& c);
  Date operator+(int d);
  Date operator-(int d);
  void operator==(const Date& c);
  Date& operator=(const Date& c);

  ~Date();
void outputtostring();//представление даты в виде строки (DD.MM:YYYY)

private:
  int Year;
  int Day;
  int Month;
};

Date::~Date() {
  Day = 0;
  Month = 0;
  Year = 0;
}
// перегрузка оператора вывода
ostream& operator<<(ostream& stream, const Date& c) {
  stream << c.Day << "." << c.Month << "." << c.Year << endl;
  return stream;
}
// перегрузка оператора ввода
istream& operator>>(istream& stream, Date& c) {
  stream >> c.Day >> c.Month >> c.Year;
  return stream;
}
// перегрузка оператора сложени€ времени с количеством суток
Date Date::operator+(const Date& c)
{
  Date res;
  res.Day = Day + c.Day;
  if (res.Day>30)
  {
    res.Day = res.Day-30;
    res.Month++;
  }
  res.Month = Month + c.Month;
  res.Year = Year + c.Year;
  if (res.Month> 12)
  {
    res.Month = res.Month-12;
    res.Year++;
  }
  return res;
}
Date Date::operator+(int k) {
  Date res;
  res.Day = this->Day;
  res.Month = this->Month;
  res.Year = this->Year;
  res.Day = res.Day + k;
  while (res.Day>30) {
    if (res.Day > 30) {
      res.Day = res.Day - 30;
      res.Month++;
      if (res.Month > 12) {
        res.Month = res.Month - 12;
        res.Year++;
      }

    }
  }
  return res;
}
//реализаци€ перегрузки оператора вычитани€
Date Date::operator-(int k) {
  Date res;
  res.Day = this->Day;
  res.Month = this->Month;
  res.Year = this->Year;
  res.Day = res.Day - k;
  while (res.Day <= 0) {
    if (res.Day <= 0) {
      res.Day = 30 + res.Day;
      res.Month--;
      if (res.Month <=0) {
        res.Month = 12-res.Month;
        res.Year--;
      }

    }
  }
  return res;
}
//реализаци€ перегрузки сравнени€ 
void Date::operator==(const Date& c) {
  Date res;
  res.Day = this->Day;
  res.Month = this->Month;
  res.Year = this->Year;
  if ((Day == c.Day) && (Month == c.Month) && (Year == c.Year)) {
    cout << ("ƒата 1 и 2 равны") << endl;
  }
  else if ((Day > c.Day) || (Month > c.Month) || (Year > c.Year)) {
    cout << ("ƒата 1 больше чем дата 2") << endl;
  }
  else if ((Day < c.Day) || (Month < c.Month) || (Year < c.Year)) {
    cout << ("ƒата 1 меньше чем дата 2") << endl;
  }
}
//реализаци€ перегрузки присваивани€
Date& Date::operator=(const Date& c) {
  (*this).Day = c.Day;
  Month = c.Month;
  Year = c.Year;
  return *this;
}

// реализаци€ конструкторов
Date::Date(int _d,int _m, int _y) : Day(_d), Month(_m),Year(_y) { }
Date::Date() {
  Day = 0;
  this->Month = 0;
  this->Year = 0;
}
Date::Date(string s) {
  string s1;
  string s2;
  string s3;
  s1.assign(s, 0, 2);
  int i = std::stoi(s1);
  s2.assign(s, 3, 5);
  int i2 = std::stoi(s2);
  Day = i;
  s3.assign(s, 6, 10);
  int i3 = std::stoi(s3);
  Month = i2;
  Year = i3;
}

//метод представлени€ даты в виде строки
void Date::outputtostring() {
  Date res;
  res.Day = this->Day;
  res.Month = this->Month;
  res.Year = this->Year;
  string s1 = std::to_string(Day);
  string s2 = ".";
  string s3 = s1 + s2;
  string s4 = std::to_string(Month);
  string s5 = ":";
  string s6 = s4 + s5;
  string s7 = s3 + s6;
  string s8 = std::to_string(Year);
  string s9 = s7 + s8;
  cout << s9 << endl;
}