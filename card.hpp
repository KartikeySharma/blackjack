#include <iostream>

class Card {
    private:
        int number;
        char ace;

    public:
        int getNumber() {
            return number;
        }

        void dealCard() {
            int val = (rand()%13) + 1;
            switch(val) {
                case 11:
                case 12:
                case 13: number=10; break;
                default: number=val;
            }
        }

        void aceSwitch(bool up) {
            if(up) number=11;
            else number=1;
        }
};