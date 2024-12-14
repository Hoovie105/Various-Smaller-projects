#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
void drawTable(char[6][7]); //Helper function to draw the table in main.
bool make_move(char table[6][7], int column, char player);
bool check_win(char table[6][7], char player); 
void test_check_win(void);

int main(){
        char table[6][7]; //board
        char player[2] = {'X', 'O'}; //Player 1 is 'x'. Player 2 is 'o'.
        int column; //Player input
        int turn=0; //Selects which player goes next.
        int num_of_turns; //Used for the draw condition.
        test_check_win();
        
        for (int i = 0; i < 7; i++){
                for (int j = 0; j < 6; j++){ //Set all values on board to ' '
                        table[i][j] = ' ';
                }
        }
       
        for (num_of_turns = 0;!check_win(table, player[turn*-1+1])&&num_of_turns<42; turn = (++num_of_turns)%2){ //check for win/alternate turns.
                do {
                        printf ("Turn# %d, Player# %c, Choose a cloumn: ", num_of_turns, player[turn]);
                        scanf ("%d", &column);
                } while (column < 0 || column > 6 || ! make_move (table, column, player[turn]));          
                drawTable (table);
        }
        if (num_of_turns >= 41) printf ("\nDraw!\n\n"); //Draw condition.
        else printf ("\n%c is the victor!\n\n", player[turn*-1+1]); //Victory declaration.     
}
/*function with various win conditions.*/
bool check_win(char table[6][7], char player){
        //Vertical win case:
        for (int i = 0; i < 7; i++){
                for (int j = 0; j < 4; j++){
                        
                        if (player == table[i][j] && player == table[i][j+1] && player == table [i][j+2] && player == table [i][j+3]) return 1;
                }
        }
       
        //Horizontal win case:
         for (int j = 0; j < 6; j++){
                for (int i = 0; i < 4; i++){
                        if (player == table[i][j] && player == table[i+1][j] && player == table[i+2][j] && player == table[i+3][j]) return 1;
                }
        }
       
        //Diagonal win case:
        for (int i = 0; i < 4; i++){
                for (int j = 0; j < 3; j++){
                        
                        if (player == table[i][j] && player == table[i+1][j+1] && player == table[i+2][j+2] && player == table[i+3][j+3]) return 1;
                        if (player == table[6-i][j] && player == table[5-i][j+1] && player == table[4-i][j+2] && player == table[3-i][j+3]) return 1;
                        if (player == table[i][5-j] && player == table[i+1][4-j] && player == table[i+2][3-j] && player == table[i+3][2-j]) return 1;
                        if (player == table[6-i][5-j] && player == table[5-i][4-j] && player == table[4-i][3-j] && player == table[3-i][2-j]) return 1;
                }
        }
                   
        return 0;
}
/*drawTable is resposible for printing out the table
state at every turn change within main.*/
void drawTable(char table[6][7]){
        printf ("\n\n.0.1.2.3.4.5.6.");
        for (int j = 0; j < 6; j++){ 
               
                printf ("\n|");
                for (int i = 0; i < 7; i++){
                        printf ("%c|", table[i][j]);
                }
                if (j == 5) printf ("\n\\^.^.^.^.^.^.^/");
                else printf ("\n|-|-|-|-|-|-|-|");
        }
        printf ("\n\n");
}
/*make_move is responsible for placing the correct player tokken
in the specified location on the board.*/
bool  make_move (char table[6][7], int column, char player){
        int i = column; //makes function easier to work with.
        for (int j = 0; j < 6; j++){
                if (table[i][j] != ' ') {
                        if (j == 0) return 0; //checks if column is full.
                        table[i][j-1] = player; 
                        return 1; 
                }
        }
        table[i][5] = player; 
        return 1;
}
//test_check_win() tests the check_win function using assert; if an error is
//detected then the program stops
void test_check_win(void){

  char ATest[6][7] =  {{' ', ' ', ' ', ' ', ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',},
                       {' ', 'O', 'O', 'O', 'O', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',}
                      };
  assert(check_win(ATest, 'O'));

  char BTest[6][7]=  {{' ', ' ', ' ', ' ',  ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', 'X', ' ',},
                       {' ', ' ', ' ', ' ', ' ', 'X', ' ',},
                       {' ', ' ', ' ', ' ', ' ', 'X', ' ',},
                       {' ', ' ', ' ', ' ', ' ', 'X', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',}
                      };
  assert(check_win(BTest, 'X'));

  char CTest[6][7] =  {{' ', ' ', ' ', ' ', ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', 'O', ' ', ' ',},
                       {' ', ' ', ' ', 'O', ' ', ' ', ' ',},
                       {' ', ' ', 'O', ' ', ' ', ' ', ' ',},
                       {' ', 'O', ' ', ' ', ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',}
                      };
  assert(check_win(CTest, 'O'));
    
  char DTest[6][7] =  {{'X', ' ', ' ', ' ', ' ', ' ', ' ',},
                       {' ', 'X', ' ', ' ', ' ', ' ', ' ',},
                       {' ', ' ', 'X', ' ', ' ', ' ', ' ',},
                       {' ', ' ', ' ', 'X', ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ',}
                      };
  assert(check_win(DTest, 'X'));

  char ETest[6][7] =  {{'O', 'X', 'O', 'O', 'O', 'X', 'O',},
                       {'X', 'O', 'X', 'X', 'X', 'O', 'X',},
                       {'O', 'X', 'O', 'O', 'O', 'X', 'O',},
                       {'X', 'O', 'X', 'X', 'X', 'O', 'X',},
                       {'O', 'X', 'O', 'O', 'O', 'X', 'O',},
                       {'X', 'O', 'X', 'X', 'X', 'O', 'X',}
                      };
  assert(check_win(ETest, 'O') == false);
  assert(check_win(ETest, 'X') == false);

  printf("All check_win tests passed. \n");
}
