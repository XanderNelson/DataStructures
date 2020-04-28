#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

#include "Player.hpp"
#include "Player.cpp"
using namespace std;

void displayMenu();
int main()
{

  Player O;
  O.outstream.open("Game.html", std::ios::app);
  //O.Player();
  O.shuffle();

 O.outstream << endl;
 O.outstream << "Objective of the game is to have a set of cards whose value beats the dealer's set of cards' total value. <br>"<<  endl;
 O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
 O.outstream << "The cards are scored by their intended value, face cards are valued at 10 and the ace is your choice of 1 through 11.<br> " << endl;
 O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
 O.outstream << "Hit is when you the player wants another card from the dealer. A push occurs    when the dealer and the player's hand are equal and busting occurs when the dealer or player goes above 21. <br>" << endl;
 O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
 O.outstream << "Splitting can occur immidiately after your two cards are dealt and only is available if the hand is a pair.<br>" << endl;
 O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
 O.outstream << "Betting can start before the hand is drawn if the player thinks they can get a higher total than the dealwer without busting. There is the ability to double down after you are drawn your initial two cards.<br> " << endl;
 O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
 O.outstream << "If you lose the dealer takes your whole bet. If you win the dealer with give you your bet back times 2(bet $100 get back additional $100 from     dealer). If you draw with the dealer you keep your original bet and if   you get blackjack, you get your original bet back and 1.5 times from the  dealer(bet $100 get back additional $150 from dealer).<br>" << endl;
 O.outstream <<"------------------------------------------------------------------------------<br>" << endl;

  O.outstream << "How much cash are you bringing to the table?<br>" << endl;
  string c;
  getline(cin, c);
  O.setCash(stoi(c));
  O.outstream << "How much would you like to bet?" << endl;
  string b;
  getline(cin, b);
  O.setBet(stoi(b));
  O.deal();

  bool play = true;
  string check;
  while(check != "5" && play == true)
  {
     //O.caseFunction();
     if(O.caseFunction() != 0)
     {
       string input;
        O.outstream << "Money at hand:" << O.getCash() << endl;
        O.outstream << "Play again?" << endl;
        O.outstream << "1) Yes" << endl << "2) No" << endl;
        while(input != "1" && input != "2")
        {
          getline(cin, input);
          if(input == "2")
          {
            play = false;
            O.outstream << "Thanks for playing." << endl;
            O.outstream.close();
            //remove("Game.txt");
            exit(0);
          }
          else if(input == "1")
          {
              O.~Player();
              O.deal();
          }
          else
          {
             O.outstream << "Invalid input, choose (1) or (2)" << endl;
          }
        }
     }


    O.outstream << endl;
     O.outstream << "Current Hand: " << endl;
     O.printHand('p');
     O.outstream << "Total hand value: " << O.totalPlayer << endl;

     O.outstream << endl;
     O.outstream << "======Next Move, What would you like to do?======" << endl ;
     O.outstream << "1. Hit" << endl ;
     O.outstream << "2. Double Down" << endl;
     O.outstream << "3. Split" << endl;
     O.outstream << "4. Hold" << endl ;
     O.outstream << "5. Quit" << endl ;
     getline(cin, check);
     switch(stoi(check))
     {
        case 1:
        {
          //char p;
          O.hit('p');
            break;
        }
        case 2:
        {

           break;
        }
        case 3:
        {

           break;
        }
        case 4:
        {

          break;
        }
        case 5:
        {
          O.outstream << "Thanks for playing." << endl;
          break;
        }
     }
  }
  O.outstream.close();
}

// void displayMenu()
// {
//     O.outstream << endl;
//     O.outstream << "======Next Move, What would you like to do?======" << endl ;
//     O.outstream << "1. Hit" << endl ;
//     O.outstream << "2. Double Down" << endl;
//     O.outstream << "3. Split" << endl;
//     O.outstream << "4. Hold" << endl ;
//     O.outstream << "5. Quit" << endl ;
// }
