#include "information.h"
#include "interface.h"
#include "function.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#define set_alarm 1

int search_data(TRANSPORT* input_data)
{
	int ret = -1;
	if (input_data == NULL) return ret;
	rewind(stdin);
	if (input_data->select == BUS)
	{
		char bus_number[10];
		system("cls");
		gotoxy(25, 5);
		printf("ž���ϰ� �ִ� ������ ��ȣ�� �Է��ϼ���.");
		gotoxy(35, 10);
		printf("��");
		gotoxy(38, 10);
		gets_s(bus_number, sizeof(bus_number));

		for (int i = 0; i < input_data->current_element_count; i++)
		{
			if (strcmp(input_data->data[i].number, bus_number) == 0)
				ret = i;
		}

		return ret;
	}
	else
	{
		char subway_number[10];
		system("cls");
		gotoxy(25, 5);
		printf("ž���ϰ� ����ö�� ȣ���� �Է��ϼ���. (ex.7ȣ��)");
		gotoxy(35, 10);
		printf("��");
		gotoxy(38, 10);
		gets_s(subway_number, sizeof(subway_number));

		for (int i = 0; i < input_data->current_element_count; i++)
		{
			if (strcmp(input_data->data[i].number, subway_number) == 0)
				ret = i;
		}

		return ret;
	}
}

void show_data(TRANSPORT* input_data, int index)
{
	int count = input_data->data[index].route_count;
	system("cls");
	system("mode con: cols=100 lines=50");
	int x, y;
	setting_background();
	gotoxy(20, 10);
	printf("[%s]",input_data->data[index].number);
	gotoxy(20, 15);
	printf("���� ����� ��ȣ");
	gotoxy(20, 17);
	printf("��");
	gotoxy(20, 20);
	printf("���� ����� ��ȣ");
	gotoxy(20, 22);
	printf("��");
	x = 60, y = 1;
	for (int i = 0; i < count; i++)
	{
		gotoxy(x, y+=2 );
		printf("[%d]%s", i, input_data->data[index].route[i]);
	}
}

void show_data_add(TRANSPORT* input_data, int index, int current, int dest)
{
	int count = input_data->data[index].route_count;
	system("cls");
	system("mode con: cols=100 lines=50");
	int x = 40, y = 5;
	for (int i = 0; i < count; i++)
	{
		if (i == current)
		{
			RED;
			y += 2;
			gotoxy(x - 11, y);
			printf("������ġ��");

			gotoxy(x, y);
			printf("%s", input_data->data[index].route[i]);
			WHT;
		}
		else if (i == dest)
		{
			SKY;
			y += 2;
			gotoxy(x - 9, y);
			printf("��������");

			gotoxy(x, y);
			printf("%s", input_data->data[index].route[i]);
			WHT;
		}
		else
		{
			y += 2;
			gotoxy(x, y);
			printf("%s", input_data->data[index].route[i]);
		}


	}
}

void running(TRANSPORT* input_data, int index, int start, int dest)
{
	if (start >= dest)
	{
		
		system("cls");
		gotoxy(35, 15);
		printf("[ERROR]�߸��� �����Դϴ�.");	
		rewind(stdin);
		getchar();
		return;
	}
		
	srand((unsigned)time(NULL));
	double start_time;
	double end_time;
	double pst_time;
	char destination[MAX_STRING_SIZE];
	strcpy_s(destination, sizeof(input_data->data[index].route[dest]), input_data->data[index].route[dest]);

	int current = start;
	while (1)
	{
		if (current + set_alarm == dest) break; //������ ���� ����

		show_data_add(input_data, index, current, dest);

		start_time = clock();
		while (1)
		{
			end_time = clock();
			pst_time = (double)(end_time - start_time);
			if (pst_time >= TIME_LIMIT) break;
		}
		current++;
	}

	Alarm(input_data->data[index].route[dest]);
}

void Alarm(char *destination)
{
	system("cls");
	RED;
	for (int i = 0; i < 3; i++)
	{
		Sleep(500);
		gotoxy(27, 15);
		printf("[�˸�]����ĸ� �������� %s�� �����մϴ�!",destination);
		Sleep(1000);
		system("cls");
	}
	WHT;
}