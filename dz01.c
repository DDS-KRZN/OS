#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int rulesText(){
	printf("�� ������ ��� ��������� 100 ��������.\n���� ����������: 000, 111, 222, 333, 444 ��� 555 - �� ��������� 500 ��������.\n���� 5XX ��� 7XX (X - ����� �����) - �� ��������� 200 ��������.\n���� 55X ��� 75X (X - ����� �����) - �� ��������� 300 ��������\n���� 666 - � ��� ������� 300 ��������.\n777 - ������� � ����� ����\n");
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
		printf("������! +500 ��������\n\a");
		credits+=500;		
	} else if ((a1==5 && a2==5) || (a1==7 && a2==7))	// esli 55X ili 77X
	{
		printf("������! +300 ��������\n\a");
		credits+=300;
	} else if (((a1==5)) || ((a1==7)))	// esli 5XX ili 7XX
	{
		printf("������! +200 ��������\n\a");
		credits+=200;
	} else if (a1==6 && a2==6 && a3==6)		// esli 666
	{
		printf("��������! -300 ��������\n\a");
		credits-=300;
	} else if (a1==7 && a2==7 && a3==7)		// esli 777
	{
		printf("�������!\n\a");
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
			printf("\n������������ �������� ��� ����!\n\a");
			exit(0);
		}
		printf("\n----- ���� -----\n");
		printf("�������� ��������: %d\n", credits);
		printf("\t1: �����\n");
		printf("\t2: ������� � �������\n");
		printf("\t0: �����\n");
		printf("��� �����: ");
		scanf("%d", &ch);
		switch(ch){
			case 0: exit(0);
			case 1: credits = lotery(credits); break;
			case 2: rulesText(); break;
			default: printf("������� ������������ ��������!\a\n"); break;
		}
	}
	return 0;
}
