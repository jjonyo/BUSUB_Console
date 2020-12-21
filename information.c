#include "information.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

#define MAX_STRING_SIZE 30
#define MAX_STATION_NUMBER 50

char dongjak01[MAX_STATION_NUMBER][MAX_STRING_SIZE] =
{
	"�޸���","���ع̾���Ʈ","�߾Ӻ�����","�����ʵ��б�","�ߴ����","�߾Ӵ뺴���Ĺ�",
	"�߾Ӵ뺴��","�߾Ӵ�����","�߾Ӵ��߹�","�߾Ӵ��Ĺ�","��ȭ�౹","���ۻ󵵱��ֵ�����",
	"���ͳλ󵵵�","�󵵿�","�븲����Ʈ","�ǿ�����Ʈ","�켺����Ʈ","������ȸ","�뷮���ѱ����б�����",
	"�뷮����","�뷮���������"
};

char dongjak10[MAX_STATION_NUMBER][MAX_STRING_SIZE] =
{
	"��鿪","���۽ǹ������Ա�","�漮��ȿ������","�漮��","�߾Ӵ뺴��","�߾Ӵ�����",
	"�߾Ӵ��߹�","�߾Ӵ��Ĺ�","��ȭ�౹","����󵵱��ֵ�����","���ͳλ󵵵�","�󵵿�1���ⱸ",
	"�󵵿�"
};

//////////////////////////////����ö
char one_line[MAX_STATION_NUMBER][MAX_STRING_SIZE]=
{
	"����","�ΰ�","�۳�","�ߵ�","��õ","�һ�","����","�¼�","������","����","����",
	"����","�ŵ���","������","�ű�","���","�뷮��","���","����","���￪"
};
char seven_line[MAX_STATION_NUMBER][MAX_STRING_SIZE] =
{
	"�¼�","õ��","�����Ÿ�","ö��","��������д���","������","�븲","��ǳ","�����",
	"�Ŵ���Ÿ�","��¹��","��","���Ǵ��Ա�","����","���","����","����͹̳�",
	"����","����","�е�","������û","û��","�Ҽ�������"
};

char nine_line[MAX_STATION_NUMBER][MAX_STRING_SIZE] =
{
	"���","��ȸ�ǻ��","���ǵ�","����","�뷮��","���","�漮","����","������",
	"�Ź���","����͹̳�","����","�ų���","����","������","�Ｚ�߾�","������","���տ��"
};

void data_set(TRANSPORT* set_data)
{
	if (set_data == NULL) return;


	if (set_data->select == BUS) //���� ������ �Է�
	{
		int index = 0;
		//����01�� ���� �߰�
		/////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("����01"), "����01"); //����01 ���� �Է�
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 21; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(dongjak01[i]), dongjak01[i]);
			set_data->data[index].route_count++;
		}
		index++;
		///////////////////////////////////////////////////////////////////////////

		//����10�� ���� �߰�
		//////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("����10"), "����10"); //����10 ���� �Է�
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 13; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(dongjak10[i]), dongjak10[i]);
			set_data->data[index].route_count++;
		}
		///////////////////////////////////////////////////////////////////////////

	}
	else //����ö ������ �Է�
	{
		int index = 0;
		//1ȣ�� �߰�
		/////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("1ȣ��"), "1ȣ��"); //7ȣ�� �Է�
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 20; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(one_line[i]), one_line[i]);
			set_data->data[index].route_count++;
		}
		index++;
		//////////////////////////////////////////////////////////////////////////

		//7ȣ�� �߰�
		/////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("7ȣ��"), "7ȣ��"); //7ȣ�� �Է�
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 23; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(seven_line[i]), seven_line[i]);
			set_data->data[index].route_count++;
		}
		index++;
		//////////////////////////////////////////////////////////////////////////

		//9ȣ�� �߰�
		//////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("9ȣ��"), "9ȣ��"); //9ȣ�� �Է�
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 18; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(nine_line[i]), nine_line[i]);
			set_data->data[index].route_count++;
		}
		index++;
		//////////////////////////////////////////////////////////////////////////
	}
}

TRANSPORT* create_data(int select)
{
	if (select != BUS && select != SUBWAY) return NULL;
	TRANSPORT* ret_data;
	ret_data = (TRANSPORT*)malloc(sizeof(TRANSPORT));

	if (select == BUS) //BUS
	{
		ret_data->select = BUS;
		ret_data->current_element_count = 0;
	}
	else //SUBWAY
	{
		ret_data->select = SUBWAY;
		ret_data->current_element_count = 0;
	}

	return ret_data;
}


int get_startpos()
{
	int start;
	gotoxy(24, 17);
	scanf("%d", &start);

	return start;
}

int get_destpos()
{
	int dest;
	gotoxy(24, 22);
	scanf("%d", &dest);
	return dest;
}

