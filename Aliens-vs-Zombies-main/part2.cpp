//Version 1 or Part 1
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <ctime> //can remove if dont want random
using namespace std;

const int BOARD_SIZE = 15;

char board[BOARD_SIZE][BOARD_SIZE];
int playerX, playerY;
int alienHealth = rand() % 200 + 80;

vector<vector<int> > zombieStats;  //<--Zombies and their stats
class Zombies {
private:

public:
// use these to assign data to each zombie
    vector<int> attributes;
    int zombieId;
    int zombieHealth;
    int zombieAttack;
    int zombieRange;
    //constructor to pass in initial information
    Zombies(int aZombie_id, int aZombie_health, int aZombie_attack, int aZombie_range){
        zombieId = aZombie_id;
        zombieHealth = aZombie_health;
        zombieAttack = aZombie_attack;
        zombieRange = aZombie_range;
    }
};


//The stats of the zombies will be created here
//- max of zombies 9, represented by numbers
//- each zombie has a different id, attack, health and range 1-3,
//- sets the zombies attributes
void zombieAttributes(int noOfZombies) 
{
    vector<int> zombieCharacters; // Will store the stats of one zombie
    //The order vector is {id,health,attack,range} 
    for (int i = 1; i <= noOfZombies; i++){
        int zombieAttack = rand()%25 + 9;
        int zombieHealth = rand()%50 + 1;
        int zombieRange = rand()%2 + 1;
        int zombieId = i;
        Zombies zombiePower(int ZombieId, int ZombieHealth, int zombieAttack, int ZombieRange);
        zombieCharacters.push_back(zombieId);
        zombieCharacters.push_back(zombieHealth);
        zombieCharacters.push_back(zombieAttack);
        zombieCharacters.push_back(zombieRange);
    }
    zombieStats.push_back(zombieCharacters); //Will store the stats of a the whole vector in zombieCharacters to stats vectors
    for (int j=0; j < zombieCharacters.size(); j++)
    {
        cout << zombieCharacters[j] << " ";
    }
}


void movementArrows(char changeofmovement){
    //change the direction of thrust when the alien moves
    system("cls");
    board[playerX][playerY] = '.';
    if (changeofmovement == 'v') //Down
    {
    while (playerX < BOARD_SIZE - 1 && board[playerX+1][playerY] != 'r')
        {
            if (board[playerX+1][playerY] == 'v' || board[playerX+1][playerY] == '^' || board[playerX-1][playerY] == '>' || board[playerX-1][playerY] == '<' ){
                char changeofmovement = board[playerX+1][playerY];
                board[playerX][playerY] = '.';
                playerX++;
                movementArrows(changeofmovement);
                break;
            }
            else{
                board[playerX+1][playerY] = '.';
                playerX++;
            }
        }
    }
    else if (changeofmovement == '^'){ //UP
        while (playerX > 0  && board[playerX-1][playerY] != 'r')
        {
            if (board[playerX-1][playerY] == 'v' || board[playerX-1][playerY] == '^' || board[playerX-1][playerY] == '>' || board[playerX-1][playerY] == '<' ){
                char changeofmovement = board[playerX-1][playerY];
                board[playerX][playerY] = '.';
                playerX--;
                movementArrows(changeofmovement);
                break;
            }
            else{
                board[playerX][playerY] = '.';
                playerX--;
            }
        }
    }
    else if (changeofmovement == '<'){ //left
        while (playerY > 0 && board[playerX][playerY-1] != 'r')
        {
            if (board[playerX][playerY-1] == 'v' || board[playerX][playerY-1] == '^' || board[playerX][playerY-1] == '>' || board[playerX][playerY-1] == '<' ){
                char changeofmovement = board[playerX][playerY-1];
                board[playerX][playerY] = '.';
                playerY--;
                movementArrows(changeofmovement);
                break;
            }
        else{
             board[playerX][playerY] = '.';
            playerY--;
            }
        }
    }
    else if (changeofmovement == '>'){ //right
        while (playerY < BOARD_SIZE - 1 && board[playerX][playerY+1] != 'r')
        {
            if (board[playerX][playerY+1] == 'v' || board[playerX][playerY+1] == '^' || board[playerX][playerY+1] == '>' || board[playerX][playerY+1] == '<' ){
                char changeofmovement = board[playerX][playerY+1];
                board[playerX][playerY] = '.';
                playerY++;
                movementArrows(changeofmovement);
                break;
            }
        else{
            board[playerX][playerY] = '.';
            playerY++;
            }
        }
    

    }
    //must also allow to change the arrow navigation
    //i is row, j is column
}

void alienHealthdisplay(int alienHealth){
    cout << endl;
    cout << "ALIENS HEALTH:   " << alienHealth << endl;
}

void alien_Health(bool healthPod){
    if (healthPod == true){
        int alienHealth = alienHealth + 20;
        alienHealthdisplay(alienHealth);
    }
}

//save and load functions
void saveData() {
    ofstream outputFile("data.txt");

    if (outputFile.is_open()) {
        outputFile << "Some data to save" << endl;
        outputFile.close();
        cout << "Data saved successfully" << endl;
    }
    else {
        cout << "Error: Unable to open file for writing" << endl;
    }
}

void loadData() {
    ifstream inputFile("data.txt");

    if (inputFile.is_open()) {
        string data;
        while (getline(inputFile, data)) {
            cout << data << endl;
        }
        inputFile.close();
        cout << "Load Successfully "<<endl;
    }
    else {
        cout << "Error: Unable to open file for reading" << endl;
    }
}

//where the player spawns
void initBoard() 
{
    system("cls");
    char gameObj[] = {'v','^','>','<','h','p','r',' ',' ',' '}; //1-10
    int noofgameObj = 10;
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            int chooseGameObject = rand() % noofgameObj;
            board[i][j] = gameObj[chooseGameObject];
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
    if (direction == 'w' && playerX > 0) 
    {
        while (playerX > 0  && board[playerX-1][playerY] != 'r')
        {
            if (board[playerX-1][playerY] == 'v' || board[playerX-1][playerY] == '^' || board[playerX-1][playerY] == '>' || board[playerX-1][playerY] == '<' ){
                char changeofmovement = board[playerX-1][playerY];
                board[playerX][playerY] = '.';
                playerX--;
                movementArrows(changeofmovement);
                break;
            }
            else{
                board[playerX][playerY] = '.';
                playerX--;
            }
        }
    }
    else if (direction == 's' && playerX < BOARD_SIZE - 1) 
    {
        while (playerX < BOARD_SIZE - 1 && board[playerX+1][playerY] != 'r')
        {
            if (board[playerX+1][playerY] == 'v' || board[playerX+1][playerY] == '^' || board[playerX-1][playerY] == '>' || board[playerX-1][playerY] == '<' ){
                char changeofmovement = board[playerX+1][playerY];
                board[playerX][playerY] = '.';
                playerX++;
                movementArrows(changeofmovement);
                break;
            }
            else{
                board[playerX+1][playerY] = '.';
                playerX++;
            }
        }
    }
    else if (direction == 'a' && playerY > 0) 
    {
        while (playerY > 0 && board[playerX][playerY-1] != 'r')
        {
        if (board[playerX][playerY-1] == 'v' || board[playerX][playerY-1] == '^' || board[playerX][playerY-1] == '>' || board[playerX][playerY-1] == '<' ){
                char changeofmovement = board[playerX][playerY-1];
                board[playerX][playerY] = '.';
                playerY--;
                movementArrows(changeofmovement);
                break;
            }
        else{
             board[playerX][playerY] = '.';
            playerY--;
            }
        }
    }
    else if (direction == 'd' && playerY < BOARD_SIZE - 1) 
    {
        while (playerY < BOARD_SIZE - 1 && board[playerX][playerY+1] != 'r')
        {
        if (board[playerX][playerY+1] == 'v' || board[playerX][playerY+1] == '^' || board[playerX][playerY+1] == '>' || board[playerX][playerY+1] == '<' ){
                char changeofmovement = board[playerX][playerY+1];
                board[playerX][playerY] = '.';
                playerY++;
                movementArrows(changeofmovement);
                break;
            }
        else{
            board[playerX][playerY] = '.';
            playerY++;
            }
        }
    }
    else if (direction == 'q')
    {
        cout << "Do you want to save?(y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'y')
        {
            saveData();
        }
        else if(answer == 'n')
        {
            cout << "Are you sure you want to quit without saving?(y/n): ";
            char answer2;
            cin >> answer2;
            if (answer2 == 'y')
            {
                exit(0);
            }
            else if (answer2 == 'n')
            {
                saveData();
            }
        }
        else
        {
            cout << "Invalid input, please enter the following input (y/n)";
        }
    }
    else if (direction == 'e')
    {
        saveData();
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
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


//to start the game
int startgame()
{
    initBoard();
    printBoard();

    char direction;
    int directions;
    while (true) {
        alienHealthdisplay(alienHealth);
        cout << "Enter 'q' to exit the game" << endl;
        cout << "Enter 'e' to save the game" << endl;
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
    int number;
    cin >> options;
    option = uppercase(options);

    if (option == "START")
    {
        startgame();
    }
    else if (option == "LOAD") //soon to add
    {
        //cout << "Under maintenance, please come back later " << endl;
        loadData();
        system("pause");
        mainmenu();
    }
    else if (option == "SETTING") //soon to add
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
    srand(time(NULL)); //can be remove if dont want random
    mainmenu();

}
