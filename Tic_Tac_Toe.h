#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H






void voidDrawBoard(char *Grid);


void voidGetPlayersChoice(char * Grid , char PlayerSymbol);

char SelectPlayerSymbol(void);


bool boolCheckForWinner(char* Grid);


bool boolCheckForDraw(char* Grid);

void voidStartGame(void);

#endif 
