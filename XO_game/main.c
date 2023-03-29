/***********************************************************************************/
/* Author    : Mustafa Mohammed Abdou                                              */
/* Date      : 26 Mar 2023                                                         */
/* Version   : V01                                                                 */
/* Hint      : application layer of XO game                                        */
/***********************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS


#include<stdio.h>

#include"standard_types.h"

#include"XO_interface.h"


uint8_t boardnumbers[] = { '0','1','2','3','4','5','6','7','8' }; /* BOARD CHARACTERS */


void main(void)
{
	uint8_t  iterator, gamestate = 0 ;    /* ITERATOR INSIDE FOR LOOP AND gamestate TO HOLD THE RETURN FROM GAME STATE FUNCTION */

	uint8_t configrArr[] = { '0' ,'0' };  /* ARRAY TO HOLD CONFIGURATION OF PLAYERS */

	
	
		setPlayerConfig(configrArr); /* SET CONFIGURATIONS OF EACH PLAYER */

		while (configrArr[0] == '0' || configrArr[1] == '0'); /* HOLD HERE IF ANY OF THE SYMBOLS IS INVALID */

		drawBoard(boardnumbers); /* DISPLAY THE BOARD AT THE BEGINNING */

		/* FOR LOOP COSISTS OF 9 ATTEMPTS (ONE FULL GAME) */
		for (iterator = 1; iterator <= 9; iterator++)
		{
			if (iterator % 2 == 0)       /* PLAYER 2 TURN */
			{
				loadAndUpdate(player2);  /* UPDATE THE BOARD BY THE LAST PLAY */

				getGameState(boardnumbers, &gamestate); /* GET THE STATUS AFTER EACH UPDATE */

				if (gamestate == 0) /* PLAYER ONE IS WINNER */
				{
					printf("\n player 2 is the winner\n ");
					break;
				}
			}

			else if (iterator % 2 == 1)  /* PLAYER 1 TURN */
			{
				loadAndUpdate(player1);  /* UPDATE THE BOARD BY THE LAST PLAY */

				getGameState(boardnumbers, &gamestate); /* GET THE TATUS AFTER EACH UPDATE */

				if (gamestate == 0) /* PLAYER 2 IS WINNER */
				{
					printf("\n player 1 is the winner\n ");
					break;
				}

			}

		}

		if (gamestate == 1) /* DRAW STATUS */
			printf("Final result : draw\n");

          while(1)
		  {

	      }
	
	
}