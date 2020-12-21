#pragma once
#ifndef __INTERFACE

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define Orgn SetConsoleTextAttribute(COL, 0x0007)
#define SKY SetConsoleTextAttribute(COL, 0x000b);
#define WHT SetConsoleTextAttribute(COL,0x000F); 
#define RED SetConsoleTextAttribute(COL,0x000c );
#define GREEN SetConsoleTextAttribute(COL,0x000a );
#define YELLOW SetConsoleTextAttribute(COL,0x000e );
#define PLUM SetConsoleTextAttribute(COL,0x000d );
#define ESC 27
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define TIME_LIMIT 5000 //3��
#define set_alarm 1 //�˶� ����, 1-> ������ ���� 1�� �˶� , 2->������ ���� 2��

void gotoxy(int x, int y);
void CursorView(char show);

//ù ����ȭ�� ���� ����Լ�
int display_menu();
int display_select();
void select_background();
void select_menu1();
void select_menu2();
void select_menu3();
void main_logo();
//1.���� ���ý� ������ ����Լ�
int start_menu();
void start_background();
void start_menu1();
void start_menu2();

//2.���� ���ý� ������ �Լ�
Print_inforamtion(); //���α׷� ����

//����Լ� background
void setting_background();


#endif // !__INTERFACE
