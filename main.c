/*
â���� ���� �⸻������Ʈ
����/����ö ���� �˸��� BUSUB
����Ʈ�����к� 20185536 ������
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
		
		select = display_menu(); //select 1 -> ���� , 2 -> ���� , 3-> ���� 
		switch (select)
		{
		case 1:
			transport = start_menu();
			if (transport == BUS)
			{
				TRANSPORT* BUS_DATA = create_data(BUS); //�޸� �Ҵ�
				data_set(BUS_DATA); //������ �Է�
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
					printf("��ϵ��� ���� ��ȣ�Դϴ�. ���� �޴��� ���ư��ϴ�.");
					getchar();
				}
				// BUS
			}
			else if (transport == SUBWAY)
			{
				TRANSPORT* SUBWAY_DATA = create_data(SUBWAY); //�޸� �Ҵ�
				data_set(SUBWAY_DATA); //������ �Է�
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
					printf("��ϵ��� ���� ��ȣ�Դϴ�. ���� �޴��� ���ư��ϴ�.");
					getchar();
				}

				// SUBWAY
			}
			break;
		case 2:
			// ���� OR ����
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