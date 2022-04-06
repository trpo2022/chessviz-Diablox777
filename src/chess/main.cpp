#include <iostream>
#include <string>
#include <libchess/print_board.h>

#define board_size 8

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    char chess_board[board_size][board_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    motion motion;
    printf("Для выхода из программы введите 'выход'\n");
    print_board(chess_board);
    string step;
    float number_of_turn = 1;
    bool move_white = true;
    while (true) {
        printf("%d", (int)number_of_turn);
        printf("-ый ход: ");
        number_of_turn += 0.5;
        cin >> step;
        if (step == "выход") {
            printf("Программа завершена");
            break;
        }
        if (switch_figure(step, motion, chess_board, move_white) != 0) {
            printf("Попробуйте снова");
            number_of_turn -= 0.5;
            continue;
        };
        print_board(chess_board);
        printf("\n");
    }
    return 0;
}
