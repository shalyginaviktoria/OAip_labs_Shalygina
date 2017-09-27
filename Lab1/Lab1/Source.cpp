#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	
	float a;
	printf("Enter the speed in the node ", &a);
	a = scanf("%f", &a);
	float b = a*1.852;
	
	
	if (a == 0) {
		printf("Error: 'a' must be integer");
	}
	else {

		

		printf("Speed in h / h %9.2f  \n", b);
		float c = (b * 1000) / 3600;
		printf("Speed in m / s %9.2f  \n", c);
	}


	system("Pause");

}

