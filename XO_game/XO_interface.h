/***********************************************************************************/
/* Author    : Mustafa Mohammed Abdou                                              */
/* Date      : 26 Mar 2023                                                         */
/* Version   : V01                                                                 */
/* Hint      : prootypes of XO functions                                           */
/***********************************************************************************/

/* HEADER FILE GUARD */
#ifndef XO_INTERFACE_H
#define XO_INTERFACE_H


/* MACROS TO BE USED FOR REDABILITY */
#define player1  1
#define player2  2



/* FUNCTION TO DRAW THE BOARD TO PLAYERS    */
/* ARGUMENTS  : ARRAY OF CHAR (BOARD)       */
/* RETURN     : VOID                        */
void drawBoard(uint8_t* board);


/* FUNCTION TO UPDATE THE BOARD AFTER EACH PLAY      */
/* ARGUMENTS   : ARRAY OF CHAR(BOARD) , THE POSITION TO UPDATE IT , THE VALUE FOR THE PREVIOUS POSITION (X , O) */
/* RETURNS     : VOID                                */
void updateBoard(uint8_t* board, uint8_t position, uint8_t value);


/* FUNCTION THAT SCAN THE SYMBOL OF EACH PLAYER WHEN HE ATTEMPT TO PLAY                                   */
/* ARGUMENTS   : PLAYER NUMBER , PLAYER SYMBOL                                                            */
/* RETURNS     : 0 WHEN THE SYMBOL HADN'T BEEN CHOOSEN BEFORE / 1 WHEN THE SYMBOL HAD BEEN CHOOSEN BEFORE */
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol);


/* FUNCTION TO ENABLE EACH PLAYER TO CHOOSE HIS OWN SYMBOL        */
/* ARGUMENTS  : ARRAY OF TWO ELEMENTS WILL BE FILLED WITH SYMBOLS */
/* RETURNS    : VOID                                              */
void setPlayerConfig(uint8_t* configArray);


/* FUNCTION TO UPDATE PLAYER STATUS ON THE BOARD */
/* ARGUMENTS   : PLAYER'S NUMBER                 */
/* RETURN      : JUST UPDATE THE SELECTED POSITION BY PLAYER'S SYMBOL */
void loadAndUpdate(uint8_t playerNumber);



/* FUNCTION TO CHECK THE STATUS OF PLAYERS AFTER EACH MOVE */
/* ARGUMENTS THE BOARD AND GAME STATE THAT HOLDS THE STATE */
/* GAME STATE = 0 OR 1 OR 2                                */
/* RETURNS VOID                                            */
void getGameState(uint8_t* board, uint8_t* gameState);




#endif 






