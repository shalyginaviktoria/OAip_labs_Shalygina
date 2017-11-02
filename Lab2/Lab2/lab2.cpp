/*
Шалыгина Виктория Алексеевна Лабораторная работа №2. Вариант №4 Задание: Написать программу, которая вычисляет сумму всех положительных элементов
массива. Массив и его длина вводятся пользователем.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int readValue() {
	int check;
	check = scanf("%d", &a[i]);
	if (check == 0) {
		printf("Ошибка, элементом массива должен быть целым числом, вы сломали программу \n");
		a[i] = 0;
		_getch();
	return check;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите длину массива   ");
	int length;
	scanf("%d", &length);
	int a[100];
	int sum_of_positive_elements=0 ;
	for (int i = 0; i < length; i++) {
		printf("Введите элемент массива");
		readValue();	
		if (a[i] > 0 && check != 0){
			sum_of_positive_elements += a[i];
		}
	}
	printf("Сумма положительных элементов массива %d", sum_of_positive_elements);
	_getch();
	return 0;
}
