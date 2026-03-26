// ti-tac-toe game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
using namespace std;
char board [3][3] ={{'1','2','3'},{'4','5','6'},{ '7','8','9'}};

void drawing_board() {
    cout << setw(55)<<board[0][0]<<setw(5) << "|" << setw(5) << board[0][1] << setw(5) << "|"  <<setw(5)<<board[0][2] << endl;
    cout << setw(50);
    for (int i = 0; i <= 32; i++) {
        cout << "-";
    }
    cout << "\n";
    cout << setw(55) << board[1][0] << setw(5) << "|" << setw(5) << board[1][1] << setw(5) << "|" << setw(5) << board[1][2] << endl;
    cout << setw(50);
    for (int i = 0; i <= 32; i++) {
        cout << "-";
    }
    cout << "\n";
    cout << setw(55) << board[2][0] << setw(5) << "|" << setw(5) << board[2][1] << setw(5) << "|" << setw(5) << board[2][2] << endl;
    cout << setw(50);
    for (int i = 0; i <= 32; i++) {
        cout << "-";
    }
    cout << "\n";
   
}
void gues(int slot,char mark) {
    int row, column;
    if (slot % 3 == 0) {
        column = 2;
        row = ( slot/ 3) - 1;
    }
    else if (slot % 3 == 2) {
        column = 1;
        row = slot / 3;
    }else{
        column = 0;
        row = slot / 3;


    }

	board[row][column] = mark;
}
char check_winner( int player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return player ;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return player;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return player;
    }
    return 0;
}


int main()
{
    int a;
    drawing_board();
	int player = 1;
	int player2 = 2;
	for (int i = 0; i < 9; i++) {
        if (player == 1) {
            cout << "Player 1, enter a slot number: ";
            cin >> a;
            gues(a, 'X');
            drawing_board();
            if (check_winner(player)) {
                cout << "Player 1 wins!" << endl;
                break;
            }
            player = 2;
        }
        else {
            cout << "Player 2, enter a slot number: ";
            cin >> a;
            gues(a, 'O');
            drawing_board();
            if (check_winner(player2)) {
                cout << "Player 2 wins!" << endl;
                break;
            }
            player = 1;
        }
    }
    
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
