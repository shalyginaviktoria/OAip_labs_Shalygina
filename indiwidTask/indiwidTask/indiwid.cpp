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
struct DateOfUsesOfTheServiceDay
{
	int day;
	int month;
	int year;
};
struct ClientBase {
	char customerName[CONST255];
	int serviceCodes;
	char calculationOfServices[CONST255];
	struct DateOfUsesOfTheServiceDay
	{
		int day;
		int month;
		int year;
	};
	char dateOfUsesOfTheServiceHour[CONST255];	
};
void readFile(FILE *f, ClientBase *d,DateOfUsesOfTheServiceDay *v) {
	fscanf(f, "%s, %d, %d.%d.%d %s, %s", d->customerName, d->serviceCodes, v->day, v->month, v->year, d->dateOfUsesOfTheServiceHour, d->calculationOfServices);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ClientBase base[30];
	DateOfUsesOfTheServiceDay serviceDay[30];
	FILE *f = fopen("input1.txt", "r");
	for (int i = 0; i < 10; i++)
	{
		readFile(f, &base[i], &serviceDay[i]);
	}
	fclose(f);
	FILE *fd = fopen("input2.txt", "r");
	for (int i = 10; i < 20; i++)
	{
		readFile(fd, &base[i], &serviceDay[i]);
	}
	fclose(fd);
	FILE *fdd = fopen("input3.txt", "r");
	for (int i = 20; i < 30; i++)
	{
		readFile(fdd, &base[i],&serviceDay[i]);
	}
	for (int i = 0; i < 30; i++)
	{
		printf("%s, %d, %d.%d.%d %s, %s\n", base[i].customerName, base[i].serviceCodes, serviceDay[i].day, serviceDay[i].month, serviceDay[i].year, base[i].dateOfUsesOfTheServiceHour, base[i].calculationOfServices);
	}
	fclose(fdd);
	ClientBase  dumbbell;
	DateOfUsesOfTheServiceDay dumbbell1;
	strcpy(dumbbell.customerName, "\0");// для обнуления. на случай вопроса что это?? это строка с единственным символом конца строки
	dumbbell.serviceCodes = 0;
	strcpy(dumbbell.calculationOfServices, "\0");
	dumbbell1.day = 0;
	dumbbell1.month = 0;
	dumbbell1.year = 0;
	strcpy(dumbbell.dateOfUsesOfTheServiceHour, "\0");
	for (int i = 0; i < 30; i++) 
	{
		if (base[i].serviceCodes == 5 && serviceDay[i].year == 17 && serviceDay[i].month >= 6 )
		{
			base[i] = dumbbell;
			serviceDay[i] = dumbbell1;
		}
	}
	ClientBase smsUsers[30]; // а это уже база тех, кто юзал смс
	int count = 0, b = 0;
	for (int i = 0; i < 30; i++)
	{
		if (base[i].serviceCodes == 2)// не хватает условия времеи
		{
			smsUsers[b] = base[i];
			count++;
			b++;
		}
	}
	for (int i = 0; i < b; i++) 
	{


	}


	_getch();
	return 0;
}
/*
   2) как обьеденить имена в отдельного пользователя? можно конечно через иф это условияе прописать но я не хочу писать такое длинное состваное условие должно быть что то проще
   3) Теерь проблема со считыванием :((((((
   */

   