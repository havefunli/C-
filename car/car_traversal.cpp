#include "car.h"

void delay_ms(unsigned int ms)//�����ʱ
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

////T2 �ж�
//void time2() interrupt 5
//{
//	static unsigned int lemon = 0;
//	static bit ir = 0;//�����ж��Ƿ��仹�ǽ���
//	int i = 0;
//
//	TF2 = 0;//����жϱ�־λ
//	if (!ir)//������ǰ����������ܷ�������
//	{
//		MOUSE_IR_ON(lemon);
//	}
//	else
//	{
//		switch (lemon++)
//		{
//		case 0:irC = irR1 == 0 ? 1 : 0; MOUSE_IR_ON(5); break; //ǰ			
//		case 1:irLu = irR2 == 0 ? 1 : 0; MOUSE_IR_ON(5); break;	//��ǰ	
//		case 2:irL = irR3 == 0 ? 1 : 0; MOUSE_IR_ON(5); break;	//��
//		case 3:irR = irR4 == 0 ? 1 : 0; MOUSE_IR_ON(5); break;	//��	
//		case 4:irRu = irR5 == 0 ? 1 : 0; MOUSE_IR_ON(5); break; //��ǰ
//		}
//	}
//	ir = ~ir;//�ı���շ���״̬
//	if (lemon == 5)
//		lemon = 0;
//}

//void setTime2(unsigned int us)//����T2�Զ����ؼĴ����ͼ�������ֵ
//{
//	TH2 = (65536 - us) / 256;
//	RCAP2H = (65536 - us) / 256;
//	TL2 = (65536 - us) % 256;
//	RCAP2L = (65536 - us) % 256;
//}
//
//void initTime2()//��ʼ���жϺ���
//{
//	EA = 1;//�����жϵ��ܿ���
//	ET2 = 1; //T2 �ж�
//	setTime2(5000);
//	TR2 = 1; //������ʱ��2
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
	dir_map = (dir_map + 1) % 4;    //��ת֮����Է���ı�
}

void modify()   //Ϊ������С����ƫ����
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

void go_forward()  //ǰ������
{
	unsigned char i = 0, j = 0;
	left_modi = 0;
	right_modi = 0;
	for (j = 0; j < 100 - right_modi; j++)
	{                          //���������ᵼ�µ��ǰ��������Ӧ�ü���ǰ���ľ���
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

unsigned int is_reached(unsigned int poi)  //�ж��Ƿ��Ѿ��߹�
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

int approach()//�ж��Ƿ��߹�
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

void turn_back()  //���ݵ���һ����·��
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

		if (pi == dir_map) //���Է�����ͬ
		{
			right();
			right();//������ת,ʵ�ֵ�ͷ
			delay_ms(250);
			delay_ms(250);
			go_forward();
		}
		else if ((pi + dir_map) % 2 == 0) //���Է����෴��ֱ��
		{
			delay_ms(250);
			delay_ms(250);
			go_forward();
		}
		else  //��ת������ת
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
		if (approach() || is_end())  //�ﵽ�����һ����·��
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

void add_message()//��¼��ǰ���ǽ����Ϣ������λ��¼�Ƿ���ǽ������λ��¼
{
	unsigned char str;
	unsigned char sum = 0;
	x = dir_car / 10; y = dir_car % 10;
	switch (dir_map)  //��¼����ľ��Է���  ��������,��������
	{
	case 0:map[x][y] &= 0x7f; break;  //��
	case 1:map[x][y] &= 0xef; break; //��
	case 2:map[x][y] &= 0xcf; break;  //��
	case 3:map[x][y] &= 0xdf; break;//��
	default:break;
	}
	if (!(dir_car == 0))  //��ʼ�ڵ��ʱ�򲻼�¼�󷽣�����ͼ�¼���ķ���
	{
		str = (dir_map + 2) % 4;
		fill_wall(str, x, y);
	}
	if (!irR)   //��¼�ҷ��Ƿ���ǽ    
	{
		sum++;
		str = (dir_map + 1) % 4;
		fill_wall(str, x, y);
	}
	if (!irC)  //��¼ǰ���Ƿ���ǽ
	{
		sum++;
		str = dir_map;
		fill_wall(str, x, y);
	}
	if (!irL)  //��¼���Ƿ���ǽ
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

void init_maze() //��ʼ���Թ�����
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

void is_destination()  //�ж��Ƿ񵽴�Ŀ����
{
	if (dir_car == poi_x * 10 + poi_y)
	{
		Beep = 0;
		delay_ms(250);
		delay_ms(250);
		delay_ms(250);
		delay_ms(250);//�жϵ��յ����
		Beep = 1;
	}
}
int is_end()  //�ж��Ƿ�ص����
{
	if (dir_car == 0)
	{
		return 1;
	}
	else
		return 0;
}

void start_run() //��ת����,�����ж�ǰ��
{
	if (!approach())
		add_message();				//������Ѿ��߹��Ĳ�·�ھͲ���¼��Ϣ
	if (!irR && is_reached(1))  //�ҷ���ǽ
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
	is_destination();    //�Ƿ��ߵ��յ�
}

void main()
{
	init_maze(); //��ʼ���Թ�����
	initTime2();//��ʼ���жϺ���
	while (6)
	{
		operate_single();
		if (is_end())  //ÿ��һ����߻��ݵ��˲�·�ڣ����߻ص�����㶼�����һ���ж�
		{
			break;
		}
	}
	while (6);
}



