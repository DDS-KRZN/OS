#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	double fx, gx;
	printf("Enter value: ");
	scanf("%d", &x);
	fx = exp(-(abs(x)))*sin(x);
	printf("f(x)=exp(-|x|)sin(x)\n");
	printf("f(x)=%d\n", fx);
	gx = exp(-(abs(x)))*cos(x);
	printf("g(x)=exp(-|x|)cos(x)\n");
	printf("g(x)=%d\n", gx);
	return 0;
}
