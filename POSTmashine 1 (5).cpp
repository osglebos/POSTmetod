#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <time.h>

int *ConvertFromDecemaToUno(int first, int second, int third)
{
	int *arr = new int[first + second + third + 5];

	for (int i = 0; i < first + second + third + 5; i++)
		if ((i == first+1) || (i==first+1+second+2)) arr[i] = 0;
		else arr[i] = 1;
	return arr;
}

int ConvertFromCharToInt(char *arr, int len)
{
	int res = 0;
	for (int i = 0; arr[i] != 0; i++)
		res = res * 10 + arr[i] - '0';
	return res;
}

int SeparateQuastion(char comand[10], bool TrOrFl)
{
	int tr_cmd = 0, fl_cmd = 0;
	char *tmp = new char[10];
	int i = 1, start = 1;

	for (; i < 10; i++)
		if (comand[i] == ',')
		{
			tmp[i - start] = 0;
			break;
		}
		else tmp[i - start] = comand[i];

	tr_cmd = ConvertFromCharToInt(tmp, i - start + 1);
	start = ++i;

	for (; i < 10; i++)
		if (comand[i] == 0)
		{
			tmp[i - start] = 0;
			break;
		}
		else tmp[i - start] = comand[i];

	tmp[i - start] = 0;

	fl_cmd = ConvertFromCharToInt(tmp, i - start + 1);

	if (TrOrFl == true) return tr_cmd;
	else return fl_cmd;
}

int SeparateComand(char comand[10])
{
	int next_cmd = 0;
	char *tmp = new char[10];
	int i = 0;
	for (i = 1; i < 10; i++)
		if (comand[i] == 0)
		{
			tmp[i - 1] = 0;
			break;
		}
		else tmp[i - 1] = comand[i];

	tmp[i - 1] = 0;
	next_cmd = ConvertFromCharToInt(tmp, i);

	return next_cmd;
}

void PrintTape(int *arr, int len, int k)
{
	for (int i = 0; i < len; i++)
		printf("%3i", i);
	printf("\n");

	for (int i = 0; i < len; i++)
		printf("%3i", arr[i]);
	printf("\n");

	for (int i = 0; i < k; i++)
		printf("   ");
	printf("  ^\n");

}

void PostAddition(int *arr, int len)
{
	char comands[18][10] = { "C2", ">3", "C4", ">5", "?4,6", "M7", "<8", "?7,9", ">10", "C11", ">12", "C13", ">14", "?13,15", "M16", "<17", "?16,18", "O18"};
	bool quit = false;
	int comand = 0, k = 0;
	while(k < len && k >= 0)
	{
		char action = comands[comand][0];
		printf("\nTape : \n");
		PrintTape(arr, len, k);
		printf("Comanda : %i%s\n", comand + 1, comands[comand]);
		switch (action)
		{
		case'C':
			arr[k] = 0;
			comand = SeparateComand(comands[comand]) - 1;
			break;
		case'>':
			k++;
			comand = SeparateComand(comands[comand]) - 1;
			break;
		case'<':
			k--;
			comand = SeparateComand(comands[comand]) - 1;
			break;
		case'?':
			if (arr[k] == 1)
				comand = SeparateQuastion(comands[comand], true) - 1;
			else if (arr[k] == 0)
				comand = SeparateQuastion(comands[comand], false) - 1;
			break;
		case'M':
			arr[k] = 1;
			comand = SeparateComand(comands[comand]) - 1;
			break;
		case'O':
			quit = true;
			comand = SeparateComand(comands[comand]) - 1;
			break;
		}
		if (quit == true) break;
	}
}

int main(void)
{
	setlocale(LC_ALL, "Russian");

	int first = 0, second = 0, third = 0;
	printf("¬ведите первое слагаемое: ");
	scanf("%i", &first);
	printf("¬ведите второе слагаемое: ");
	scanf("%i", &second);
	printf("¬ведите третее слагаемое: ");
	scanf("%i", &third);

	PostAddition(ConvertFromDecemaToUno(first, second, third), first + second + 5 + third);
	system("pause");
	return 0;
}