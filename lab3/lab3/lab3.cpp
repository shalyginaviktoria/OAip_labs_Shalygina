/*
Шалыгина Виктория Алексеевна Лабораторная работа №3. Вариант №4 Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова,
количество букв «м» в которых будет максимально, и выведет их на экран.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct Word {
	char data[255];
	int size;
	int countLetterM;
};
int sizeSTR(char *x){
	int y = strlen(x);
//	printf("Количествоп символов в слове равно :%d \n", y);
	return y;
}
int amountM(char *x, int n) {
	int AmountLetterM = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'м'|| x[i] =='М' ) {
			AmountLetterM ++;
		}
	}
	return AmountLetterM;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Word words[10];
	printf("Введите слова \n");
	for (int i = 0; i < 5; i++) {
		printf("Введите слово: ");
		scanf("%s", &words[i].data);
		words[i].size = sizeSTR(words[i].data);
		words[i].countLetterM = amountM(words[i].data, words[i].size);
		//printf("Колличество букв М :%d   \n  ", words[i].countLetterM);
	}

	int maxCountM = 0;
	for (int i = 0; i < 5 ; i++){
		if (words[i].countLetterM > maxCountM ){ 
			maxCountM = words[i].countLetterM;
		}	
	}	
	printf("Максимальное количество букв М :%d  \n", maxCountM);
	if (maxCountM != 0) {
		for (int i = 0; i < 5; i++) {
			if (words[i].countLetterM == maxCountM) {
				printf("Слово с максимальным количеством букв М :%s \n", words[i].data);
			}
		}
	}
	else {
		printf("Слов с буквой М нет    \n  ");
	}
	_getch();
	return 0;
}