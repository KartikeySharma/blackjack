#include <iostream>
#include <cstring>
#include <vector>

#include <fstream>
#include <ctime>

#include "card.hpp"
#include "player.hpp"
#include "dealer.hpp"

using namespace std;

void clrscr() {
    system("clear");
}

// deal card for both
bool deal(Player &p1, Dealer &d1) {
    bool player = p1.addCard();
    bool dealer;
    if(d1.getSum() < 18){
        dealer = d1.addCard();
    }
    return (player && dealer);
}

int main() {
    clrscr();
    srand(time(NULL));

    char name[100];
    cout << "Hello! Enter your name: ";
    cin >> name;

    Player player(name);
    Dealer dealer;

    clrscr();
    cout<<"Hello! "; player.printName();
    
    char choice, hit='Y';
    bool status;

    while(hit!='N' and hit!='n') {
        status = deal(player,dealer);
        cout<<"\nYou hold: "<<player.getSum();
        cout<<"\nDealer holds: "<<dealer.getSum();
        if(status){
            cout<<"\nHit? : "; cin>>hit;
        }
        else {
            cout<<"\nGame ended.";
            break;
        }
    }

    if(status) {
        if(dealer.getSum() > player.getSum()) {
            cout<<"\nDealer wins";
        }
        else if(dealer.getSum() == player.getSum()) {
            cout<<"\nNeutral";
        }
        else{
            cout<<"\nYou win!";
        }
    }

    return 0;
}
