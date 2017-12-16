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
	printf(" 1-количество игроков, 2-количетво очков, ->");
	scanf("%d", &numderOfOut);
	switch (numderOfOut) 
	{
	  case 1: //сортировка по количеству игроков 
	  {
		 for (int i = 1; i < amountTeam; i++) 
		 {  
			for (int j = amountTeam - 1; j >= i; j--) 
				if (team[j].amountPlayers < team[j + 1].amountPlayers)
				{
					Footbool buf;
					buf = team[j];
					team[j] = team[j + 1];
					team[j + 1] = buf;   
				}
		 }
		fprintf(f, "Вывод в сортировке по количеству игроков \n");
	    fprintf(f, "_________________________________________________ \n");
		for (int i = 1; i <= amountTeam; i++)
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
	  case 2: //сортировка по количеству очков 
	  {
		for (int i = 1; i < amountTeam; i++)       
		{
			for (int j = amountTeam - 1; j >= i; j--)
				if (team[j].points < team[j + 1].points)
				{
					Footbool buf;
					buf = team[j];
					team[j] = team[j + 1];
					team[j + 1] = buf;
				}
		}
		fprintf(f, "Вывод в сортировке по количеству очков \n");
		fprintf(f, "_________________________________________________ \n");
		for (int i = 1; i <= amountTeam; i++)
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
	
	  default: 
	  {
		 fprintf(f, "Вывод в исходной сортировке \n");
		 fprintf(f, "_________________________________________________ \n");
		 for (int i = 1; i <= amountTeam; i++)
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
	int numderOfSearch,searchSign;
	printf("Введите по какому признаку найти команду:\n");
	printf(" 1-количество игроков, 2-количетво очков ->");
	scanf("%d", &numderOfSearch);
	printf(" Сколько надо искать ->");
	scanf("%d", &searchSign);
	switch (numderOfSearch) 
	{
	  case 1: //поиск по количеству игроков 
	  {
		 fprintf(f, "Поиск выполнен по игрокам \n");
		 fprintf(f, "_________________________________________________ \n");
		 int test=0;
		 for (int i = 1; i <= amountTeam; i++)
		 {  
			if (team[i].amountPlayers == searchSign)
			{
				fprintf(f, "Название команды которую нужно найти %s\n", team[i].name);
				fprintf(f, "Количество игроков команды %d\n", team[i].amountPlayers);
				fprintf(f, "_________________________________________________ \n");
			}
			else 
			{
				test++;
			}
		  }  
		 if (test != 0 )
		 {
			 fprintf(f, "Нет удолетворяющих поиску критериев \n");
			 fprintf(f, "_________________________________________________ \n");
		 }
		  break;
	  }
	  case 2: //поиск по количеству очков 
	  {  
		 fprintf(f, "Поиск выполнен по очкам \n");
		 fprintf(f, "_________________________________________________ \n");
		 int test = 0;
		 for (int i = 1; i <= amountTeam; i++)
		 {  
			if (team[i].points == searchSign)
			{
				fprintf(f, "Название команды которую нужно найти %s\n", team[i].name);
				fprintf(f, "Количество игроков команды %d\n", team[i].points);
				fprintf(f, "_________________________________________________ \n");
			}
			else
			{
				test++;
			}
		 }
		 if (test != 0)
		 {
			 fprintf(f, "Нет удолетворяющих поиску критериев \n");
			 fprintf(f, "_________________________________________________ \n");
		 }
		 break;
	  }
	  default:
	  {  
		 fprintf(f, "Нет поиска по таким критериям \n");
	   	 fprintf(f, "_________________________________________________ \n");
		 break;
	  }
	}
	 fclose(f);
	return 0;
}