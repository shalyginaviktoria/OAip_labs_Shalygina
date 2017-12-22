/*
Шалыгина Виктория Алексеевна индивидуальное задание. Вариант №24 Задание: разработка программы, которая считывает настроечные
параметры и формирует отчет по имеющимся данным в файлах. Отчет
записывается в текстовый файл. Число записей в каждом из описанных выше
файлов произвольно.Найти клиентов, не пользовавшихся роумингом в течение последнего полугода, но отправлявших не менее 5 СМС в день
*/
#define CONST255 255
#define NUMBER_OF_CLIENTS 30
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
	char customerNumber[CONST255];
	int serviceCodes;
	char calculationOfServices[CONST255];
	DateOfUsesOfTheServiceDay dateOfUses;
	char dateOfUsesOfTheServiceHour[CONST255];	
};struct CustomerData{
	char customeSurname[CONST255];
	char customeFathername[CONST255];
	char customerName[CONST255];
	char customerNumber1[CONST255];
	char dateOfContract[CONST255];
	char endDateOfContract[CONST255];
	int amountOfDebt;
	int allowableCredit;
};
struct ServicesBase {
	char serviceName[CONST255];
		int serviceCodes1;
		char calculationOfServices1[CONST255];
	char serviceTariff[CONST255];
};
struct SmSUser {
	char smsUserName[CONST255];
	char smsUserNumber[CONST255];
};
void readFile1(FILE *f, ClientBase *d,DateOfUsesOfTheServiceDay *v) {
	fscanf(f, "%s, %d, %d.%d.%d %s, %s", d->customerNumber, d->serviceCodes, v->day, v->month, v->year, d->dateOfUsesOfTheServiceHour, d->calculationOfServices);
}
void readFile2(FILE *f, ServicesBase *d) {
	fscanf(f, "%s, %d, %s, %s", d->serviceName, d->serviceCodes1, d->serviceTariff, d->calculationOfServices1);
}
void readFile3(FILE *f, CustomerData *d) {
	fscanf(f, "%s &s &s, %s, %s, %s, %d, %d", d->customeSurname, d->customerName, d->customeFathername, d->customerNumber1, d->dateOfContract, d->endDateOfContract, d->amountOfDebt, d->allowableCredit);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ClientBase base[NUMBER_OF_CLIENTS];
	DateOfUsesOfTheServiceDay serviceDay[NUMBER_OF_CLIENTS];
	ServicesBase base2[NUMBER_OF_CLIENTS];
	CustomerData base3[NUMBER_OF_CLIENTS];
	FILE *f = fopen("input1.txt", "r");
	for (int i = 0; i < NUMBER_OF_CLIENTS; i++)
	{
		readFile1(f, &base[i], &serviceDay[i]);
	}
	fclose(f);
	FILE *fd = fopen("Param.txt", "r");
	for (int i = 0; i < NUMBER_OF_CLIENTS; i++)
	{
		readFile2(fd, &base2[i]);
	}
	fclose(fd);
	FILE *fdd = fopen("input3.txt", "r");
	for (int i = 0; i < NUMBER_OF_CLIENTS; i++)
	{
		readFile3(fdd, &base3[i]);
	}
//	for (int i = 0; i < 30; i++)
//	{
//		printf("%s, %d, %d.%d.%d %s, %s\n", base[i].customerNumber, base[i].serviceCodes, serviceDay[i].day, serviceDay[i].month, serviceDay[i].year, base[i].dateOfUsesOfTheServiceHour, base[i].calculationOfServices);
//	}
	fclose(fdd);
	ClientBase  dumbbell;
	DateOfUsesOfTheServiceDay dumbbell1;
	strcpy(dumbbell.customerNumber, "\0");// для обнуления. на случай вопроса что это?? это строка с единственным символом конца строки, а обнуляем чтоб они нам больше не выскакивали тк они нам больше не нужны
	dumbbell.serviceCodes = 0;
	strcpy(dumbbell.calculationOfServices, "\0");
	dumbbell1.day = 0;
	dumbbell1.month = 0;
	dumbbell1.year = 0;
	strcpy(dumbbell.dateOfUsesOfTheServiceHour, "\0");
	for (int i = 0; i < NUMBER_OF_CLIENTS; i++)
	{
		if (base[i].serviceCodes == 5 && serviceDay[i].year == 17 && serviceDay[i].month >= 6 )
		{
			base[i] = dumbbell;  // я не вижу смысла выносить 2 строчки в отдельную функцию мб потом и сделаю это но сначала долелаю полностью работу
			serviceDay[i] = dumbbell1;
		}
	}
	ClientBase smsUsers[30]; // а это уже база тех, кто юзал смс
	int count = 0, b = 0;
	for (int i = 0; i < 30; i++)
	{
		if (base[i].serviceCodes == 2 )
		{
			smsUsers[b] = base[i];
			count++;
			b++;
		}
	}
	SmSUser base4[NUMBER_OF_CLIENTS]; //моя попытка группировки только что то говорит мне что она неверная
	for (int i = 0; i < NUMBER_OF_CLIENTS; i++)
	{   int k = 0;
		for (int j = 0; j < i; j++)
		{
			if(smsUsers[i].customerNumber== smsUsers[j].customerNumber && smsUsers[i].customerNumber == base3[i].customerNumber1 || smsUsers[i].customerNumber == base3[j].customerNumber1)
			{ 
				k++;
			}
		}
		for (int j = i; j < NUMBER_OF_CLIENTS; j++)
		{
			if (smsUsers[i].customerNumber == smsUsers[j].customerNumber && smsUsers[i].customerNumber == base3[i].customerNumber1 || smsUsers[i].customerNumber == base3[j].customerNumber1)
			{
				k++;
			}
		}
		if (k!=0)
		{
			base4[i].smsUserNumber = smsUsers[i].customerNumber;
			base4[i].smsUserName = base3[i].customerName; // эта ошибка меня бееееессссиииит  ну ПАЧЕМУ ЕЕ ЖЕ ЕЩЕ НЕ ТРОГАЛИ И НЕ ПРИСВАИВАЛИ
		}
	}
	_getch();
	return 0;
}
/*
   2) не могу проверить группировку на верность, голова кругом
   3) Теерь проблема со считыванием :((((((

   */

   