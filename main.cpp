#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int randomize();

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

        void dealCard() {
            number = (rand()%13)+1;
        }
};

class Dealer {
    private: 
        vector<Card> cards;
        int sum, index, win;

    public:
        Dealer(): cards(5) {
            sum=0; index=0; win=0;    
        }
        
        int checkSum() {
            if(sum > 21) {
                win = 2;
            }
            if(sum == 21) {
                win = 3;
            }
            return win;
        }

        bool addCard() {
            cards[index].dealCard();
            sum += cards[index].getNumber();
            index++;

            if(checkSum() == 2) {
                cout<<"\n Dealer lost!";
                return 0;
            }
            return 1;
        }

        int getSum() {
            return sum;
        }


};

class Player {
    private:
        char name[100];
        vector<Card> cards;
        int sum, cash, bet, index;
        int win;

    public:
        Player(char pname[100]): cards(5) {
            strcpy(name,pname);
            index = sum = win = 0;
            cash = 5000;
        }

        int checkSum() {
            if(sum > 21) {
                win = 2;
            }
            return win;
        }

        void printName() {
            cout<<name<<endl;
        }

        bool addCard() {
            cards[index].dealCard();
            sum += cards[index].getNumber();
            index++;

            if(checkSum() == 2){
                cout<<"\nYou lost!";
                return 0;
            } 
            return 1;
        }

        int getSum() {
            return sum;
        }
};

// deal card for both
void deal(Player &p1, Dealer &d1) {
    bool player = p1.addCard();
    bool dealer;
    if(d1.getSum() < 19){
        dealer = d1.addCard();
    }
}

int main() {
    clrscr();
    char name[100];
    cout << "Hello! Enter your name: ";
    cin >> name;

    Player player(name);
    // player.printName();
    
    Dealer dealer;
    clrscr();
    cout<<"Hello! "; player.printName();
    
    char choice, quit='n';
    while(quit!='Y' and quit!='y') {
        cout<<"\nDeal card? (Enter d/D): "; cin>>choice;
        switch(choice) {
            case 'd':
            case 'D': deal(player,dealer);
        }
        cout<<player.getSum();
        cout<<"\nQuit? (y/n): ";
        cin>>quit;
    }

    return 0;
}
