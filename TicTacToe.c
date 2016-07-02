#include<stdio.h>
#include<stdlib.h>

void init();
void display();
void play1();
void play2();
int win();
void again();

char ch[3][3];
int row,col;
int player;
int count;

int main()
{
	init();
	display();
	return 0;
}

void init()
{
	count = 9;
	player = 1;
	int i;
	int j;
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			ch[i][j] = '\0';
		}
	}
}

void display()
{
    int j;
    int i;
    printf("\t\t  <TIC-TAC-TOE>\n");
	for(j = 0; j < 10;j++)
	{
		printf("  ");
	}
	for(j = 0;j < 3;j++)
	{
		printf(" - ");
	}
	printf("\n");
	for(i = 0;i < 3;i++)
	{
		for(j = 0; j < 10;j++)
		{
			printf("  ");
		}
		for(j = 0;j < 3;j++)
		{
			printf("|%c|",ch[i][j]);
		}
		printf("\n");
		for(j = 0; j < 10;j++)
		{
			printf("  ");
		}
		for(j = 0;j < 3;j++)
		{
			printf(" - ");
		}
		printf("\n");
	}

	if(count)
	{
		if(player == 1)
		{
			play1();
		}
		else
		{
			play2();
		}
	}
	else
	{
		printf("\n----------------------------------->END OF GAME<-------------------------------\n");
		again();
	}
}

void play1()
{
	printf("\nPlayer 1 playing\n");
	printf("\nEnter the row: ");
	scanf("%d",&row);
	row--;
	printf("\nEnter the column: ");
	scanf ("%d",&col);
	col--;
	if(row < 3 && row >= 0 && col < 3 && col >= 0 && !ch[row][col])
	{
		ch[row][col] = 'x';
		count--;
		player = win();
		if(player == 1)
		{
		    system("cls");
			printf("---------------------------->Player 1 Wins!!! Congratulations!!!<-------------\n\n");
			count = 0;
			display();
		}
		else
		{
		    system("cls");
			display();
		}
	}
	else
	{
		printf("Wrong input... Enter again");
		play1();
	}
}

void play2()
{
	printf("\nPlayer 2 playing\n");
	printf("\nEnter the row: ");
	scanf("%d",&row);
	row--;
	printf("\nEnter the column: ");
	scanf("%d",&col);
	col--;
	if(row < 3 && row >= 0 && col < 3 && col >= 0 && !ch[row][col])
	{
		ch[row][col] = 'o';
		count--;
		player = win();
		if(player == 0)
		{
		    system("cls");
			printf("--------------------------------->Player 2 Wins!!! Congratulations!!!<----------------------------\n");
			count = 0;
			display();
		}
		else
		{
		    system("cls");
			display();
		}
	}
	else
	{
		printf("\nWrong input... Enter again");
		play2();
	}
}

int win()
{
	if(ch[row][0] == ch[row][1] && ch[row][1] == ch[row][2])
	{
		return player;
	}
	else if(ch[0][col] == ch[1][col] && ch[1][col] == ch[2][col])
	{
		return player;
	}
	else if(row == col && ch[0][0] == ch[1][1] && ch[1][1] == ch[2][2])
	{
		return player;
	}
	else if(row + col == 2 && ch[0][2] == ch[1][1] && ch[1][1] == ch[2][0])
	{
		return player;
	}
	else
	{
		player = !player;
		return player;
	}
}

void again()
{
	char choose;
	printf("\nIf you want to play again press (Y) else press any other key to exit:");
	fflush(stdin);
	scanf("%c",&choose);
	fflush(stdin);
	if(choose == 'Y' || choose == 'y')
	{
		init();
		system("cls");
		display();
		again();

	}
}
