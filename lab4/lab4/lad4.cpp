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
	Word words[10];
	FILE *f = fopen("input.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(f, "%s", &words[i].data);
		words[i].size = sizeSTR(words[i].data);
		words[i].countLetterM = amountM(words[i].data, words[i].size);
	}

	int maxCountM = 0;
	for (int i = 0; i < 5; i++) {
		if (words[i].countLetterM > maxCountM) {
			maxCountM = words[i].countLetterM;
		}
	}
	fclose(f);
	f = fopen("output.txt", "w");
	fprintf(f, "Максимальное количество букв М: %d\n", maxCountM);
	if (maxCountM != 0)
	{
		for (int i = 0; i < 5; i++) {
			if (words[i].countLetterM == maxCountM) {
				fprintf(f, "Слово с максимальным количеством букв М: %s\n", words[i].data);
			}
		}
	}
	else
	{
		fprintf(f, "Слов с буквой М нет\n");
	}
	fclose(f);
	return 0;
}