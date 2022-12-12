#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_

#define DATE_LEN 100
#define STOCK_LINE_BUFFER 256


typedef struct _stock
{
	char date[DATE_LEN];
	float open; 
	float high;
	float low;
	float close;
	float adjClose;
	int volume;
	struct _stock *next;
} stock;

#endif
