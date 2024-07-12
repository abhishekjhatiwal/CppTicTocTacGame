#include<iostream>
using namespace std;

char Board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row,column;
bool draw = false;

void display_board(){
    system("cls");
    cout<<"\t Tick Cross Game "<<endl;
    cout<<"\tPlayer1[X]\n \tPlayer2[O]\n";
    
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<< Board[0][0] << "   |  " <<Board[0][1]<<"  |  "<<Board[0][2]   <<endl;
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<< Board[1][0] << "   |  " <<Board[1][1]<<"  |  "<<Board[1][2]   <<endl;
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<< Board[2][0] << "   |  " <<Board[2][1]<<"  |  "<<Board[2][2]   <<endl;
    cout<<"\t\t     |     |     \n";
}

void player_turn(){
    int choice;

    if (turn == 'X')
    {
        cout<<"\n\t Player1 [X] turn : ";
    }
    if (turn == 'O')
    {
        cout<<"\n\tPlayer2 [O] trun : ";
    }
    
    
    //bool validInput = false;
    // if (turn == 'X' && Board[row][column] != 'X' && Board[row][column] != 'O')
    // {
    //     cout<<"\n\tPlayer1 [X] turn : ";
    // }
    // if(turn == 'O' && Board[row][column] != 'X' && Board[row][column] != 'O'){
    //     cout<<"\n\tPlayer2 [O] turn : ";
    // }
    // else
    // {
    //     cout<<"Box already filled!\n Please try again!\n\n";
    //     player_turn();
    // }
    
    
    cin>>choice;
    // switch (choice)
    // {
    // case 1:
    //     Board[0][0] = 'X';
    //     break;
    // case 2:
    //     Board[0][1] = 'X';
    //     break;
    // case 3:
    //     Board[0][2] = 'X';
    //     break;
    // default:
    //     cout<<"Invalid Choise "<<endl;
    //     break;
    // }

    switch (choice)
    {
        case 1:
            row=0; column = 0; break;
        case 2:
            row=0; column = 1; break;
        case 3:
            row=0; column = 2; break;
        case 4:
            row=1; column = 0; break;
        case 5:
            row=1; column = 1; break;
        case 6:
            row=1; column = 2; break;
        case 7:
            row=2; column = 0; break;
        case 8:
            row=2; column = 1; break;
        case 9:
            row=2; column = 2; break;
        
        default:
           cout<<"Invalid Choice \n"; break;
    }

    if (turn == 'X')
    {
        Board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O')
    {
        Board[row][column] = 'O';
        turn = 'X';
    }
    

    // if (Board[row][column] != 'X' && Board[row][column] != 'O') {
    //     Board[row][column] = 'X';
    //     turn = true;
    // } else {
    //     cout << "Box already filled! Please try again.\n";
    //     player_turn(); // Ask again without recursion
    // }
    // display_board();
}

bool game_over(){
    // check win
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] || Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
        {
            return false;
        }
    }
    if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] || Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0])
    {
        return false;
    }    

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != 'X' && Board[i][j] != 'O')
            {
                return true;
            }  
        }
    }
    draw = true;
    return false;
}

int main(){   

    while (game_over())
    {
        display_board();
        player_turn();
        game_over();
    }
    
    if (turn == 'X' && !draw)
    {
        cout<<"Player2 [O] Wins!! Congratulations\n";
    }
    else if (turn == 'O' && !draw)
    {
        cout<<"Player1 [X] Wins!! Congratulations\n";
    }
    else
    {
        cout<<"Game Draw!! \n";
    }
    

    return 0;
}