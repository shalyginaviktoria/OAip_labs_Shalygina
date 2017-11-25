/*
Шалыгина Виктория Алексеевна Лабораторная работа №4. Вариант №4 Задание: Написать программу, которая во вводимом с файла тексте выберет слова,
количество букв «м» в которых будет максимально, и выведет их в другой файл.
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
int sizeSTR(char *x) {
	int y = strlen(x);
	//	printf("Количество символов в слове равно :%d \n", y);
	return y;
}
int amountM(char *x, int n) {
	int AmountLetterM = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'м' || x[i] == 'М') {
			AmountLetterM++;
		}
	}
	return AmountLetterM;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int TextLength = 0;
	Word words[10];
	FILE *Inp = fopen("input.txt" , "r");
	if (Inp == NULL) {
		printf("В файле нет данных ");
		_getch();
		return 0;
	}
	fscanf(Inp, "%d", &TextLength);
	for (int i = 0; i < TextLength ; i++) {
		fread(words[i].data, sizeof(char), TextLength, Inp);
		words[i].size = sizeSTR(words[i].data);
		words[i].countLetterM = amountM(words[i].data, words[i].size);
		//printf("Колличество букв М :%d   \n  ", words[i].countLetterM);
	}

	int maxCountM = 0;
	for (int i = 0; i < TextLength; i++) {
		if (words[i].countLetterM > maxCountM) {
			maxCountM = words[i].countLetterM;
		}
	}
	FILE *Out = fopen("output.txt", "w");
	//fprintf(Out, "%s", maxCountM);
		//printf("Максимальное количество букв М :%d  \n", maxCountM);
	//fwrite(amountOut, sizeof(char), TextLength, Out);
	
	if (maxCountM != 0) {
		for (int i = 0; i < TextLength; i++) {
			if (words[i].countLetterM == maxCountM) {
				fprintf(Out, "%s", words[i].data);
				//printf("Слово с максимальным количеством букв М :%s \n", words[i].data);
			}
		}
	}

	else {
		printf("Слов с буквой М нет    \n  ");
	}
	fclose(Inp); 
	fclose(Out);
	_getch();
	return 0;
}