#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int rulesText(){
	printf("За каждый ход снимается 100 кредитов.\nЕсли комбинация: 000, 111, 222, 333, 444 или 555 - вы получаете 500 кредитов.\nЕсли 5XX или 7XX (X - любое число) - вы получаете 200 кредитов.\nЕсли 55X или 75X (X - любое число) - вы получаете 300 кредитов\nЕсли 666 - с вас снимают 300 кредитов.\n777 - джекпот и конец игры\n");
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
		printf("Победа! +500 кредитов\n\a");
		credits+=500;		
	} else if ((a1==5 && a2==5) || (a1==7 && a2==7))	// esli 55X ili 77X
	{
		printf("Победа! +300 кредитов\n\a");
		credits+=300;
	} else if (((a1==5)) || ((a1==7)))	// esli 5XX ili 7XX
	{
		printf("Победа! +200 кредитов\n\a");
		credits+=200;
	} else if (a1==6 && a2==6 && a3==6)		// esli 666
	{
		printf("Проигрыш! -300 кредитов\n\a");
		credits-=300;
	} else if (a1==7 && a2==7 && a3==7)		// esli 777
	{
		printf("Джекпот!\n\a");
		exit(0);
	}
	return credits;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int credits = 5000;
	int ch;
	while(1){
		if(credits < 100){
			printf("\nНедостаточно кредитов для игры!\n\a");
			exit(0);
		}
		printf("\n----- МЕНЮ -----\n");
		printf("Кредитов осталось: %d\n", credits);
		printf("\t1: Старт\n");
		printf("\t2: Правила и награды\n");
		printf("\t0: Выход\n");
		printf("Ваш выбор: ");
		scanf("%d", &ch);
		switch(ch){
			case 0: exit(0);
			case 1: credits = lotery(credits); break;
			case 2: rulesText(); break;
			default: printf("Введено некорректное значение!\a\n"); break;
		}
	}
	return 0;
}
