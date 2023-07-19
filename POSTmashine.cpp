// laba7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int array[12]{ 0,0,1,1,1,1,0,1,1,0 };
	int i = 3;

	for (size_t j = 0; j < 12; j++)
	{
		cout << array[j];
	}
	cout << endl;
	cout << "Каретка на начальной позиции: " << i << endl;

	for (size_t k = 1, j = 1; k < 5; k++, j++)
	{
		cout << j << " > " << j + 1;
		cout << " Каретка на позиции: " << ++i << endl;
	}
	cout << "5 V 6" << endl;
	array[i - 1] = 1;
	for (size_t j = 0; j < 12; j++)
	{
		cout << array[j];
	}
	cout << endl;

	for (size_t k = 0, j = 6; k < 2; k++, j++)
	{
		cout << j << " > " << j + 1;
		cout << " Каретка на позиции: " << ++i << endl;
	}
	cout << "8 C 9" << endl;
	array[i - 1] = 0;
	cout << "9 < 10";
	cout << " Каретка на позиции: " << --i << endl;
	cout << "10 C 11" << endl;
	array[i - 1] = 0;
	cout << "11 < 12";
	cout << " Каретка на позиции: " << --i << endl;

	for (size_t j = 0; j < 12; j++)
	{
		cout << array[j];
	}
	cout << endl << "12 . STOP" << endl;

	system("pause");
	return 0;
}

