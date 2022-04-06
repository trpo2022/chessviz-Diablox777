#include <iostream>
#include <string>

#define board_size 8

using namespace std;

struct motion {
int vertical1;
int gorizontal1;
int vertical2;
int gorizontal2;
};

void print_board(char chess_board[board_size][board_size]);

void trans(string step, motion& motion);

int switch_figure(
string step,
motion motion,
char chess_board[board_size][board_size],
bool& move_white);
