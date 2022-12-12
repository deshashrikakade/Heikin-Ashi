#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>

int freeLinkedList(stock** headCandle)
{
    stock* iter = *headCandle;
    int recordsFreed = 0;
    
    while ( iter != NULL )
    {
        stock* temp = iter ;
        iter = iter -> next ;
        if ( temp != NULL)
		{
            		free (temp);
			recordsFreed++;
		}
    }
    return recordsFreed;

}

void appendLinkedList(stock **headCandle, stock* data)
{
    stock* iter = *headCandle ;

    if ( *headCandle == NULL )
    {
        *headCandle = data ;
    }
    else
    {
        while ( iter -> next != NULL)
        iter = iter -> next;
        iter -> next = data ;
    }
    data -> next = NULL ;
}

void display_stock(stock* st)
{
    printf("| %s | %.5f | %.5f | %.5f | %.5f | %.5f | %9d |\n",
        st -> date,
        st -> open,
        st -> high,
        st -> low,
        st -> close,
        st -> adjClose,
        st -> volume );
}

void printLinkedList(stock *st)
{
    stock* iter = st;
    while ( iter != NULL )
    {
        display_stock(iter);
        iter = iter -> next ;
    }

}

int loadFromFile(const char *fileName, stock **headCandle)
{
	char lineBuffer[STOCK_LINE_BUFFER];
	const char* seperator = "," ;
	char* token = NULL ;

	FILE* stockFile = fopen (fileName, "r");
	if (stockFile == NULL )
    	{
		printf("Issue opening the file %s\n", fileName);
		return EXIT_FAILURE ;
	}
	
	fgets ( lineBuffer, STOCK_LINE_BUFFER, stockFile);
	
	while ( fgets ( lineBuffer, STOCK_LINE_BUFFER, stockFile) != 0)
	{
		stock *iter = (stock*)malloc(sizeof(struct _stock));
		if ( iter == NULL )
		{
			printf("Could not allocate memory !\n");
			break;
		}

		token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			strcpy(iter -> date, token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> open = atof(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> high = atof(token);
			
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> low = atof(token);
		}


		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> close = atof(token);
		}
		
		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> adjClose = atof(token);
		}
		
		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> volume = atoi(token);
		}
		
		iter -> next = NULL;
		appendLinkedList(headCandle, iter);
	}

	fclose(stockFile);
	return 0;
}

