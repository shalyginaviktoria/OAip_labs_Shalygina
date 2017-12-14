/*
Шалыгина Виктория Алексеевна Лабораторная работа №5. Вариант №4 Задание: Написать программу, которая записывает с клавиатуры в файл структуру
согласно выданному варианту задания. В качестве разделителя полей структуры
использовать символ табуляции. «Футбольная команда»: название, город, количество сыгранных игр, количество
очков (проигрыши, выигрыши, ничьи), количество игроков, фамилия тренера.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
struct point {
	int NumberOfWins;
	int NumberOfLosses;
	int NumberOfDraws;
};
struct Footbool {
	char name[255];
	char city[255];
	int NumberOfGamesPlayed;
		struct point {
		int NumberOfWins;
		int NumberOfLosses;
		int NumberOfDraws;
	};
	int amountPlayers;
	char SurnameOftheTrainer[255];
	int points;
};
	int sizeSTR(char *x) {
		int y = strlen(x);
		return y;
	}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Footbool team[100];
	point points[100];
	int amountTeam;
	printf("Введите сколько будет команд ");
	scanf("%d", &amountTeam);
	printf("Введите даные о командах\n");
	for (int i = 1; i <= amountTeam; i++)
	{
		printf("Ведите название команды: ");
		scanf("%s", &team[i].name);
		printf("Ведите город команды: ");
		scanf("%s", &team[i].city);
		printf("Ведите количесство сыграных игр: ");
		scanf("%d", &team[i].NumberOfGamesPlayed);
		printf("Ведите количесство выйгрышей: ");
		scanf("%d", &points[i].NumberOfWins);
		printf("Ведите количесство пройгрышей: ");
		scanf("%d", &points[i].NumberOfLosses);
		printf("Ведите количесство ничьих: ");
		scanf("%d", &points[i].NumberOfDraws);
		printf("Ведите количесство игроков: ");
		scanf("%d", &team[i].amountPlayers);
		printf("Ведите фамилию тренера: ");
		scanf("%s", &team[i].SurnameOftheTrainer);
		printf("Система подсчета отчков: 2(ввыйгрыши)-пройгрыши+ниьчи  (выйгрш 2 очка, пройгрыш -1, ничья 1)  \n");
		team[i].points = 2 * points[i].NumberOfWins - points[i].NumberOfLosses + points[i].NumberOfDraws;
		printf("Количество очков:%d \n", team[i].points);
	}
	FILE *f = fopen("tablOut.txt", "w");
	int numderOfOut;
	printf("Введите по какому признаку сортировать команды:\n");
	printf("1-названия(от самого длинного до самого короткого), 2-количество игроков, 3-количетво очков, 4-город(аналогично названию)->");
	scanf("%d", &numderOfOut);
	switch (numderOfOut) // начало оператора switch
	{
	case 1: //сортировка по названию от длинного до короткого
	{
		int lenght[1000];
		int maxLenght = 0;
		for (int i = 1; i <= amountTeam; i++)
		{
			lenght[i] = sizeSTR(team[i].name);
			if (lenght[i] > maxLenght)
			{
				maxLenght = lenght[i];
			}
		}
		for (int i = 0; i < amountTeam; i++)
		{
			fprintf(f, "Название команды %s\n", team[i].name);
			fprintf(f, "Город команды %s\n", team[i].city);
			fprintf(f, "Количество сыграных игр команды %d\n", team[i].NumberOfGamesPlayed);
			fprintf(f, "Количество очков команды %d\n", team[i].points);
			fprintf(f, "Количество игроков команды %d\n", team[i].amountPlayers);
			fprintf(f, "Фамилия тренера команды %s\n", team[i].SurnameOftheTrainer);
			fprintf(f, "_________________________________________________ \n");
		}
		break;
	}
	case 2: //сортировка по количеству игроков 
	{
		for (int i = 0; i < amountTeam; i++) // пузырьком по колличеству очков сортируем       
		{
			int c = 0;
			for (int j = amountTeam - 1; j >= i; j--) // кол-во элементов
				if (team[j].amountPlayers < team[j + 1].amountPlayers)
				{
					c = team[j].amountPlayers;
					team[j].amountPlayers = team[j + 1].amountPlayers;
					team[j + 1].amountPlayers = c;
				}
		}
		for (int i = 0; i < amountTeam; i++)
		{
			fprintf(f, "Название команды %s\n", team[i].name);
			fprintf(f, "Город команды %s\n", team[i].city);
			fprintf(f, "Количество сыграных игр команды %d\n", team[i].NumberOfGamesPlayed);
			fprintf(f, "Количество очков команды %d\n", team[i].points);
			fprintf(f, "Количество игроков команды %d\n", team[i].amountPlayers);
			fprintf(f, "Фамилия тренера команды %s\n", team[i].SurnameOftheTrainer);
			fprintf(f, "_________________________________________________ \n");

		}
		break;
	}
	case 3: //сортировка по количеству очков 
	{
		for (int i = 0; i < amountTeam; i++)       
		{
			int c = 0;
			for (int j = amountTeam - 1; j >= i; j--)
				if (team[j].points < team[j + 1].points)
				{
					c = team[j].points;
					team[j].points = team[j + 1].points;
					team[j + 1].points = c;
				}
		}
		for (int i = 0; i < amountTeam; i++)
		{
			fprintf(f, "Название команды %s\n", team[i].name);
			fprintf(f, "Город команды %s\n", team[i].city);
			fprintf(f, "Количество сыграных игр команды %d\n", team[i].NumberOfGamesPlayed);
			fprintf(f, "Количество очков команды %d\n", team[i].points);
			fprintf(f, "Количество игроков команды %d\n", team[i].amountPlayers);
			fprintf(f, "Фамилия тренера команды %s\n", team[i].SurnameOftheTrainer);
			fprintf(f, "_________________________________________________ \n");
		}
			break;
		}
	case 4: //сортировка по городу от длинного до короткого
	{
		for (int i = 0; i < amountTeam; i++)
		{
			fprintf(f, "Название команды %s\n", team[i].name);
			fprintf(f, "Город команды %s\n", team[i].city);
			fprintf(f, "Количество сыграных игр команды %d\n", team[i].NumberOfGamesPlayed);
			fprintf(f, "Количество очков команды %d\n", team[i].points);
			fprintf(f, "Количество игроков команды %d\n", team[i].amountPlayers);
			fprintf(f, "Фамилия тренера команды %s\n", team[i].SurnameOftheTrainer);
			fprintf(f, "_________________________________________________ \n");

		}
		break;
	}
	default: {
		for (int i = 0; i < amountTeam; i++)
		{
			fprintf(f, "Название команды %s\n", team[i].name);
			fprintf(f, "Город команды %s\n", team[i].city);
			fprintf(f, "Количество сыграных игр команды %d\n", team[i].NumberOfGamesPlayed);
			fprintf(f, "Количество очков команды %d\n", team[i].points);
			fprintf(f, "Количество игроков команды %d\n", team[i].amountPlayers);
			fprintf(f, "Фамилия тренера команды %s\n", team[i].SurnameOftheTrainer);
			fprintf(f, "_________________________________________________ \n");
		}
	}
	}
	 fclose(f);
	//_getch();
	return 0;
}