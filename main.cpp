#include <iostream>
#include <cstring>
#include <vector>

#include <fstream>
#include <ctime>
#include <tuple>

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
    bool dealer = true;
    if(d1.getSum() < 18){
        dealer = d1.addCard();
    }
    return (player && dealer);
}

void printDeck(vector<Card>& d) {
    for(auto el:d) {
        cout<<el.getNumber()<<" ";
    }
    cout<<endl;
}

int main() {
    clrscr();
    srand(time(NULL));

    char name[100];
    char choice, hit='Y';
    bool status;

    int k=1;
    vector<Card> deck(52);
    for(int i=0;i<52;i++) {
        deck[i].setNumber(k++);
    }
    printDeck(deck);

    int val= rand()%52;
    cout << deck[val].getNumber() << endl;
    cout<<deck.size()<<endl;
    deck.erase(deck.begin()+val);
    printDeck(deck);
    cout<<deck.size()<<endl;
    // cout << "Hello! Enter your name: ";
    // cin >> name;

    // Player player(name);
    // Dealer dealer;

    // clrscr();
    // cout<<"Hello! "; player.printName();
    

    // while(hit!='N' and hit!='n') {
    //     status = deal(player,dealer);
    //     cout<<"\nYou hold: "<<player.getSum();
    //     cout<<"\nDealer holds: "<<dealer.getSum();
    //     if(status){
    //         cout<<"\nHit? : "; cin>>hit;
    //     }
    //     else {
    //         cout<<"\nGame ended.";
    //         break;
    //     }
    // }

    // if(status) {
    //     if(dealer.getSum() > player.getSum()) {
    //         cout<<"\nDealer wins";
    //     }
    //     else if(dealer.getSum() == player.getSum()) {
    //         cout<<"\nNeutral";
    //     }
    //     else{
    //         cout<<"\nYou win!";
    //     }
    // }

    return 0;
}
