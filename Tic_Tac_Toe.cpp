#include <iostream>

#include "Tic_Tac_Toe.h"

char Grid[9] ={
    '1', '2', '3', '4', '5', '6', '7', '8', '9'
};



void voidDrawBoard(char *Grid){

    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << Grid[0] << "  |  " << Grid[1] << "  |  " << Grid[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << Grid[3] << "  |  " << Grid[4] << "  |  " << Grid[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << Grid[6] << "  |  " << Grid[7] << "  |  " << Grid[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;

}


char SelectPlayerSymbol(void) {
    char playerSymbol=0;
    std::cout << "Player 1"<<std::endl;
    std::cout << "Choose your symbol (X or O): ";
    std::cin >> playerSymbol;
    if(std::cin.fail())  /* Check if the input is valid */
    {
        std::cin.clear(); /* Clear the error flag */
        std::cin.ignore(10000, '\n'); /* Ignore invalid input */
        std::cout << "Invalid input! Please enter a valid Choice.\n";
    }
    
    
    // Ensure valid input
    while (playerSymbol != 'X' && playerSymbol != 'O') {
        std::cout << "Invalid choice. Please choose 'X' or 'O': ";
        std::cin >> playerSymbol;
    }

    return playerSymbol;
}



void voidGetPlayersChoice(char * Grid , char PlayerSymbol){

    int place;
    std::cout << "Player " << PlayerSymbol << ", select a position from 1 to 9: ";
    std::cin >> place;
    if(std::cin.fail())  /* Check if the input is valid */
    {
        std::cin.clear(); /* Clear the error flag */
        std::cin.ignore(10000, '\n'); /* Ignore invalid input */
        std::cout << "Invalid input! Please enter a valid Choice.\n";
    }
    // Check if the position is valid and available
    if (place >= 1 && place <= 9 && Grid[place - 1] == '0' + place) {
        Grid[place - 1] = PlayerSymbol; // Place the player's symbol ('X' or 'O') on the grid
    } else {
        std::cout << "Invalid move! Try again." << std::endl;
        voidGetPlayersChoice(Grid, PlayerSymbol); // Retry
    }

}

bool boolCheckForWinner(char* Grid){

    // Win conditions represented as rows, columns, and diagonals
    int Loc_intWinConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    // Loop through each win condition and check for matching symbols
    for (int i = 0; i < 8; i++) {
        if (Grid[Loc_intWinConditions[i][0]] == Grid[Loc_intWinConditions[i][1]] &&
            Grid[Loc_intWinConditions[i][1]] == Grid[Loc_intWinConditions[i][2]]) {
            return true;  // Winner found
        }
    }

    return false;  // No winner found


}


bool boolCheckForDraw(char* Grid){


    if (boolCheckForWinner(Grid)) {
        return false;
    }

    // Check if all positions are filled (no available moves)
    for (int i = 0; i < 9; ++i) {
        if (Grid[i] != 'X' && Grid[i] != 'O') {
            return false;  // If any position is still unfilled, it's not a draw
        }
    }

    // If all positions are filled and no winner, then it's a draw
    return true;

}


void voidStartGame(void){


    char Player1Symbol = SelectPlayerSymbol();
    char Player2Symbol = (Player1Symbol == 'X') ? 'O' : 'X';  // Fix to ensure case-sensitive comparison
    char Loc_PlayerWantToContinue=0;
    voidDrawBoard(Grid);

    char charCurrentPlayer = Player1Symbol;

    while (true) {
        voidGetPlayersChoice(Grid, charCurrentPlayer);
        voidDrawBoard(Grid);

        if (boolCheckForWinner(Grid)) {  // Check for a win
            std::cout << "Player " << charCurrentPlayer << " Wins!!!" << std::endl;
            break;  // End the game after a win
        }

        if (boolCheckForDraw(Grid)) {  // Check for a draw
            std::cout << "It's a draw !!" << std::endl;
            break;  // End the game after a draw
        }

        // Switch the current player
        charCurrentPlayer = (charCurrentPlayer == Player1Symbol) ? Player2Symbol : Player1Symbol;
    }
    std::cout<<"Do you Want To Play Again ?? (Y/N)"<<std::endl;
    std::cin>>Loc_PlayerWantToContinue;
    if(std::cin.fail())  /* Check if the input is valid */
    {
        std::cin.clear(); /* Clear the error flag */
        std::cin.ignore(10000, '\n'); /* Ignore invalid input */
        std::cout << "Invalid input! Please enter a valid Input.\n";
    }
    if(Loc_PlayerWantToContinue == 'Y'){
        voidStartGame();
    }
    else
    {

    }

}