
#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if(i<row-1)
//			printf("---|---|---\n");
//	}
//}
//


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int a = 0;
			for (a = 0; a < col; a++)
			{
				printf("---");
				if (a < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


void PlayerMoveA(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("���1��:>\n");

	while (1)
	{
		printf("���������������:>");
		scanf_s("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			//�����Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ��, ����������\n");
			}
		}
		else
		{
			printf("����Ƿ�, ����������\n");
		}
	}
}

void PlayerMoveB(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("���2��:>\n");

	while (1)
	{
		printf("���������������:>");
		scanf_s("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			//�����Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("���걻ռ��, ����������\n");
			}
		}
		else
		{
			printf("����Ƿ�, ����������\n");
		}
	}
}


//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	printf("������:>\n");
//
//	while (1)
//	{
//		int x = rand() % row;
//		int y = rand() % col;
//
//		//�ж�ռ��
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}


int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//����û��
			}
		}
	}

	return 1;//��������
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж�ʮ��
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return  board[i][1];//
		}
	}

	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//�ж�ƽ��
	//����������˷���1�� ��������0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//����
	return 'C';
}