#include <iostream>
using namespace std;

class Dealer {
    private: 
        vector<Card> hand;
        int sum, index, win;

    public:
        Dealer(): hand(5) {
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
            hand[index].dealCard();
            sum += hand[index].getNumber();
            index++;

            if(checkSum() == 2) {
                cout << "\n Dealer busted (Sum: " << getSum() << ")\n";
                return 0;
            }
            else if(checkSum() == 3){
                cout << "Blackjack!";
                return 0;
            }
            return 1;
        }

        int getSum() {
            return sum;
        }


};