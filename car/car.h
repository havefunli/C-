#pragma once
#include<reg52.h>
#include<intrins.h>
sfr P4 = 0xe8;
sbit Beep = P3 ^ 7; //蜂鸣器初始化
//3——8译码器的三个输入端
sbit A0 = P4 ^ 0;
sbit A1 = P2 ^ 0;
sbit A2 = P2 ^ 7;
//红外传感器的五个方向
sbit irR1 = P2 ^ 1;
sbit irR2 = P2 ^ 2;
sbit irR3 = P2 ^ 3;
sbit irR4 = P2 ^ 4;
sbit irR5 = P2 ^ 5;
//初始化传感器的方向
bit irC = 0, irL = 0, irR = 0, irLu = 0, irRu = 0; //C为1，左前2，左3，右前5，右4

//红外发射控制宏定义
#define MOUSE_IR_ON(GROUP_NO)\
do\
{\
    A0=(GROUP_NO)&0X01;\
    A1=(GROUP_NO)&0X02;\
    A2=(GROUP_NO)&0X04;\
} while (0);

unsigned char left_modi = 0, right_modi = 0; //修正变量

//记录岔路口坐标
xdata unsigned char stack_x[20] = { -1 };
xdata unsigned char stack_y[20] = { -1 };
unsigned char stack_top = 0;//堆柞指针

//单元格目标记录
unsigned char x = 0, y = 0;
//地图数据
unsigned char map[8][8]; //地图数据

//绝对方向与相对方向的和与4的余数
unsigned int dir_map = 0, dir_car = 0; //记录绝对方向  //规定0为上，1为右，2为下，3为左
//对数值进行运算
unsigned int move_x[4] = { 0,10,0,-10 };
unsigned int move_y[4] = { 1,0,-1,0 };

xdata unsigned char path[20] = { 5 };