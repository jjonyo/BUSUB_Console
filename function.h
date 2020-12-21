#pragma once
#ifndef __FUNCTION
#include "information.h"

int search_data(TRANSPORT* input_data);
void show_data(TRANSPORT* input_data, int index);
void show_data_add(TRANSPORT* input_data, int index, int start, int dest);
void running(TRANSPORT* input_data, int index, int current, int dest);
void Alarm(char *destination);

#endif // !__BUS
