
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 3;
void drawbaord(vector<vector<char>> board){
    cout << "---------------\n"; 
    for(int i = 0 ; i < SIZE; i++){
        for(int j = 0 ; j < SIZE; j++){
            cout << " | " << board.at(i).at(j);
            if(j == 2){
                cout << " |\n";
            }
        }
        cout << "---------------\n";
    }
}

bool checkifwin(vector<vector<char>> board, char player){
    for(int i = 0 ; i< SIZE; i++){
        if(board.at(0).at(i) == player && board.at(1).at(i) == player && board.at(2).at(i) == player){
            return true;
        }
        if(board.at(i).at(0) == player && board.at(i).at(1) == player && board.at(i).at(2) == player){
            return true;
        }
    }
    if(board.at(0).at(0) == player && board.at(1).at(1) == player && board.at(2).at(2) == player){
            return true;
        }
    if(board.at(2).at(0) == player && board.at(1).at(1) == player && board.at(0).at(2) == player){
            return true;
        }
    return false;
}

int main(){
    vector<vector<char>> board = vector<vector<char>>(SIZE,vector<char>(SIZE, ' '));
    cout << "Welcome to Tic-Tac-Toe!\n";
    drawbaord(board);
    bool win = false;
    int tors = 0;
    char player = 'X';
    int row, col;
    while(!win && (tors < 9)){
        player = ((tors % 2 == 0)? 'X' : 'O');
        cout << "Player "<< player << ", enter row (0-2) and column (0-2):"; 
        while(true){
            cin >> row >> col;
            if((row < 0 || row > 2 || col < 0 || col > 2) || board.at(row).at(col) != ' ' ){
                cout << "Invalid move! try again:";
            }
            else break;
        }
        board.at(row).at(col) = player;
        win = checkifwin(board,player);
        if(win){
            cout << "Player " << player << " win!\n";
        }
        drawbaord(board);
        tors++;
    }

    return 0;
}