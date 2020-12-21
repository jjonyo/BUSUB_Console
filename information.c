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
	"달마사","유앤미아파트","중앙빌리지","은로초등학교","중대부초","중앙대병원후문",
	"중앙대병원","중앙대정문","중앙대중문","중앙대후문","이화약국","동작상도국주도서관",
	"상도터널상도동","상도역","대림아파트","건영아파트","우성아파트","강남교회","노량진한국법학교육원",
	"노량진역","노량진수산시장"
};

char dongjak10[MAX_STATION_NUMBER][MAX_STRING_SIZE] =
{
	"노들역","동작실버센터입구","흑석동효사정앞","흑석역","중앙대병원","중앙대정문",
	"중앙대중문","중앙대후문","이화약국","동장상도국주도서관","상도터널상도동","상도역1번출구",
	"상도역"
};

//////////////////////////////지하철
char one_line[MAX_STATION_NUMBER][MAX_STRING_SIZE]=
{
	"부평","부개","송내","중동","부천","소사","역곡","온수","오류동","개봉","구일",
	"구로","신도림","영등포","신길","대방","노량진","용산","남영","서울역"
};
char seven_line[MAX_STATION_NUMBER][MAX_STRING_SIZE] =
{
	"온수","천왕","광명사거리","철산","가산디지털단지","남구로","대림","신풍","보라매",
	"신대방삼거리","장승배기","상도","숭실대입구","남성","사당","내방","고속터미널",
	"반포","논현","학동","강남구청","청담","뚝섬유원지"
};

char nine_line[MAX_STATION_NUMBER][MAX_STRING_SIZE] =
{
	"당산","국회의사당","여의도","샛강","노량진","노들","흑석","동작","구반포",
	"신반포","고속터미널","사평","신논현","언주","선정릉","삼성중앙","봉은사","종합운동장"
};

void data_set(TRANSPORT* set_data)
{
	if (set_data == NULL) return;


	if (set_data->select == BUS) //버스 데이터 입력
	{
		int index = 0;
		//동작01번 버스 추가
		/////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("동작01"), "동작01"); //동작01 버스 입력
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 21; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(dongjak01[i]), dongjak01[i]);
			set_data->data[index].route_count++;
		}
		index++;
		///////////////////////////////////////////////////////////////////////////

		//동작10번 버스 추가
		//////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("동작10"), "동작10"); //동작10 버스 입력
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 13; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(dongjak10[i]), dongjak10[i]);
			set_data->data[index].route_count++;
		}
		///////////////////////////////////////////////////////////////////////////

	}
	else //지하철 데이터 입력
	{
		int index = 0;
		//1호선 추가
		/////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("1호선"), "1호선"); //7호선 입력
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 20; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(one_line[i]), one_line[i]);
			set_data->data[index].route_count++;
		}
		index++;
		//////////////////////////////////////////////////////////////////////////

		//7호선 추가
		/////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("7호선"), "7호선"); //7호선 입력
		set_data->data[index].route_count = 0;
		set_data->current_element_count++;
		for (int i = 0; i < 23; i++)
		{
			strcpy_s(set_data->data[index].route[i], sizeof(seven_line[i]), seven_line[i]);
			set_data->data[index].route_count++;
		}
		index++;
		//////////////////////////////////////////////////////////////////////////

		//9호선 추가
		//////////////////////////////////////////////////////////////////////////
		strcpy_s(set_data->data[index].number, sizeof("9호선"), "9호선"); //9호선 입력
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

