// Anthony Licea
// Assignment #9

#include <iostream>
#include <string>
using namespace std;

struct Player
{
    string playerName;
    char playerMark;
};
const int rows = 3;
const int cols = 3;
void getplayerOne(Player *);
void getplayerTwo(Player *);
void displayTurn(char [][cols], int, Player *);
void getplayerInput(char [][cols], int, Player &);
string winCondition(char[][cols], int, Player *);
void displayFinal(char[][cols], int);


int main() {
    Player playerOne;
    Player playerTwo;
    char tictactoeArray[rows][cols] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int moveNumber = 1;
    
    getplayerOne(&playerOne);
    cin.ignore();
    getplayerTwo(&playerTwo);
    
    cout << endl;
    cout << playerOne.playerName << " starts." << endl;
    
    displayTurn(tictactoeArray, rows, &playerOne);
    getplayerInput(tictactoeArray, rows, playerOne);
    
    while (moveNumber < 9)
    {
        moveNumber++;
        displayTurn(tictactoeArray, rows, &playerTwo);
        getplayerInput(tictactoeArray, rows, playerTwo);
        if (winCondition(tictactoeArray, rows, &playerTwo) == playerTwo.playerName)
        {
            cout << playerTwo.playerName << " is the winner!\n";
            break;
        }
        moveNumber++;
        displayTurn(tictactoeArray, rows, &playerOne);
        getplayerInput(tictactoeArray, rows, playerOne);
        if (winCondition(tictactoeArray, rows, &playerOne) == playerOne.playerName)
        {
            cout << playerOne.playerName << " is the winner!\n";
            break;
        }
        else if (moveNumber == 9)
        {
            cout << "It is a draw\n";
        }
    }
    
    displayFinal(tictactoeArray, rows);
    
    system("pause");
    return 0;
}

void getplayerOne(Player *firstPlayer)
{
    cout << "Name for player 1: ";
    getline(cin, firstPlayer->playerName);
    cout << "Choose a mark (A-Z) : ";
    cin.get(firstPlayer->playerMark);
}

void getplayerTwo(Player *secondPlayer)
{
    cout << "Name for player 2: ";
    getline(cin, secondPlayer->playerName);
    cout << "Choose a mark (A-Z) : ";
    cin.get(secondPlayer->playerMark);
}

void displayTurn(char matrix[][cols], int row, Player *player)
{
    cout << player->playerName << "'s (" << player->playerMark << ") turn" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "[" << matrix[i][j] << "] ";
        }
        cout << endl;
    }
}

void getplayerInput(char matrix[][cols], int row, Player &player)
{
    int numberField;
    cout << "Select a field (1-9): ";
    cin >> numberField;
    while ((numberField < 1) || (numberField > 9))
    {
        cout << "Error, please reenter a value between 1 and 9\nSelect a field (1-9): ";
        cin >> numberField;
    }
    
    if (numberField == 1)
    {
        if (matrix[0][0] == '1')
        {
            matrix[0][0] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
        
    }
    else if (numberField == 2)
    {
        if (matrix[0][1] == '2')
        {
            matrix[0][1] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    else if (numberField == 3)
    {
        if (matrix[0][2] == '3')
        {
            matrix[0][2] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    else if (numberField == 4)
    {
        if (matrix[1][0] == '4')
        {
            matrix[1][0] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    else if (numberField == 5)
    {
        if (matrix[1][1] == '5')
        {
            matrix[1][1] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    else if (numberField == 6)
    {
        if (matrix[1][2] == '6')
        {
            matrix[1][2] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    else if (numberField == 7)
    {
        if (matrix[2][0] == '7')
        {
            matrix[2][0] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    else if (numberField == 8)
    {
        if (matrix[2][1] == '8')
        {
            matrix[2][1] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    else if (numberField == 9)
    {
        if (matrix[2][2] == '9')
        {
            matrix[2][2] = player.playerMark;
        }
        else
        {
            cout << "Field is already in use, try again\n";
            getplayerInput(matrix, rows, player);
        }
    }
    cout << endl;
}

string winCondition(char matrix[][cols], int rows, Player *player)
{
    if ((matrix[0][0] == player->playerMark) && (matrix[0][1] == player->playerMark) && (matrix[0][2] == player->playerMark))
    {
        return player->playerName;
    }
    if ((matrix[1][0] == player->playerMark) && (matrix[1][1] == player->playerMark) && (matrix[1][2] == player->playerMark))
    {
        return player->playerName;
    }
    if ((matrix[2][0] == player->playerMark) && (matrix[2][1] == player->playerMark) && (matrix[2][2] == player->playerMark))
    {
        return player->playerName;
    }
    if ((matrix[0][0] == player->playerMark) && (matrix[1][0] == player->playerMark) && (matrix[2][0] == player->playerMark))
    {
        return player->playerName;
    }
    if ((matrix[0][1] == player->playerMark) && (matrix[1][1] == player->playerMark) && (matrix[2][1] == player->playerMark))
    {
        return player->playerName;
    }
    if ((matrix[0][2] == player->playerMark) && (matrix[1][2] == player->playerMark) && (matrix[2][2] == player->playerMark))
    {
        return player->playerName;
    }
    if ((matrix[0][0] == player->playerMark) && (matrix[1][1] == player->playerMark) && (matrix[2][2] == player->playerMark))
    {
        return player->playerName;
    }
    if ((matrix[2][0] == player->playerMark) && (matrix[1][1] == player->playerMark) && (matrix[0][2] == player->playerMark))
    {
        return player->playerName;
    }
    else
    {
        return "no win";
    }
}

void displayFinal(char matrix[][cols], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "[" << matrix[i][j] << "] ";
        }
        cout << endl;
    }
}

