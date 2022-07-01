#include <iostream>
#include <cstring>
using namespace std;

class Player {
    private:
        char name[100];
        vector<Card> hand;
        int sum, cash, bet, index;
        int win;

    public:
        Player(char pname[100]): hand(5) {
            strcpy(name,pname);
            index = sum = win = bet = 0;
            cash = 5000;
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

        void printName() {
            cout<<name<<endl;
        }

        bool addCard() {
            hand[index].dealCard();
            sum += hand[index].getNumber();
            index++;

            if(checkSum() == 2){
                cout<<"\nYou got busted!";
                return 0;
            } 
            else if(checkSum() == 3){
                cout<<"\nBlackjack!";
            }
            return 1;
        }

        int getSum() {
            return sum;
        }
};
