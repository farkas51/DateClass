#include <iostream>
#include <fstream>
#include <clocale>  
#include <string>
#include "DateClass.h"
using namespace std;

int main() {
  int k;
  string s = "12.15:2000";
  setlocale(LC_CTYPE, "Russian");
  Date d0(20, 8, 2000);
  Date d1; //����������� �� ���������
  Date d2(12, 5, 1990); //����������� �������������
  Date d3;
  Date d5(6, 6, 1950);
  Date d7(6, 6, 1951);
  Date d8;
  Date d9;
  Date d10;
  Date d11(s);
  cout << "������� ������� �����,������� �� ����� �������� � ������,������ DD.MM.YYYY" << endl;
  cout << "����� ����� �1" << endl;
  cout << d2 << endl;
  cout << "������� ����� �2 ������� ����� ������ ������� (����,�����,���)" << endl;
  cin >> d3;
  cout << d3 << endl;
  cout << "����� ����� �3 " << d2 << endl;
  cout << "������� ���������� ���� ���� ������� � ������ �3" << endl;
  cin >> k;
  Date d4;
  d4 = d2 + k; 
  cout << d4 << endl;
  cout << "����� ����� �4 " << d5 << endl;
  cout << "������� ���������� ���� ���� ������� �� ����� �4" << endl;
  cin >> k;
  Date d6 = d5 - k;
  cout << d6 << endl;
  cout << "������� ���� 1 ��� ��������� ����� Enter(����,�����,���)" << endl;
  cin >> d8;
  cout << "������� ���� 2 ��� ��������� ����� Enter(����,�����,���)" << endl;
  cin >> d9;
  cout << "���� 1 ��� ��������� " << d8 << "���� 2 ��� ��������� " << d9 << endl;
  d8 == d9;
  d9 = d7;
  cout << d9 << endl;
  cout << "������� ���� ������� ������ ����������� � ������� DD.MM:YYYY" << endl;
  cin >> d10;
  d10.outputtostring();
  cout << "���� ������������ �� ������ � �����" << endl;
  cout << d11 << endl;
  system ("pause");
  return 0;
}  