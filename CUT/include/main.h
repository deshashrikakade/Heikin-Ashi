#ifdef __MAIN_H__
#define __MAIN_H__
#include <struct.h>

extern float haClose(stock *head);
extern void haClose(stock* currentCandle, stock* HeikenAshi, stock* prevHACandle);
extern int freeLinkedList(stock** headCandle);
extern void appendLinkedList(stock **headCandle, stock* data);
extern void display_stock(stock* st);
extern void printLinkedList(stock *st);
extern int loadFromFile(const char *fileName, stock** headCandle);
extern void makeHeikenAshi(stock* headCandle, stock** headHeikenAshi);
extern void checkColourChange(stock* headHeikenAshi);

#endif
