#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>

int main()
{
	int ch , ch1, ch2, ch3, ch4, ch5;
    	int returnValue = 0;
	do 
	{
		printf("###################################################\n");
    		printf("********     Welcome to TA Screener 2     ********\n");
    		printf("###################################################\n");
    		printf(" **List of Stocks** \n");	
		printf(" 1. TATA POWER \n");
		printf(" 2. ICICI BANK \n");
		printf(" 3. ADANI POWER \n");
		printf(" 4. HDFC BANK \n");
		printf(" 5. AXB \n");
		printf(" 6. Exit the system.\n");
		printf("⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆\n\n");
	
		printf("Enter a valid choice (1-6): ");
		returnValue = scanf ("%d", &ch);
		printf("\n");
		printf("⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆⋆\n");
		
		if ( returnValue == 0 || returnValue ==  EOF)
		{
			fflush(stdin);
			printf("* Invalid input. Please enter valid input\n");
			break;
		}
		
		stock *headCandle = NULL;
		stock *headHeikenAshi = NULL ;
		stock *headcurrentCandle = NULL ;
		stock *headprevHACandle = NULL ;

		
		switch(ch)
		{
			case 1:
		               
				do
				{
				       loadFromFile("../data/tatapower.csv", &headCandle);
					printf("*** TATA POWER *** \n");
					printf("⋆ 1. To display CSV file \n");
					printf("⋆ 2. To display Heikin Ashi Values \n");
					printf("⋆ 3. To display the colour change of candles \n");
					printf("⋆ 4. Exit \n");
					
					scanf ("%d", &ch1);
					printf("\n");
					
					switch(ch1)
					{
					case 1:
						printLinkedList(headCandle);
						break;
					case 2:
					        makeHeikenAshi(headCandle, &headHeikenAshi);
					        haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						break;
					case 3:
					        makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						checkColourChange(headHeikenAshi);
						break;
					case 4:
						freeLinkedList(&headCandle);
                                              freeLinkedList(&headprevHACandle);
						freeLinkedList(&headcurrentCandle);
						freeLinkedList(&headHeikenAshi);
						exit(0);
					
					default:
						printf("Invalid Choice.");
				    		continue;
					
					}
					
				} while (ch1 != 4);
				
				break;
				
			case 2:
				//int ch2;
				do
				{
					loadFromFile("../data/icicibank.csv", &headCandle);
					printf("***  ICICI BANK *** \n");
					printf("⋆ 1. To display CSV file \n");
					printf("⋆ 2. To display Heikin Ashi Values \n");
					printf("⋆ 3. To display the colour change of candles \n");
					printf("⋆ 4. Exit \n");
					
					scanf ("%d", &ch2);
					printf("\n");
					
					switch(ch2)
					{
					case 1:
						printLinkedList(headCandle);
						break;
					case 2:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						break;
					case 3:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						checkColourChange(headHeikenAshi);
						break;
					case 4:
						freeLinkedList(&headCandle);
                                              freeLinkedList(&headprevHACandle);
						freeLinkedList(&headcurrentCandle);
						freeLinkedList(&headHeikenAshi);
						exit(0);
					
					default:
						printf("Invalid Choice.");
				    		continue;
					
					}
					
				} while (ch2 != 4);
				
				break;
				
			case 3:
				//int ch3;
				do
				{
					loadFromFile("../data/adanipower.csv", &headCandle);
					printf("*** ADANI POWER *** \n");
					printf("⋆ 1. To display CSV file \n");
					printf("⋆ 2. To display Heikin Ashi Values \n");
					printf("⋆ 3. To display the colour change of candles \n");
					printf("⋆ 4. Exit \n");
					
					scanf ("%d", &ch3);
					printf("\n");
					
					
					switch(ch3)
					{
					case 1:
						printLinkedList(headCandle);
						break;
					case 2:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						break;
					case 3:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						checkColourChange(headHeikenAshi);
						break;
					case 4:
						freeLinkedList(&headCandle);
                                              freeLinkedList(&headprevHACandle);
						freeLinkedList(&headcurrentCandle);
						freeLinkedList(&headHeikenAshi);
						exit(0);
					
					default:
						printf("Invalid Choice.");
				    		continue;
					
					}
					
				} while (ch3 != 4);
				
				break;
				
			case 4:
				//int ch4;
				do
				{
					loadFromFile("../data/hdfcbank.csv", &headCandle);
					printf("*** HDFC BANK *** \n");
					printf("⋆ 1. To display CSV file \n");
					printf("⋆ 2. To display Heikin Ashi Values \n");
					printf("⋆ 3. To display the colour change of candles \n");
					printf("⋆ 4. Exit \n");
					
					scanf ("%d", &ch4);
					printf("\n");
					
					
					switch(ch4)
					{
					case 1:
						printLinkedList(headCandle);
						break;
					case 2:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						break;
					case 3:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						checkColourChange(headHeikenAshi);
						break;
					case 4:
						freeLinkedList(&headCandle);
                                              freeLinkedList(&headprevHACandle);
						freeLinkedList(&headcurrentCandle);
						freeLinkedList(&headHeikenAshi);
						exit(0);
					
					default:
						printf("Invalid Choice.");
				    		continue;
					
					}
					
				} while (ch4 != 4);
				
				break;
				
			case 5:
				//int ch5;
				do
				{
					loadFromFile("../data/axb.csv", &headCandle);
					printf("*** AXIX BANK *** \n");
					printf("⋆ 1. To display CSV file \n");
					printf("⋆ 2. To display Heikin Ashi Values \n");
					printf("⋆ 3. To display the colour change of candles \n");
					printf("⋆ 4. Exit \n");
					
					scanf ("%d", &ch5);
					printf("\n");
					
					
					switch(ch5)
					{
					case 1:
						printLinkedList(headCandle);
						break;
					case 2:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						break;
					case 3:
						makeHeikenAshi(headCandle, &headHeikenAshi);
			        		haClose(headcurrentCandle,headHeikenAshi,headprevHACandle);
						checkColourChange(headHeikenAshi);
						break;
					case 4:
						freeLinkedList(&headCandle);
                                              freeLinkedList(&headprevHACandle);
						freeLinkedList(&headcurrentCandle);
						freeLinkedList(&headHeikenAshi);
						exit(0);
					
					default:
						printf("Invalid Choice.");
				    		continue;
					
					}
					
				} while (ch5 != 4);
				
				break;
				
			case 6:
				freeLinkedList(&headCandle);
				printf("* Exit. \n\n");
				exit(0);
			
			default:
			    	printf("* Kindly enter valid number i.e. (1-6).\n");
				continue;
		}

	} while ( ch != 6);
   
    return EXIT_SUCCESS;

}
