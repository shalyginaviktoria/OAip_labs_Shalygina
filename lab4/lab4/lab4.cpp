/*
�������� �������� ���������� ������������ ������ �4. ������� �4 �������: �������� ���������, ������� �� �������� � ����� ������ ������� �����,
���������� ���� �� � ������� ����� �����������, � ������� �� � ������ ����.
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
	//	printf("���������� �������� � ����� ����� :%d \n", y);
	return y;
}
int amountM(char *x, int n) {
	int AmountLetterM = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == '�' || x[i] == '�') {
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
		printf("� ����� ��� ������ ");
		_getch();
		return 0;
	}
	fscanf(Inp, "%d", &TextLength);
	for (int i = 0; i < TextLength ; i++) {
		fread(words[i].data, sizeof(char), TextLength, Inp);
		words[i].size = sizeSTR(words[i].data);
		words[i].countLetterM = amountM(words[i].data, words[i].size);
		//printf("����������� ���� � :%d   \n  ", words[i].countLetterM);
	}

	int maxCountM = 0;
	for (int i = 0; i < TextLength; i++) {
		if (words[i].countLetterM > maxCountM) {
			maxCountM = words[i].countLetterM;
		}
	}
	FILE *Out = fopen("output.txt", "w");
	//fprintf(Out, "%s", maxCountM);
		//printf("������������ ���������� ���� � :%d  \n", maxCountM);
	//fwrite(amountOut, sizeof(char), TextLength, Out);
	
	if (maxCountM != 0) {
		for (int i = 0; i < TextLength; i++) {
			if (words[i].countLetterM == maxCountM) {
				fprintf(Out, "%s", words[i].data);
				//printf("����� � ������������ ����������� ���� � :%s \n", words[i].data);
			}
		}
	}

	else {
		printf("���� � ������ � ���    \n  ");
	}
	fclose(Inp); 
	fclose(Out);
	_getch();
	return 0;
}