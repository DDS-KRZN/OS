#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float a, b, c;
	printf("1) Enter a value for coefficient a:");
	scanf("%f", &a);
	printf("2) Enter a value for coefficient b:");
	scanf("%f", &b);
	printf("3) Enter a value for coefficient c:");
	scanf("%f", &c);
	float d, x1, x2;
	d = b*b-4*a*c;
	printf("D: %f\n", d);
	if (d>0)
	{
		x1 = (-b+sqrt(d))/(2*a);
		x2 = (-b-sqrt(d))/(2*a);
		printf("X1 = %f\nX2 = %f\n", x1, x2);
	} else if (d == 0)
	{
		x1 = (-b)/(2*a);
		printf("X = %f\n", x1);
	} else if (d<0)
	{
		printf("Equation doesn't have real roots!\a\n"); 
	}
	return 0;
}
