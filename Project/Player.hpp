#ifndef Player_HPP
#define Player_HPP
#include <stack>
#include <vector>
#include <iostream>
using namespace std;


struct hand
{



};

struct deck
{
  string faceValue;
  int value;
  string suit;
  deck *next;
};\


const int deckSize = 52;
const int handSize = 14;

class Player
{
   public:
      Player();
      ~Player();
      // Dealer();
      void deal();
      deck playerArr[handSize];
      deck dealerArr[handSize];
      void hit(char letter);
      void shuffle();
      void loadDeck();
      void playerBet();
      int playerOut();
      void printDeck();
      deck arr[deckSize];
      void setCash(int cashMoney);
      int getCash();
      void setBet(int betMoney);
      int getBet();
      void printHand(char let);
      int totalPlayer;
      int totalDealer;
      int caseFunction();
      ofstream outstream;
      void doubleDown();


   private:
      int cash;
      int currentBet;
      deck* deckHead;
      unsigned getHash();
      stack<deck*> cardStack;
};

#endif
