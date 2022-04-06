#include <iostream>
#include <string>
#include <libchess/print_board.h>

#define board_size 8

using namespace std;

void print_board(char chess_board[board_size][board_size])
{
int i = 0, j = 0;
printf("\n");
for (i = 0; i < board_size; i++) {
cout << board_size - i << " ";
for (j = 0; j < board_size; j++) {
cout << chess_board[i][j] << " ";
}
printf("\n");
}
printf("  A B C D E F G H \n");
}

void trans(string step, motion& motion)
{
motion.vertical1 = board_size - ((int)step[1] - (int)'0');
motion.gorizontal1 = (int)step[0] - (int)'a';
motion.vertical2 = board_size - ((int)step[4] - (int)'0');
motion.gorizontal2 = (int)step[3] - (int)'a';
}

int switch_figure(
string step,
motion motion,
char chess_board[board_size][board_size],
bool& move_white)
{
char type;
trans(step, motion);
type = chess_board[motion.vertical1][motion.gorizontal1];
chess_board[motion.vertical1][motion.gorizontal1] = ' ';
chess_board[motion.vertical2][motion.gorizontal2] = type;
if (move_white == true)
move_white = false;
else
move_white = true;
return 0;
} 
