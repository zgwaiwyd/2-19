#pragma once


//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//���ŵĶ���
#define ROW 10
#define COL 10

//����������

//��ʼ�����̵�
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ���̵ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMoveA(char board[ROW][COL], int row, int col);

//��������
void PlayerMoveB(char board[ROW][COL], int row, int col);

//
//1. ���Ӯ�� - *
//2. ����Ӯ�� - #
//3. ƽ�� - Q
//4. ��Ϸ���� - C

//�ж���Ϸ�Ƿ�����Ӯ
char IsWin(char board[ROW][COL], int row, int col);

