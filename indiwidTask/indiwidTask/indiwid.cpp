/*
Шалыгина Виктория Алексеевна индивидуальное задание. Вариант №24 Задание: разработка программы, которая считывает настроечные
параметры и формирует отчет по имеющимся данным в файлах. Отчет
записывается в текстовый файл. Число записей в каждом из описанных выше
файлов произвольно.Найти клиентов, не пользовавшихся роумингом в течение последнего полугода, но отправлявших не менее 5 СМС в день
*/
#define CONST255 255
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
struct ClientBase {
	char customerName[CONST255];
	int serviceCodes;
	char calculationOfServices[CONST255];
	char dateOfUsesOfTheServiceDay[CONST255];
	char dateOfUsesOfTheServiceHour[CONST255];	
};
void readFile(FILE *f, ClientBase *d ) {
	fscanf(f, "%s, %d, %s %s, %s", d->customerName, d->serviceCodes, d->dateOfUsesOfTheServiceDay, d->dateOfUsesOfTheServiceHour, d->calculationOfServices);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ClientBase base[30];
	FILE *f = fopen("input1.txt", "r");
	for (int i = 0; i < 10; i++)
	{
		readFile(f, &base[i]);
	}
	fclose(f);
	FILE *f = fopen("input2.txt", "r");
	for (int i = 10; i < 20; i++)
	{
		readFile(f, &base[i]);
	}
	fclose(f);
	FILE *f = fopen("input3.txt", "r");
	for (int i = 20; i < 30; i++)
	{
		readFile(f, &base[i]);
	}
	fclose(f);
	ClientBase  dumbbell;
	strcpy(dumbbell.customerName, "\0");// для обнуления. на случай вопроса что это?? это строка с единственным символом конца строки
	dumbbell.serviceCodes = 0;
	strcpy(dumbbell.calculationOfServices, "\0");
	strcpy(dumbbell.dateOfUsesOfTheServiceDay, "\0");
	strcpy(dumbbell.dateOfUsesOfTheServiceHour, "\0");
	for (int i = 0; i < 30; i++) 
	{
		if (base[i].serviceCodes == 5)// не хватает условия времеи
		{
			base[i] = dumbbell;
		}
	}
	ClientBase smsUsers[30]; // а это уже база тех, кто юзал смс
	int count = 0, b = 1;
	for (int i = 0; i < 30; i++)
	{
		if (base[i].serviceCodes == 2)// не хватает условия времеи
		{
			smsUsers[b] = base[i];
			count++;
			b++;
		}
	}
}
/* 1) как добавить время, чтоб фильтровать точнее?
   2) как обьеденить имена в отдельного пользователя? можно конечно через иф это условияе прописать но я не хочу писать такое длинное состваное условие должно быть что то проще
   3)
   */

   