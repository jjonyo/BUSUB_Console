#pragma once
#ifndef INFORMATION

#define MAX_ELEMENT_SIZE 50
#define MAX_STRING_SIZE 30
#define MAX_STATION_NUMBER 50

#define BUS 100
#define SUBWAY 200

#define TRUE 1
#define FALSE 0

typedef struct element
{
	char number[10]; //����,����ö ��ȣ
	int route_count; //�뼱 ����
	char route[MAX_STATION_NUMBER][MAX_STRING_SIZE];
}element;

typedef struct TRANSPORT
{
	int select; //BUS 100, SUBWAY 200
	int current_element_count; //��ϵ� ����,����ö ���
	element data[MAX_ELEMENT_SIZE];
}TRANSPORT;

TRANSPORT* create_data(int select);
void data_set(TRANSPORT* set_data); //������ �Է�
int get_startpos(void);
int get_destpos(void);




#endif // !INFORMATION
