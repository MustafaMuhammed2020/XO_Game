/***********************************************************************************/
/* Author    : Mustafa Mohammed Abdou                                              */
/* Date      : 26 Mar 2023                                                         */
/* Version   : V01                                                                 */
/* Hint      : implementation of XO game functions                                 */
/***********************************************************************************/
#include"standard_types.h"

#include"XO_interface.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS


#include<stdio.h>
#include<ctype.h>



extern boardnumbers[9];                      /* EXTERN THE BOARD FROM main.c */

uint8_t configurationArray[2] = { 0,0 };     /* GLOBAL ARRAY EXTERNED FROM main.c */




void drawBoard(uint8_t* board)
{
	/* PRINT NUMBERS FROM 1 TO 9 AS MATRIX 3*3  */
	printf("\t%c\t%c\t%c\n\t%c\t%c\t%c\n\t%c\t%c\t%c\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);

}

void updateBoard(uint8_t* board, uint8_t position, uint8_t value)
{
	/* UPDATE THE PASSED POSITION BY THE PASSED VALUE  */
	board[position] = value;
}


uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol)
{
	uint8_t returnstatus = 0, character1 = 0, character2 = 0, row , validsymbol = 0 ; /* VARIABLE TO HOLD THE RETURN STATUS OF THE FUNCTION */

	/* SWITCH CASE TO SWITCH BETWEEN THE TWO PLAYERS */
	switch (playerNumber)
	{
	case 1: /* PLAYER 1 */

		do
		{
			/* ASK PLAYER 1 TO CHOOSE HIS SYMBOL */
			printf("Player %d please choose your symbol between X and O \n", playerNumber);
			scanf("%c", &character1);

			*symbol = character1;

			scanf("%c", &row); /* PADDING FOR scanf() */


			if (character1 == 'X' || character1 == 'x') /* UPPER AND LOWER CASE ARE BOTH ACCEPTED */
			{
				validsymbol = 1;
			}
			else if (character1 == 'O' || character1 == 'o')
			{
				validsymbol = 1;
			}
			else
				validsymbol = 0; /* SCANNED VARIABLE IS NOT VALID */

		} while (!validsymbol ); /* REPEAT UNTILL THE SCANNED SYMBOL IS VALID */
		
		validsymbol = 0; /* INITIALIZE THE VARIABLE TO 0  BECAUSE IT WILL BE USED IN PLAYER 2 SCANING */

		configurationArray[0] = *symbol; /* STORE THE SCANNED SYMBOL IN THE PASSED ARGUMENT */

		if (configurationArray[0] == 'X' || configurationArray[0] == 'x')      /* WHEN THE SYMBOL ISN'T X UPPER / LOWER CASE */
		{
			returnstatus = 0; /* THIS MEANS THE PLAYER SELECTED X */

		}

		else if (configurationArray[0] == 'O' || configurationArray[0] == 'o')      /* SYMBOL IS'T O ALSO UPPER / LOWER CASE */
		{
			returnstatus = 0; /* THIS MEANS THE PLAYER SELECTED O */

		}
		
		else /* SYMBOL IS NOT VALID  */
		{
			returnstatus = 1;              /* RETURN STATUS WILL BE 1 WHEN THE PLAYER SELECT ANY SYMBOL UNLESS X , O */
			configurationArray[0] = '0';   /* RECHANGE configurationArray[0] TO '0' */

		}
		
	    break; /* BREAK CASE1 */

	case 2: /* PLAYER 2 */
		do
		{
			/* ASK PLAYER 1 TO CHOOSE HIS SYMBOL */
			printf("Player %d please choose your symbol between X and O \n", playerNumber);
			scanf("%c", &character2);

			scanf("%c", &row); /* PADDING FOR scanf() */

			*symbol = character2; /* STORE THE SCANNED CHARACTER */

		
			if (character2 == 'X' || character2 == 'x') /* UPPER AND LOWER CASE ARE BOTH ACCEPTED */
			{
				validsymbol = 1;
			}

			else if (character2 == 'O' || character2 == 'o')
			{
				validsymbol = 1;
			}
			else
				validsymbol = 0;

		} while (!validsymbol); /* REPEAT UNTILL THE SCANNED SYMBOL IS VALID */


		configurationArray[1] = *symbol ;   /* STORE THE SYMBOL SCANNED FROM USER */

		if (configurationArray[1] == 'X' || configurationArray[1] == 'x')        /* WHEN THE SYMBOL ISN'T X UPPER / LOWER CASE */
		{
			if (configurationArray[0] == 'X' || configurationArray[0] == 'x') /* MEANS THAT PLAYER 2 SELECTED THE SAME SYMBOL AS PLAYER 1 */
			{
				printf("Sorry this symbol was selected by player 1 you will play as O\n");
				configurationArray[1] = 'O';    /* SET PLAYER 2 AS X  */
				returnstatus = 0;               /* RETURN STATUS IS 0 */

			}
			else /* THAT MEANS PLAYER 2 SELECTED X UNSIMILAR TO PLAYER1 */
			{
				returnstatus = 0 ;               /* RETURN STATUS IS 0 */
			}
	 	}

		else if (configurationArray[1] == 'O' || configurationArray[1] == 'o')    /* SYMBOL IS'T O ALSO UPPER / LOWER CASE */
		{
			if (configurationArray[0] == 'O' || configurationArray[0] == 'o')  /* THIS MEANS PLAYER 2 SELECTED THE SAME SYMBOL AS PLAYER 1 */
			{
				printf("Sorry this symbol was selected by player 1 you will play as X\n");
				configurationArray[1] = 'X';   /* SET PLAYER 2 AS X  */
				returnstatus = 0;               /* RETURN STATUS IS 0 */

			}
			else
			{
				returnstatus = 0 ;              /* RETURN STATUS WILL BE 0 */
			}
		}
		
		break; /* BREAK CASE2 */

	default:
		/* WHEN NUMBER OF PLAYER NOT 1 OR 2 */
		printf("This player number is not valid \n");
		returnstatus = 1;

		break;
	}

	return returnstatus; /* RETURN STATUS */
	
 }
  
	

void setPlayerConfig(uint8_t* configArray)
{
	uint8_t player1status = 0, player2status = 0, Player1symbol = 0, player2symbol = 0; /* WIL HOLD THE RETURN FROM getPlayerSymbol FOR PLAYER 1 AND PLAYER 2 */


	player1status = getPlayerSymbol(player1, &Player1symbol); /* VALIDATE THE SCANNED SYMBOL */

	if (!player1status) /* THAT WILL BE TRUE ONLY IF THE SYMBOL IS VALID ( TRUE AND NOR REPEATED ) */
	{
		configArray[0] = configurationArray[0]; /* SET THE SYMBL OF PLAYER1 IN THE INDEX 0 OF ARRAY */
	}


	player2status = getPlayerSymbol(player2, &player2symbol); /* VALIDATE THE SCANNED SYMBOL */

	if (!player2status) /* THAT WILL BE TRUE ONLY IF THE SYMBOL IS VALID ( TRUE AND NOR REPEATED ) */
	{
		configArray[1] = configurationArray[1]; /* SET THE SYMBL OF PLAYER1 IN THE INDEX 0 OF ARRAY */
	}

	/* PRINT MESSAGE FOR PLAYERS ABOUT LASTEST CONFIGURATION */
	printf("\n Configuration set as player1 : %c   , player2 : %c\n", configArray[0], configArray[1]);

}


void loadAndUpdate(uint8_t playerNumber)
{
	uint8_t playerposition = 0 , positionstatus = 0 ; /* TO HOLD THE SCANNED POSITION FROM THE PLAYER */

	static uint8_t positions[9] = { '1','1','1','1','1','1','1','1','1' }; /* ARRAY TO HOLD THE USED POSITIONS */

	do
	{
		printf("player %d select your next position\n", playerNumber); /* SCAN THE POSITION FROM PLAYER */
		scanf("%d", &playerposition);
   
		if (positions[playerposition] == '1' )  /* THE POSITION STILL FREE */
		{
			
			positions[playerposition] = '0'; /* UPDATE THE POSITION STATUS */

			positionstatus = 1;                 /* POSITION IS AVAILABLE */

		}
		
		else /* POSITION IS NOT FREE */
		{
			printf("THIS POSITION NOT FREE TRY AGAIN \n");
			positionstatus = 0;  /* POSITION IS NOT AVAILABLE */
		}

	} while (!positionstatus); /* LOOP UNTIL THE SCANNED POSITION IS VALID */
	

	if (playerposition >= 0 && playerposition <= 8) /* POSITION IS TRUE */
	{
		if (playerNumber == 1) /* PLAYER 1 WHO PLAYED THIS POSITION */
		{
			updateBoard(boardnumbers, playerposition, configurationArray[0]); /* UPDATE THE POSITION BY PLAYER1 SYMBOL */
		}

		else if (playerNumber == 2) /* PLAYER 2 WHO PLAYED THIS POSITION */
		{
			updateBoard(boardnumbers, playerposition, configurationArray[1]); /* UPDATE THE POSITION BY PLAYER2 SYMBOL */
		}
	}
	else
	{
		printf("choose position between 0 and 9\n");
	}

	printf("\n\n");
	drawBoard(boardnumbers); /* DISPLAY THE BOARD AFTER EACH UPDATE */
}


void getGameState(uint8_t* board, uint8_t* gameState)
{
	/* CHECK IF THERE IS WINNER OR CONTINUE TO THE NEXT MOVE */
	if (((board[0] == board[4]) && (board[0] == board[8])))     /* DIAGONAL  1 */
	{
			*gameState = 0;
	}

	else if (((board[3] == board[4]) && (board[3] == board[5])))/* ROW 2 */
	{
			*gameState = 0;
	}

	else if (((board[6] == board[7]) && (board[6] == board[8]) )) /* ROW 3 */
	{
			*gameState = 0;
	}

	else if (((board[0] == board[3]) && (board[0] == board[6])))  /* COLOUMN 1 */
	{

			*gameState = 0;
	}

	else if (((board[1] == board[4]) && (board[1] == board[7]) )) /* COLOUMN 2 */
	{
			*gameState = 0;
	}

	else if ( ((board[2] == board[5]) && (board[2] == board[8])) ) /* COLOUMN 3 */
	{
			*gameState = 0;
	}

	else if ( ((board[2] == board[4]) && (board[2] == board[6]) )) /* DIAGONAL 2  */
	{

			*gameState = 0; 
	}

	else if ( ((board[0] == board[1]) && (board[0] == board[2]))) /* ROW 1 */
	{
			*gameState = 0;
	}

	else /* DRAW STATE */
	{
		*gameState = 1;
	}
}







