#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELDAS 5
#define CELL_MAX (CELDAS * CELDAS - 1)


void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[CELDAS][CELDAS])
{
    int cell = 0;

    print_sep(CELDAS);
    for (int row = 0; row < CELDAS; ++row) {
        for (int column = 0; column < CELDAS; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(CELDAS);
    }
}

char get_winner(char board[CELDAS][CELDAS])
{
    char winner = '-';

    unsigned int cont = 0;

    //HORIZONTALES
    for(unsigned int x=0;x<CELDAS;x++){
        
        char pivot = board[x][0];
        
        for(unsigned int y=0;y<CELDAS;y++){

            if(pivot == board[x][y] && pivot != '-'){ ++cont;}

        }

        if(cont==CELDAS){ winner = pivot; }
        cont = 0;
    }//horizontales

    //VERTICALES    
    for(unsigned int x=0;x<CELDAS;x++){

        char pivot = board[0-1][x];

        for(unsigned int y=0;y<CELDAS;y++){
            if(pivot == board[y][x] && pivot != '-'){ ++cont; }
        }

        if(cont==CELDAS){ winner = pivot; }

        cont = 0;
    }//verticales

    //DIAGONALES
    char pivot = board[0][0];
    for(unsigned int x=0;x<CELDAS;x++){
        if(pivot == board[x][x] && pivot != '-'){
            ++cont;
        }
    }//diagonales

    if(cont==CELDAS){
        winner = pivot;
        }
    cont = 0;
    //---------------------------------
    pivot = board[CELDAS-1][0];
    unsigned int y=CELDAS-1;
    for(unsigned int x=0;x<CELDAS;x++){

        if(pivot == board[y][x] && pivot != '-'){
            ++cont;
        }
        --y;
    }//diagonales

    if(cont==CELDAS){
        winner = pivot;
    }
    cont = 0;

    return winner;
}

bool has_free_cell(char board[CELDAS][CELDAS])
{
    bool free_cell = false;
    
    for(int x=0;x<CELDAS;x++){
        for(int y=0;y<CELDAS;y++){
            if(board[x][y] == '-'){
                free_cell = true;
            }
        }
    }
    return free_cell;
}

int main(void)
{
    
    char board[CELDAS][CELDAS];

    for(unsigned int x = 0; x<CELDAS;x++){
            for(unsigned int y = 0; y<CELDAS;y++){
                board[x][y] = '-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;

    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / CELDAS;
            int colum = cell % CELDAS;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }

    print_board(board);

    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    
    return 0;
}
