#include "car.h"

void delay_ms(unsigned int ms)//软件延时
{
	unsigned char lem1, lem2;
	while (--ms)
	{
		_nop_();
		lem1 = 2;
		lem2 = 199;
		do
		{
			while (--lem2);
		} while (--lem1);
	}
}

////T2 中断
//void time2() interrupt 5
//{
//	static unsigned int lemon = 0;
//	static bit ir = 0;//本次中断是发射还是接收
//	int i = 0;
//
//	TF2 = 0;//清除中断标志位
//	if (!ir)//设置左前方发光二极管发射红外光
//	{
//		MOUSE_IR_ON(lemon);
//	}
//	else
//	{
//		switch (lemon++)
//		{
//		case 0:irC = irR1 == 0 ? 1 : 0; MOUSE_IR_ON(5); break; //前			
//		case 1:irLu = irR2 == 0 ? 1 : 0; MOUSE_IR_ON(5); break;	//左前	
//		case 2:irL = irR3 == 0 ? 1 : 0; MOUSE_IR_ON(5); break;	//左
//		case 3:irR = irR4 == 0 ? 1 : 0; MOUSE_IR_ON(5); break;	//右	
//		case 4:irRu = irR5 == 0 ? 1 : 0; MOUSE_IR_ON(5); break; //右前
//		}
//	}
//	ir = ~ir;//改变接收发射状态
//	if (lemon == 5)
//		lemon = 0;
//}

//void setTime2(unsigned int us)//设置T2自动重载寄存器和计数器初值
//{
//	TH2 = (65536 - us) / 256;
//	RCAP2H = (65536 - us) / 256;
//	TL2 = (65536 - us) % 256;
//	RCAP2L = (65536 - us) % 256;
//}
//
//void initTime2()//初始化中断函数
//{
//	EA = 1;//所有中断的总开关
//	ET2 = 1; //T2 中断
//	setTime2(5000);
//	TR2 = 1; //启动定时器2
//}

void left()
{
	unsigned char i = 0, j = 0;
	for (j = 0; j < 50; j++)
	{
		for (i = 0; i < 8; i++)
		{
			P1 = turn_left[i];
			delay_ms(3);
		}
	}
	dir_map = (dir_map + 3) % 4;
}
void right()
{
	unsigned char i = 0, j = 0;
	for (j = 0; j < 50; j++)
	{
		for (i = 0; i < 8; i++)
		{
			P1 = turn_right[i];
			delay_ms(3);
		}

	}
	dir_map = (dir_map + 1) % 4;    //右转之后绝对方向改变
}

void modify()   //为了修正小车的偏移量
{
	unsigned char i = 0;
	if ((irLu || irRu) && !irC)
	{
		if (irLu)
		{

			for (i = 0; i < 8; i++)
			{
				P1 = turn_right_2[i];
				delay_ms(3);
			}
		}
		if (irRu)
		{
			for (i = 0; i < 8; i++)
			{
				P1 = turn_left_2[i];
				delay_ms(3);
			}
		}
		left_modi++;
	}
}

void go_forward()  //前进函数
{
	unsigned char i = 0, j = 0;
	left_modi = 0;
	right_modi = 0;
	for (j = 0; j < 100 - right_modi; j++)
	{                          //由于修正会导致电机前进，所以应该减少前进的距离
		for (i = 0; i < 8; i++)
		{
			P1 = forward[i];
			delay_ms(3);
		}
		modify();
		right_modi += left_modi / 2;
		left_modi = left_modi % 2;
	}
	dir_car = dir_car + move_x[dir_map] + move_y[dir_map];
}

unsigned int is_reached(unsigned int poi)  //判断是否已经走过
{
	int lini = 0;
	poi = (poi + dir_map) % 4;
	lini = dir_car + move_x[poi] + move_y[poi];
	if (lini < 0)
	{
		return 0;
	}
	if ((0xf0 & map[lini / 10][lini % 10]) == 0xf0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int approach()//判断是否走过
{
	unsigned char i = 0;
	if (dir_car == 0) return 0;
	for (i = 0; i < 16; i++)
	{
		if ((dir_car / 10) == stack_x[i] && (dir_car % 10) == stack_y[i])
		{
			return 1;
		}
	}
	return 0;
}

void turn_back()  //回溯到上一个岔路口
{
	unsigned char lem;
	unsigned int pi = 0;
	while (1)
	{
		lem = map[dir_car / 10][dir_car % 10] & 0xf0;
		if (lem == 0x70) {
			pi = 0;
		}
		else if (lem == 0xe0) {
			pi = 1;
		}
		else if (lem == 0xc0) {
			pi = 2;
		}
		else if (lem == 0xd0) {
			pi = 3;
		}

		if (pi == dir_map) //绝对方向相同
		{
			right();
			right();//两次右转,实现掉头
			delay_ms(250);
			delay_ms(250);
			go_forward();
		}
		else if ((pi + dir_map) % 2 == 0) //绝对方向相反，直行
		{
			delay_ms(250);
			delay_ms(250);
			go_forward();
		}
		else  //右转或者左转
		{
			switch (dir_map) {
			case 0:
				if (pi == 3) {
					right();
				}
				else {
					left();
				}
				delay_ms(250);
				delay_ms(250);
				go_forward();
				break;
			case 1:
				if (pi == 0) {
					right();
				}
				else {
					left();
				}
				delay_ms(250);
				delay_ms(250);
				go_forward();
				break;
			case 2:
				if (pi == 1) {
					right();
				}
				else {
					left();
				}
				delay_ms(250);
				delay_ms(250);
				go_forward();
				break;
			case 3:
				if (pi == 2) {
					right();
				}
				else {
					left();
				}
				delay_ms(250);
				delay_ms(250);
				go_forward();
				break;
			default:
				break;
			}
		}
		if (approach() || is_end())  //达到最近的一个岔路口
		{
			delay_ms(50);
			break;
		}
	}
}

void fill_wall(unsigned char str, int x, int y)
{
	if (str == 0) {
		map[x][y] &= 0xf7;
	}
	else if (str == 1) {
		map[x][y] &= 0xfe;
	}
	else if (str == 2) {
		map[x][y] &= 0xfb;
	}
	else if (str == 3) {
		map[x][y] &= 0xfd;
	}
}

void add_message()//记录当前结点墙的信息，第四位记录是否有墙，高四位记录
{
	unsigned char str;
	unsigned char sum = 0;
	x = dir_car / 10; y = dir_car % 10;
	switch (dir_map)  //记录进入的绝对方向  上右下左,上下左右
	{
	case 0:map[x][y] &= 0x7f; break;  //上
	case 1:map[x][y] &= 0xef; break; //右
	case 2:map[x][y] &= 0xcf; break;  //下
	case 3:map[x][y] &= 0xdf; break;//左
	default:break;
	}
	if (!(dir_car == 0))  //初始节点的时候不记录后方，否则就记录来的方向
	{
		str = (dir_map + 2) % 4;
		fill_wall(str, x, y);
	}
	if (!irR)   //记录右方是否无墙    
	{
		sum++;
		str = (dir_map + 1) % 4;
		fill_wall(str, x, y);
	}
	if (!irC)  //记录前方是否无墙
	{
		sum++;
		str = dir_map;
		fill_wall(str, x, y);
	}
	if (!irL)  //记录左方是否无墙
	{
		sum++;
		str = (dir_map + 3) % 4;
		fill_wall(str, x, y);
	}
	if (sum >= 2)
	{
		stack_x[stack_top] = dir_car / 10;
		stack_y[stack_top] = dir_car % 10;
		stack_top++;
	}
}

void init_maze() //初始化迷宫函数
{
	unsigned char i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			map[i][j] = 0xff;
		}
	}
}

void is_destination()  //判断是否到达目标结点
{
	if (dir_car == poi_x * 10 + poi_y)
	{
		Beep = 0;
		delay_ms(250);
		delay_ms(250);
		delay_ms(250);
		delay_ms(250);//判断到终点就响
		Beep = 1;
	}
}
int is_end()  //判断是否回到起点
{
	if (dir_car == 0)
	{
		return 1;
	}
	else
		return 0;
}

void start_run() //右转法则,进行判断前进
{
	if (!approach())
		add_message();				//如果是已经走过的岔路口就不记录信息
	if (!irR && is_reached(1))  //右方无墙
	{
		right();
		delay_ms(250);
		delay_ms(250);
		go_forward();
	}
	else if (!irC && is_reached(0))
	{
		delay_ms(250);
		delay_ms(250);
		go_forward();
	}
	else if (!irL && is_reached(3))
	{
		left();
		delay_ms(250);
		delay_ms(250);
		go_forward();
	}
	else
	{
		turn_back();
	}
}

void operate_single()
{
	delay_ms(250);
	delay_ms(250);
	delay_ms(250);
	delay_ms(250);
	x = dir_car / 10;
	y = dir_car % 10;
	start_run();
	is_destination();    //是否走到终点
}

void main()
{
	init_maze(); //初始化迷宫数据
	initTime2();//初始化中断函数
	while (6)
	{
		operate_single();
		if (is_end())  //每走一格或者回溯到了岔路口，或者回到了起点都会进行一次判断
		{
			break;
		}
	}
	while (6);
}



