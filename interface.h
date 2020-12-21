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
#define TIME_LIMIT 5000 //3초
#define set_alarm 1 //알람 설정, 1-> 목적지 도착 1전 알람 , 2->목적지 도착 2전

void gotoxy(int x, int y);
void CursorView(char show);

//첫 실행화면 관련 출력함수
int display_menu();
int display_select();
void select_background();
void select_menu1();
void select_menu2();
void select_menu3();
void main_logo();
//1.시작 선택시 나오는 출력함수
int start_menu();
void start_background();
void start_menu1();
void start_menu2();

//2.설명 선택시 나오는 함수
Print_inforamtion(); //프로그램 설명

//출력함수 background
void setting_background();


#endif // !__INTERFACE
