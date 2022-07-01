#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void clrscr() {
    system("clear");
}

class Card {
    private:
        int number;

    public:
        int getNumber() {
            return number;
        }
};

class Dealer {
    private: 
        vector<Card> cards;
        int sum;

    public:

        Dealer(): cards(5) {
            
        }
        void revealCardas(vector<Card>& copyCards) {
            cards= copyCards;
        }      

        void deal() {

        }
};

class Player {
    private:
        char name[100];
        vector<Card> cards;
        int sum, cash, bet;

    public:
        Player(char pname[100]): cards(5) {
            strcpy(name,pname);
        }

        void printName() {
            cout<<name<<endl;
            // cout<<cards.size()<<endl;
        }
};

int main() {
    clrscr();
    char name[100];
    cout << "Hello! Enter your name: ";
    cin >> name;

    Player player(name);
    player.printName();

    return 0;
}
