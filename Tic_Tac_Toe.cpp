#include <bits/stdc++.h>
using namespace std;

char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void display_matrix(string s1, string s2)
{

    // Rander Game Board LAYOUT

    cout << s1 << "  [X] \t" << s2 << "\t [O]\n\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << matrix[0][0] << "  | " << matrix[0][1] << "   |  " << matrix[0][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << matrix[1][0] << "  | " << matrix[1][1] << "   |  " << matrix[1][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << matrix[2][0] << "  | " << matrix[2][1] << "   |  " << matrix[2][2] << " \n";
    cout << "\t     |     |     \n";
}
void player_turn(string s1, string s2)
{
    if (turn == 'X')
    {
        cout << s1 << " turn [X] \n ";
    }
    else if (turn == 'O')
    {
        cout << s2 << " turn [O] \n ";
    }
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid Move" << endl;
    }
    if (turn == 'X' && matrix[row][column] != 'X' && matrix[row][column] != 'O')
    {
        matrix[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && matrix[row][column] != 'X' && matrix[row][column] != 'O')
    {
        matrix[row][column] = 'O';
        turn = 'X';
    }
    else
    {

        cout << "Box already filled!n Please choose another!\n";
        player_turn(s1,s2);
    }
    display_matrix(s1,s2);
}
bool gameover()
{
    for (int i = 0; i < 3; i++)
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] || matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            return false;

    // checking the win for both diagonal

    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] || matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
        return false;

   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j = j + 1)
        { 
            if(matrix[i][j]!='X'&&matrix[i][j]!='O')
            {
                return true;
            }
        }
    }
    draw = true;
    return false;
}
int main()
{
    cout << "\t\t\tWELCOME TO TIC-TAC-TOE GAME\n\n";
    cout << "\t\t\tTHIS IS TWO PLAYER GAME\n\n";
    string s1, s2;
    cout << "PLS ENTER NAME OF PLAYER 1 [X] \n";
    getline(cin, s1);
    cout << "PLS ENTER NAME OF PLAYER 1 [O] \n";
    getline(cin, s2);

    while (gameover())
    {
        {
            display_matrix(s1, s2);
            player_turn(s1, s2);
            gameover();
        }
    }

    if(turn == 'X' && draw == false){
        cout<<"Congratulations!\t\n"<<s2<<" with 'O' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"Congratulations!\t\n"<<s1<<" with 'X' has won the game";
    }
    else
    cout<<"\nGAME DRAW!!!\n";
}