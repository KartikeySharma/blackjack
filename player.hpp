#include <iostream>
#include <cstring>
using namespace std;

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
            if(checkSum() == 3){
                cout<<"\nBlackjack!";
            }
            return 1;
        }

        int getSum() {
            return sum;
        }
};
