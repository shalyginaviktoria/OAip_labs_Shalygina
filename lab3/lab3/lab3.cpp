/*
�������� �������� ���������� ������������ ������ �3. ������� �4 �������: �������� ���������, ������� �� �������� � ���������� ������ ������� �����,
���������� ���� �� � ������� ����� �����������, � ������� �� �� �����.
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
	printf("���������� �������� � ����� ����� :%d ", strlen(x));
}
void amountM() {
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Word words[100];
	printf("������� ���������� ����   ");
	//int amount;
	//scanf("%d", &amount);
	for (int i = 0; i < 100; i++) {
		printf("������� �����");
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

//� ����� ������� ������������ ���������� ���� M � ���������� � ���������� maxCountM

//� ����� ������� words[i].data ���� words[i].countLetterM == maxCountM
