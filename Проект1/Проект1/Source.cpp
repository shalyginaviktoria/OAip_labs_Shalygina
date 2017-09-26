#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	setlocale(0, "Russian");
	float b,c,a, D;
printf("¬ведите скорость в узлах \n");
scanf("%f", &a);
b = a*1.852;
int f;
f = scanf("%d", &a);
if (f == 0) {
	printf("Error: 'a' must be integer");
}
else {

	printf("D = %d", a);

	printf("—корость в км/ч %9.2f  \n", b);
	c = (b * 1000) / 3600;
	printf("—корость в м/c %9.2f  \n", c);
}

	
system("Pause");

}