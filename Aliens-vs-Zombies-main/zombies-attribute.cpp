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
int alienHealth = rand()%200 + 100;

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

void zombieAttributes(int noOfZombies) {
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
}
