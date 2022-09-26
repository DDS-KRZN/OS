#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int rulesText(){
	printf("For each move, 100 credits are withdrawn.\nIf the combination is: 000, 111, 222, 333, 444 or 555 - you get 500 credits.\nIf 5XX or 7XX (X is any number) you get 200 credits. If 55X or 75X (X - any number) - you get 300 credits.\nIf 666 - 300 credits are removed from you.\n777 - jackpot and game over.\n");
}

int lotery(credits){
	int a1, a2, a3;
	credits-=100;
	a1 = rand()%8;	// M + rand() / (RAND_MAX / (N - M + 1) + 1)
	printf("%d\t", a1);
	a2 = rand()%8;
	printf("%d\t", a2);
	a3 = rand()%8;
	printf("%d\n", a3);
	if (((a1 == a2)&&(a2 == a3)) && ((a1!=6)&&(a2!=6)&&(a3!=6))) // esli combinatsia odinakova`a i net 666
	{
		printf("Your win! +500 credits\n\a");
		credits+=500;		
	} else if ((a1==5 && a2==5) || (a1==7 && a2==7))	// esli 55X ili 77X
	{
		printf("Your win! +300 credits\n\a");
		credits+=300;
	} else if (((a1==5)) || ((a1==7)))	// esli 5XX ili 7XX
	{
		printf("Your win! +200 credits\n\a");
		credits+=200;
	} else if (a1==6 && a2==6 && a3==6)		// esli 666
	{
		printf("Your lose! -300 credits\n\a");
		credits-=300;
	} else if (a1==7 && a2==7 && a3==7)		// esli 777
	{
		printf("Jackpot!\n\a");
		exit(0);
	}
	return credits;
}

int main()
{
	//setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int credits = 5000;
	int ch;
	while(1){
		if(credits < 100){
			printf("\nNot enough credits to play!\n\a");
			exit(0);
		}
		printf("\n----- MENU -----\n");
		printf("Credits left: %d\n", credits);
		printf("\t1: Start\n");
		printf("\t2: Rules and rewards\n");
		printf("\t0: Exit\n");
		printf("Your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 0: exit(0);
			case 1: credits = lotery(credits); break;
			case 2: rulesText(); break;
			default: printf("Invalid value entered!\a\n"); break;
		}
	}
	return 0;
}
