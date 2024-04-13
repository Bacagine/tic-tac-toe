/**
 * tic_tac_toe.c
 * 
 * Written by Gustavo Bacagine in April 2024
 * 
 * Description: This program is based in the program tic tac toe of the
 * book "C Completo e Total"; 1991; pages 117-119
 */

//////////////////////////////////////////////////////////////////////
//                                                                  //
//                            Includes                              //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//////////////////////////////////////////////////////////////////////
//                                                                  //
//                             Defines                              //
//                                                                  //
//////////////////////////////////////////////////////////////////////
#define EMPTY_CHAR ' '
#define X_CHAR     'X'
#define O_CHAR     'O'

#define UNUSED(X) (void) X

//////////////////////////////////////////////////////////////////////
//                                                                  //
//                             Globals                              //
//                                                                  //
//////////////////////////////////////////////////////////////////////
char gszMatrix[3][3];

//////////////////////////////////////////////////////////////////////
//                                                                  //
//                           Prototypes                             //
//                                                                  //
//////////////////////////////////////////////////////////////////////
char chCheckByWinner(void);
void vInitMatrix(void);
void vGetPlayerMove(void);
void vGetComputerMove(void);
void vDisplayMatrix(void);

//////////////////////////////////////////////////////////////////////
//                                                                  //
//                              main                                //
//                                                                  //
//////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
  char chDone = EMPTY_CHAR;

  UNUSED(argc);
  UNUSED(argv);

  printf("It is the Tic Tac Toe.\n");
  printf("You play with the computer.\n");

  vInitMatrix();

  do {
    vDisplayMatrix();
    vGetPlayerMove();
    chDone = chCheckByWinner();
    if ( chDone != EMPTY_CHAR ) break;
    vGetComputerMove();
    chDone = chCheckByWinner();
  } while ( chDone == EMPTY_CHAR );

  if ( toupper(chDone) == X_CHAR ) printf("You win!\n");
  else {
    printf("The computer wins\n");
  }
  
  vDisplayMatrix();

  return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////
//                                                                  //
//                            Functions                             //
//                                                                  //
//////////////////////////////////////////////////////////////////////
char chCheckByWinner(void) {
  int ii = 0;

  // Check lines
  for ( ii = 0; ii < 3; ii++ ) {
    if ( gszMatrix[ii][0] == gszMatrix[ii][1] &&
          gszMatrix[ii][0] == gszMatrix[ii][2] ) {
      return gszMatrix[ii][0];
    }
  }
  
  // Check columns
  for ( ii = 0; ii < 3; ii++ ) {
    if ( gszMatrix[0][ii] == gszMatrix[1][ii] &&
          gszMatrix[0][ii] == gszMatrix[2][ii] ) {
      return gszMatrix[0][ii];
    }
  }
  
  // Check diagonals
  if ( gszMatrix[0][0] == gszMatrix[1][1] &&
        gszMatrix[1][1] == gszMatrix[2][2] ) {
    return gszMatrix[0][0];
  }

  if ( gszMatrix[0][2] == gszMatrix[1][1] &&
        gszMatrix[1][1] == gszMatrix[2][0] ) {
    return gszMatrix[0][2];
  }

  return EMPTY_CHAR;
}

void vInitMatrix(void) {
  int ii = 0;
  int jj = 0;

  for ( ii = 0; ii < 3; ii++ ) {
    for ( jj = 0; jj < 3; jj++ ) {
      gszMatrix[ii][jj] = EMPTY_CHAR;
    }
  }
}

void vGetPlayerMove(void) {
  int iX = 0;
  int iY = 0;
  
  printf("Type the coordinates to X: ");
  scanf("%d %d", &iX, &iY);
  iX--;
  iY--;

  if ( gszMatrix[iX][iY] != EMPTY_CHAR) {
    printf("Invalid position!\n");
    printf("Try again,\n");
    vGetPlayerMove();
  }
  else {
    gszMatrix[iX][iY] = X_CHAR;
  }
}

void vGetComputerMove(void) {
  int ii = 0;
  int jj = 0;

  for ( ii = 0; ii < 3; ii++ ) {
    for ( jj = 0; jj < 3; jj++ ) {
      if ( gszMatrix[ii][jj] == EMPTY_CHAR ) {
        break;
      }
    }

    if ( gszMatrix[ii][jj] == EMPTY_CHAR ) {
      break;
    }
  }

  if ( ii * jj == 9 ) {
    printf("A tie\n");
    exit(EXIT_SUCCESS);
  }
  else {
    gszMatrix[ii][jj] = O_CHAR;
  }
}

void vDisplayMatrix(void) {
  int iT = 0;

  for ( iT = 0; iT < 3; iT++ ) {
    printf(" %c | %c | %c ", gszMatrix[iT][0],
                             gszMatrix[iT][1],
                             gszMatrix[iT][2]);

    if ( iT != 2 ) {
      printf("\n---|---|---\n");
    }
  }
  putchar('\n');
}

