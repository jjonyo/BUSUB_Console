/*
창의적 설계 기말프로젝트
버스/지하철 도착 알리미 BUSUB
소프트웨어학부 20185536 박종혁
*/




#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "function.h"
#include "information.h"
#pragma warning(disable:4996)



void main()
{
	while (1)
	{
		int select, transport;
		
		select = display_menu(); //select 1 -> 시작 , 2 -> 설명 , 3-> 종료 
		switch (select)
		{
		case 1:
			transport = start_menu();
			if (transport == BUS)
			{
				TRANSPORT* BUS_DATA = create_data(BUS); //메모리 할당
				data_set(BUS_DATA); //데이터 입력
				int index = search_data(BUS_DATA);
				int start, dest;
				if (index >= 0)
				{
					show_data(BUS_DATA, index);
					rewind(stdin);
					CursorView(1);
					start = get_startpos();
					dest = get_destpos();
					CursorView(0);
					running(BUS_DATA, index, start, dest);
				}
				else
				{
					system("cls");
					gotoxy(23, 10);
					printf("등록되지 않은 번호입니다. 메인 메뉴로 돌아갑니다.");
					getchar();
				}
				// BUS
			}
			else if (transport == SUBWAY)
			{
				TRANSPORT* SUBWAY_DATA = create_data(SUBWAY); //메모리 할당
				data_set(SUBWAY_DATA); //데이터 입력
				int index = search_data(SUBWAY_DATA);
				int start, dest;
				if (index >= 0)
				{
					show_data(SUBWAY_DATA, index);
					rewind(stdin);
					CursorView(1);
					start = get_startpos();
					dest = get_destpos();
					CursorView(0);
					running(SUBWAY_DATA, index, start, dest);
				}
				else
				{
					system("cls");
					gotoxy(23, 10);
					printf("등록되지 않은 번호입니다. 메인 메뉴로 돌아갑니다.");
					getchar();
				}

				// SUBWAY
			}
			break;
		case 2:
			// 설정 OR 설명
			Print_inforamtion();
			break;
		case 3:
			exit(0);
			break;
		default:
			break;
		}
		rewind(stdin);

	}

}