#include <iostream>

using namespace std;

char board[3][3]={{'1','2','3'},
                  {'4','5','6'},
                  {'7','8','9'}};
char curMarker;
int player;

void drawBoard()
{
    cout<<" -------------"<<endl;
    cout<<" | "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" | "<<endl;
    cout<<" -------------"<<endl;
    cout<<" | "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" | "<<endl;
    cout<<" -------------"<<endl;
    cout<<" | "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" | "<<endl;
    cout<<" -------------"<<endl;
}
bool placeMarker(int slot)
{
    int row=slot/3;
    int col;

    if (slot%3==0)
    {
        row=row-1;
        col=2;
    }
    else col = (slot%3)-1;

    if (board[row][col] != 'x' && board[row][col] != 'o') {
        board[row][col] = curMarker;
        return true;
    }
    else
        return false;

}

char winner()
{
    for (int i=0; 1<3; i++)
    {
        //row
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return player;
        //col
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return player;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return player;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return player;

    return 0;
}

void swapPlayer()
{
    if (curMarker == 'x')
        curMarker = 'o';

    else curMarker = 'x';

    if (player == 1)
        player =2;

    else player = 1;

}

void game()
{
    int playerWon;
    char markerP1;
    cout<<"player one choose marker: ";
    cin>>markerP1;

    player = 1;
    curMarker = markerP1;

    drawBoard();

    for (int i=0; i<9; i++)
    {
        int slot;
        cout << "it's player "<<player<<"'s turn. Enter your slot: ";
        cin >> slot;

       if (!placeMarker(slot))
       {
           cout<<"That slot is occupied! try another slot";
           i--;
           continue;
       }
        drawBoard();

        playerWon = winner();

        if (playerWon == 1) {cout << "player one won! Congrats you win!";
        break;
        }
        if (playerWon == 2) {cout << "player two won! Congrats you win!";
            break;
        }

        swapPlayer();
        drawBoard();
    }
    if (playerWon == 0) cout << "wow! unbelievable!!!...Its a tie! who could've guessed...";
}

int main()
{

    game();

}
