#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("******    1. play        *****\n");
	printf("******    0. exit        *****\n");
	printf("******************************\n");
}

void game()
{
	//�洢���� - ��ά����
	char board[ROW][COL];
	//��ʼ������ - ��ʼ���ո�
	InitBoard(board, ROW, COL);

	//��ӡһ������ - �����Ǵ�ӡ���������
	DisplayBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		//�������
		PlayerMoveA(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
	//	ret = IsWin(board, ROW, COL);
	//	if (ret != 'C')
		//	break;
		//��������
		PlayerMoveB(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ����Ϸ
	//	ret = IsWin(board, ROW, COL);
	//	if (ret != 'C')
	//		break;
	}
	//if (ret == '*')
	//{
	//	printf("���Ӯ��\n");
	//}
	//else if (ret == '#')
	//{
	//	printf("����Ӯ��\n");
	//}
	//else
	//{
	//	printf("ƽ��\n");
	//}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
//	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}

