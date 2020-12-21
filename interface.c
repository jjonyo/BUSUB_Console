#include "interface.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h> 
#pragma warning(disable:4996)

void gotoxy(int x, int y)
{
	COORD pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int display_menu() //�̿ϼ�
{
	int select;
	CursorView(0);
	system("mode con: cols=90 lines=30");
	system("title ������ ���� �˶� BUSUB");
	main_logo();
	select = display_select();
	
	return select;
}

int display_select()
{
	int flag = 1;
	char key;
	select_background();

	while (1)
	{
		if (flag == 1)
			select_menu1();

		key = getch();
		if (key == -32)
			key = getch();
		switch (key)
		{
		case UP:
			if (flag == 1)
			{
				select_menu1();
				flag = 1;

			}
			else if (flag == 2)
			{
				select_menu1();
				flag = 1;
			}
			else
			{
				select_menu2();
				flag = 2;
			}
			break;
		case DOWN:
			if (flag == 1)
			{
				select_menu2();
				flag = 2;
			}
			else if (flag == 2)
			{
				select_menu3();
				flag = 3;
			}
			else
			{
				select_menu3();
				flag = 3;
			}
			break;
		}
		if (key == ENTER)
		{
			return flag;
		}
	}
	select_menu1();
}

void select_background()
{
	int x = 33, y = 23;
	gotoxy(x, y);
	printf("������������������������������������");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("������������������������������������");
}
void select_menu1()
{
	gotoxy(38, 24);
	printf("�� ����");
	gotoxy(38, 26);
	printf("   ����");
	gotoxy(38, 28);
	printf("   ����");
	gotoxy(38, 30);
}
void select_menu2()
{
	gotoxy(38, 24);
	printf("   ����");
	gotoxy(38, 26);
	printf("�� ����");
	gotoxy(38, 28);
	printf("   ����");
}
void select_menu3()
{
	gotoxy(38, 24);
	printf("   ����");
	gotoxy(38, 26);
	printf("   ����");
	gotoxy(38, 28);
	printf("�� ����");
}

int start_menu()
{
	system("cls");
	int flag = 100;
	char key;
	start_background();

	while (1)
	{
		if (flag == 100)
			start_menu1();

		key = getch();
		if (key == -32)
			key = getch();

		switch (key)
		{
		case UP:
			if (flag == 100)
			{
				start_menu1();
				flag = 100;
			}
			else if (flag == 200)
			{
				start_menu1();
				flag = 100;
			}
			break;
		case DOWN:
			if (flag == 100)
			{
				start_menu2();
				flag = 200;
			}
			else if (flag == 200)
			{
				start_menu2();
				flag = 200;
			}
			break;
		}
		if (key == ENTER)
		{
			return flag;
		}
	}
	start_menu1();
}
void start_background()
{
	int x = 34, y = 11;
	gotoxy(x, y);
	printf("������������������������������������");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("��                ��");
	gotoxy(x, ++y);
	printf("������������������������������������");
}
void setting_background()
{
	int x = 16, y = 9;
	gotoxy(x, y);
	printf("����������������������������������������������������������");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("��			   ��");
	gotoxy(x, ++y);
	printf("����������������������������������������������������������");
}
void start_menu1()
{
	gotoxy(38, 13);
	printf("�� BUS");
	gotoxy(38, 15);
	printf("   SUBWAY");
}
void start_menu2()
{
	gotoxy(38, 13);
	printf("   BUS");
	gotoxy(38, 15);
	printf("�� SUBWAY");
}

void main_logo()
{
	WHT;
	int x = 17, y = 3;
	gotoxy(x, y);
	printf("�ߡߡߡ�");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("�ߡߡ�");
	gotoxy(x, ++y);
	printf("�ߡ�");
	gotoxy(x, ++y);
	printf("�ߡߡ�");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("�ߡߡߡ�");
	///////////////////////////////////////B
	x = 28, y = 3;
	gotoxy(x, y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf(" ��  ��");
	gotoxy(x, ++y);
	printf("  �ߡ�  ");
	//////////////////////////////////U
	x = 38, y = 3;
	RED;
	gotoxy(x, y);
	printf("     ��");
	gotoxy(x, ++y);
	printf("   ��");
	gotoxy(x, ++y);
	printf(" ��");
	gotoxy(x, ++y);
	printf("��");
	gotoxy(x, ++y);
	printf("��");
	gotoxy(x, ++y);
	printf("  ��");
	gotoxy(x, ++y);
	printf("     ��");
	gotoxy(x, ++y);
	printf("       ��");
	gotoxy(x, ++y);
	printf("     ��");
	gotoxy(x, ++y);
	printf("   ��");
	gotoxy(x, ++y);
	printf(" ��");
	/////////////////////////////S
	x = 49, y = 3;
	WHT;
	gotoxy(x, y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf(" ��  ��");
	gotoxy(x, ++y);
	printf("  �ߡ�  ");
	//////////////////////////////////U
	x = 59, y = 3;
	gotoxy(x, y);
	printf("�ߡߡߡ�");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("�ߡߡ�");
	gotoxy(x, ++y);
	printf("�ߡ�");
	gotoxy(x, ++y);
	printf("�ߡߡ�");
	gotoxy(x, ++y);
	printf("��    ��");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("��     ��");
	gotoxy(x, ++y);
	printf("�ߡߡߡ�");
	///////////////////////////////////////B
	WHT;
}

Print_inforamtion()
{
	system("cls");

	rewind(stdin);
	gotoxy(23, 3);
	printf("--------------���α׷� �Ұ�---------------");
	gotoxy(24, 7);
	printf("1.BUS or SUBWAY ����");
	gotoxy(24, 9);
	printf("2.������ȣ or ����ö ȣ�� ��ȣ �˻�");
	gotoxy(24, 11);
	printf("3.��߿��� ������ ����");
	gotoxy(24, 13);
	printf("4.�����ϱ� �� �˶�!");
	
	int i, y = 5;
	char msg[] = "Press Any Key to Continue . . .     ";
	int offset;
	while (!kbhit())
	{
		for (offset = 0; offset < strlen(msg); offset++)
		{
			gotoxy(27, 26);
			printf("%s", msg + offset);
			for (i = 0; i < offset; i++)
				printf("%c", msg[i]);
			Sleep(100);
			if (kbhit())
				break;
		}
	}
	getchar();

}