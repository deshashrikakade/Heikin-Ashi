#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

void haClose(stock* currentCandle, stock* HeikenAshi , stock* prevHACandle)
{
	
        if ( HeikenAshi != NULL && prevHACandle != NULL && currentCandle != NULL)	
	{
		HeikenAshi -> close = (currentCandle->open + currentCandle->high + currentCandle->low + currentCandle->close)/4;     //HACLOSE
		HeikenAshi -> open = (prevHACandle->open + prevHACandle->close)/2;                                                   //HAOPEN

		if (currentCandle->high > HeikenAshi->open &&  currentCandle->high > HeikenAshi->close)                              //HAHIGH
				HeikenAshi -> high = currentCandle->high ;
		if ( HeikenAshi->open > currentCandle->high && HeikenAshi->open > HeikenAshi->close)
				HeikenAshi -> high = HeikenAshi->open ;
		if ( HeikenAshi->close > currentCandle->high && HeikenAshi->close > HeikenAshi->open)
				HeikenAshi -> high = HeikenAshi->close ;
		
		
		if (currentCandle->low < HeikenAshi->open &&  currentCandle->low < HeikenAshi->close)                                //HALOW
				HeikenAshi -> low = currentCandle->low ;
		if ( HeikenAshi->open < currentCandle->high && HeikenAshi->open < HeikenAshi->close)
				HeikenAshi -> low = HeikenAshi->open ;
		if ( HeikenAshi->close < currentCandle->high && HeikenAshi->close < HeikenAshi->open)
				HeikenAshi -> low = HeikenAshi->close ;
				
		strcpy(HeikenAshi -> date, currentCandle -> date);
		printf("HAClose -> %f\n", HeikenAshi -> close);
		printf("HAOpen -> %f\n", HeikenAshi -> open);
		printf("HAHigh -> %f\n", HeikenAshi -> high);
		printf("HALow -> %f\n", HeikenAshi -> low);
		printf("\n");
	}
}	


void makeHeikenAshi(stock* headCandle, stock** headHeikenAshi)
{
	stock* iter = headCandle ;
	stock* prevHAcandle = NULL ;
	
	while ( iter != NULL )
	{
		stock* heikenCandle = (stock*) calloc(1, sizeof(stock));
		if ( prevHAcandle == NULL )
		prevHAcandle = iter ;
		haClose(iter, heikenCandle, prevHAcandle);
		prevHAcandle = heikenCandle;
		appendLinkedList(headHeikenAshi, heikenCandle);
		iter = iter -> next;
	}

}

void checkColourChange(stock* headHeikenAshi)
{
	stock* iter = headHeikenAshi;
	while ( iter != NULL && iter->next != NULL)
	{
		if ( iter -> close <= iter  -> open) // Red
		{
			if ( iter -> next -> close < iter -> next -> open ) // red
			{
				// Both candles are red so no colour change.;
				printf (" ----------------------------------------------\n");
				printf ("Candles : Date %c%c-%c%c-%c%c%c%c , Price %f\n", 
					iter ->next -> date[8], iter ->next -> date[9],
					iter ->next -> date[5], iter ->next -> date[6],
					iter ->next -> date[0], iter ->next -> date[1],
					iter ->next -> date[2], iter ->next -> date[3],
					iter -> next -> close );
			}
			else  // Green
			{
				// Color changed  from Red to green ( Buy signal )
				printf (" ----------------------------------------------\n");
				printf ("Buy signal Date %c%c-%c%c-%c%c%c%c , Price %f\n", 
					iter ->next -> date[8], iter ->next -> date[9],
					iter ->next -> date[5], iter ->next -> date[6],
					iter ->next -> date[0], iter ->next -> date[1],
					iter ->next -> date[2], iter ->next -> date[3],
					iter -> next -> close );
			}
		}

	 	else if ( iter -> close >= iter  -> open) // green
		{
			if ( iter -> next -> close > iter -> next -> open ) // green
			{
				// Both candles are green so no colour change.;
				printf (" ----------------------------------------------\n");
				printf ("Candles : Date %c%c-%c%c-%c%c%c%c , Price %f\n", 
					iter ->next -> date[8], iter ->next -> date[9],
					iter ->next -> date[5], iter ->next -> date[6],
					iter ->next -> date[0], iter ->next -> date[1],
					iter ->next -> date[2], iter ->next -> date[3],
					iter -> next -> close);
				
			}
			else
			{
				// Color changed  from Green  to Red ( Sell signal ) 
				printf (" ----------------------------------------------\n");
				printf ("Sell signal date %c%c-%c%c-%c%c%c%c , Price %f\n", 
					iter ->next -> date[8], iter ->next -> date[9],
					iter ->next -> date[5], iter ->next -> date[6],
					iter ->next -> date[0], iter ->next -> date[1],
					iter ->next -> date[2], iter ->next -> date[3],
					iter -> next -> close );
			}
		}
                                       iter = iter -> next; 
	}	

}


