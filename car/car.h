#pragma once
#include<reg52.h>
#include<intrins.h>
sfr P4 = 0xe8;
sbit Beep = P3 ^ 7; //��������ʼ��
//3����8�����������������
sbit A0 = P4 ^ 0;
sbit A1 = P2 ^ 0;
sbit A2 = P2 ^ 7;
//���⴫�������������
sbit irR1 = P2 ^ 1;
sbit irR2 = P2 ^ 2;
sbit irR3 = P2 ^ 3;
sbit irR4 = P2 ^ 4;
sbit irR5 = P2 ^ 5;
//��ʼ���������ķ���
bit irC = 0, irL = 0, irR = 0, irLu = 0, irRu = 0; //CΪ1����ǰ2����3����ǰ5����4

//���ⷢ����ƺ궨��
#define MOUSE_IR_ON(GROUP_NO)\
do\
{\
    A0=(GROUP_NO)&0X01;\
    A1=(GROUP_NO)&0X02;\
    A2=(GROUP_NO)&0X04;\
} while (0);

unsigned char left_modi = 0, right_modi = 0; //��������

//��¼��·������
xdata unsigned char stack_x[20] = { -1 };
xdata unsigned char stack_y[20] = { -1 };
unsigned char stack_top = 0;//����ָ��

//��Ԫ��Ŀ���¼
unsigned char x = 0, y = 0;
//��ͼ����
unsigned char map[8][8]; //��ͼ����

//���Է�������Է���ĺ���4������
unsigned int dir_map = 0, dir_car = 0; //��¼���Է���  //�涨0Ϊ�ϣ�1Ϊ�ң�2Ϊ�£�3Ϊ��
//����ֵ��������
unsigned int move_x[4] = { 0,10,0,-10 };
unsigned int move_y[4] = { 1,0,-1,0 };

xdata unsigned char path[20] = { 5 };