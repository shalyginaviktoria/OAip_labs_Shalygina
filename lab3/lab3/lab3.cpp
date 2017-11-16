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
	char data;
	int size;
	int countLetterM;
};
void sizeSTR(char x) {
	int strlen(char);
	printf("Количество символов в слове равно :%d ", strlen(x));
}
void amountM() {
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Word words[100];
	printf("Введите количество слов   ");
	//int amount;
	//scanf("%d", &amount);
	for (int i = 0; i < 100; i++) {
		printf("Введите слово");
		scanf("%s", words[i].data);
		words[i].size = sizeSTR();
		words[i].countLetterM = amountM();
	}

	int maxCountM = 0;
	for (int i = 0; i < 100 ; i++){
		if (words[i].countLetterM > maxCountM ){ 
			maxCountM = words[i].countLetterM;
		}
		else {

		}
	}	
	_getch();
	return 0;
}

//в цикле находим максимальное количество букв M и записываем в переменную maxCountM

//в цикле выводим words[i].data если words[i].countLetterM == maxCountM
