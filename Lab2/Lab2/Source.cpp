﻿/*
Шалыгина Виктория Алексеевна Лабораторная работа №2. Вариант №4 Задание: Написать программу, которая вычисляет сумму всех положительных элементов
массива. Массив и его длина вводятся пользователем.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int readValue() {
	int x;
	int check = 0;
	while (check == 0) {
		while (getchar() != '\n');
		check = scanf("%d", &x);
		if (check == 0) {
			printf("Ошибка, элементом массива должен быть целым числом, вы сломали программу \n");
		}
	}
	return x;
}

int summ(int x) {
	if (x > 0) {
		return x;
	}
	else {
		return 0;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите длину массива   ");
	int length;
	scanf("%d", &length);
	int a[100];
	int SumOfPositiveElements = 0;
	for (int i = 0; i < length; i++) {
		printf("Введите элемент массива");
		a[i] = readValue();
		
		SumOfPositiveElements += summ(a[i]);
	}
	printf("Сумма положительных элементов массива %d", SumOfPositiveElements);
	_getch();
	return 0;
}

int kaka() {
	int r=0 ;
	while (r >= 10) {
		r++;
		printf("%d", r);
	}
	
	for (r=0 ; r < 10; r++){ 
		printf("%d", r); 
	}

	do {
		printf("%d", r);
		r++;
	} while (r < 10);
	return 0;
}