/*
Шалыгина Виктория Алексеевна
Лабораторная работа №2.
Вариант №4
Задание: Написать программу, которая вычисляет сумму всех положительных элементов
массива. Массив и его длина вводятся пользователем.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите длину массива  ");
	int array_length;
	scanf("%d", &array_length);
	int a[100];
	
	int sum_of_positive_elements=0 ;
	for (int i = 0; i < array_length; i++) {
		printf("Введите элемент массива");
		scanf("%d", &a[i]);
		if (a[i] > 0) {
			sum_of_positive_elements += a[i];
		}
		//printf(" %d ", a[i]);
	}
	printf("Сумма положительных элементов массива %d", sum_of_positive_elements);
	_getch();
	return 0;

}
