#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
#define KMPH 1.852;
#define MPS 3.6;

int main()
{
	float a;
	printf("Enter the speed in the node ");
	scanf("%f", &a);
	float b = a * KMPH;
	if (a == 0) {
		printf("Error: speed must be float");
	}
	else {
		printf("Speed in km / h %9.2f  \n", b);
		float c = b * MPS;
		printf("Speed in m / s %9.2f  \n", c);
	};
	system("Pause");

}

