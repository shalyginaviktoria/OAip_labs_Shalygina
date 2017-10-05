#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>


using namespace std;
#define KilometersPerHour 1.852
#define МetersPerSecond 3.6

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float speed;
	printf("Введите скорость в узлах  ");

	int check;
	check = scanf("%f", &speed);
	if (check == 0) {
		printf("Ошибка: скорость должна быть вещественым числом");
	}
	else {
		float speedKM = speed * KilometersPerHour; 
		printf("Скорость в км / ч %9.2f  \n", speedKM);

		float speedMS = speedKM * МetersPerSecond;
		printf("Скорость в м / с %9.2f  \n", speedMS);
	     }
	_getch();
}

