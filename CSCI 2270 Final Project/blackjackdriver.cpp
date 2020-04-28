#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

#include "blackjack.hpp"
#include "blackjack.cpp"
using namespace std;

void displayMenu();
int main()
{
  Player O;
  O.outstream.open("Game.html", std::ios::app);
  cout << "here" << endl;
  //O.Player();
  O.shuffle();

  // O.outstream << endl;
  // O.outstream << "Objective of the game is to have a set of cards whose value beats the dealer's set of cards' total value. <br>"<<  endl;
  // O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
  // O.outstream << "The cards are scored by their intended value, face cards are valued at 10 and the ace is your choice of 1 through 11.<br> " << endl;
  // O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
  // O.outstream << "Hit is when you the player wants another card from the dealer. A push occurs    when the dealer and the player's hand are equal and busting occurs when the dealer or player goes above 21. <br>" << endl;
  // O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
  // O.outstream << "Splitting can occur immidiately after your two cards are dealt and only is available if the hand is a pair.<br>" << endl;
  // O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
  // O.outstream << "Betting can start before the hand is drawn if the player thinks they can get a higher total than the dealwer without busting. There is the ability to double down after you are drawn your initial two cards.<br> " << endl;
  // O.outstream <<"------------------------------------------------------------------------------<br>" << endl;
  // O.outstream << "If you lose the dealer takes your whole bet. If you win the dealer with give you your bet back times 2(bet $100 get back additional $100 from     dealer). If you draw with the dealer you keep your original bet and if   you get blackjack, you get your original bet back and 1.5 times from the  dealer(bet $100 get back additional $150 from dealer).<br>" << endl;
  // O.outstream <<"------------------------------------------------------------------------------<br>" << endl;

//  O.printDeck();
// }

  O.outstream << "<p>How much cash are you bringing to the table?<br>" << endl;
  string c;
  getline(cin, c);
  O.outstream << "<h4>" << c << "</h4>";
  O.setCash(stoi(c));
  O.outstream << "<p>How much would you like to bet?<br>" << endl;
  string b;
  getline(cin, b);
  O.outstream << "<h4>" << b << "</h4>";
  O.setBet(stoi(b));
  O.deal();

  bool play = true;
  string check;
  int dcheck = 0;
  while(check != "4" && play == true)
  {
     //cout << "above" << endl;

     //if(O.caseFunction() != 0)
     if(O.gameOver == true || O.caseFunction() == 4)
     {
       O.gameOver = false;
        string input;
        O.outstream << "<h4>Money at hand: " << O.getCash() << "</h4>" << endl;
        if(O.getCash() <= 0)
        {
          O.outstream << "<h2>You lost all your money, you LOSE!</h2>" << endl;
          exit(0);
        }
        O.outstream << endl;
        O.outstream << "<p>Play again?<br>" << endl;
        O.outstream << "<p>Yes: (y) or (Y)"<< " or " << "No: (n) or (N)<br>" << endl;
        while(input != "Y" && input != "N")
        {
          getline(cin, input);
          if(input == "N" || input == "n")
          {
            play = false;
            O.gameOver = false;
            O.outstream << "<p>Thanks for playing.<br>" << endl;
            exit(0);
          }
          else if(input == "Y" || input == "y")
          {
            dcheck = 0;
             O.setBet(0);
              O.outstream << "<p>How much would you like to bet?<br>" << endl;
              string b;
              getline(cin, b);
              O.outstream << "<h4>" << b << "</h4>";
              O.setBet(stoi(b));
              O.deal();
              break;
          }
          else
          {
             O.outstream << "<p>Invalid input, choose (Y) or (N)<br>" << endl;
          }
        }
     }


     O.outstream << "<br>";
     O.outstream << "<p><b>Current Hand: </b>" << endl;
     O.printHand('p');
     O.outstream << "<p>Total hand value: " << O.totalPlayer << "<br>" << endl;

     O.outstream << "<br>";
     O.outstream << "<p>======Next Move======<br>" << endl ;
     O.outstream << "<p>1. Hit<br>" << endl ;
     O.outstream << "<p>2. Double Down<br>" << endl;
     O.outstream << "<p>3. Hold<br>" << endl ;
     O.outstream << "<p>4. Quit<br>" << endl ;

     dcheck++;
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
          if(dcheck == 1)
          {
            O.doubleDown();
          }
          else
          {
            O.outstream << "<p>Cannot double down!<br>" << endl;
          }
           break;
        }
        case 3:
        {
          O.dealerFunc();
          break;
        }
        case 4:
        {
          O.outstream << "<p>Thanks for playing.<br>" << endl;
          break;
        }
     }
  }
}
