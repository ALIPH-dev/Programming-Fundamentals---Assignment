


// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT4L 
// Names: MUHAMMAD ZAHIN ADRI | WONG WEI HAN | ALIPH RAIHAN
// IDs: 1211101234 | 1211101999| 1211101179
// Emails: 1211101234@student.mmu.edu.my | 1211101999@student.mmu.edu.my | 1211101179@student.mmu.edu.my
// Phones: 011-63850145 | 011-31498987 | 012-5480403
// ********************************************************* 


#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;


//useless for now
class myclass 
{
  public:
    int boardsize;
    int playerinputset;
};

//default board size is 15
//player can change the size
//not implemented
int boardsizing(int playerinput)
{
    myclass one;
    if (playerinput =! 15)
    {
        one.playerinputset = playerinput;
    }
    else
    {
        one.playerinputset = 15;
    }
    return 0;
}

//to make the board work for now
const int BOARD_SIZE = 15;

char board[BOARD_SIZE][BOARD_SIZE];
int playerX, playerY;


//where the player spawns
void initBoard() 
{
    system("cls");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }

    playerX = BOARD_SIZE / 2;
    playerY = BOARD_SIZE / 2;
    board[playerX][playerY] = 'A';
}


//how the character moves
void movePlayer(char direction) 
{
    system("cls");
    board[playerX][playerY] = '.';
    if (direction == 'w' && playerX > 0) {
        playerX--;
    }
    else if (direction == 's' && playerX < BOARD_SIZE - 1) {
        playerX++;
    }
    else if (direction == 'a' && playerY > 0) {
        playerY--;
    }
    else if (direction == 'd' && playerY < BOARD_SIZE - 1) {
        playerY++;
    }
    else if (direction == 'q')
    {
        cout << "See you again! ";
        exit(0);
    }
    else
    {
        cout << "Invalid input, please enter the following input (q,w,a,s,d)" << endl;
    }
    board[playerX][playerY] = 'A';
}


//to print the board
void printBoard() 
{
    system("cls");
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


//settings
//int setting()
//{ 
//    cout << "Your board size is determined by AxA, where 'A' is your input"<<endl;
//    cout << "Enter your board size: ";
//    cin >> BOARD_SIZE;
//}


//to start the game
int startgame()
{
    initBoard();
    printBoard();

    char direction;
    int directions;
    while (true) {
        cout << "Enter 'q' to exit the game" << endl;
        cout << "Enter direction (w, a, s, d): ";
        cin >> direction;
        cout << endl;
        movePlayer(direction);
        printBoard();
        //savemovement(direction);
    }

    return 0;
}

//to uppercase
string uppercase(const string& word)
{
    string newWord = word;
    for (int i = 0; i < newWord.size(); ++i)
    {
        newWord[i] = toupper(newWord[i]);
    }
    return newWord;
}

//the main menu
int mainmenu()
{
    system("cls");
    cout << " ------------------------ " << endl;
    cout << " = Welcome to the game! = " << endl;
    cout << " -------------------------" << endl << endl;
    cout << " - Start   " << endl;
    cout << " - Load    " << endl;
    cout << " - Setting " << endl;
    cout << " - Quit    " << endl;

    string options;
    string option;
    cin >> options;
    option = uppercase(options);

    if (option == "START")
    {
        startgame();
    }
    else if (option == "LOAD") //soon to add
    {
        cout << "Under maintenance, please come back later " << endl;
        system("pause");
        mainmenu();
    }
    else if (option == "SETTINGS") //soon to add
    {
        cout << "Under maintenance, please come back later " <<endl;
        system("pause");
        mainmenu();
    }
    else if (option == "QUIT")
    {
        exit(0);
    }
    else
    {
        cout << "Please choose a setting "<<endl<<endl;
        mainmenu();
    }
    return 0;
}


//main function
int main() 
{
    mainmenu();
    //initBoard();
    //printBoard();

    //char direction;
    //int directions;
    //while (true) {
    //    cout << "Enter direction (w, a, s, d): ";
    //    cin >> direction;
    //    cout << endl;
    //    movePlayer(direction);
    //    printBoard();
    //    savemovement(direction);
    //}

    //return 0;
}
