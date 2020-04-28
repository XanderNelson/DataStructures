
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>

#include "blackjack.hpp"
using namespace std;

Player::Player()
{
  totalPlayer = 0;
  totalDealer = 0;
  cash = 0;
}

Player::~Player()
{
  totalPlayer = 0;
  totalDealer = 0;
  // for(int i = 0; i < handSize; i++)
  // {
  //   dealer[i].faceValue = "";
  //   dealer[i].value = 0;
  //   dealer[i].suit = "";
  //   player[i].faceValue = "";
  //   player[i].value = 0;
  //   player[i].suit = "";
  // }
}


void Player::loadDeck()
{
   arr[0].faceValue = "Ace"; arr[0].value = 0; arr[0].suit = "Hearts";
   arr[1].faceValue = "Two"; arr[1].value = 2; arr[1].suit = "Hearts";
   arr[2].faceValue = "Three"; arr[2].value = 3; arr[2].suit = "Hearts";
   arr[3].faceValue = "Four"; arr[3].value = 4; arr[3].suit = "Hearts";
   arr[4].faceValue = "Five"; arr[4].value = 5; arr[4].suit = "Hearts";
   arr[5].faceValue = "Six"; arr[5].value = 6; arr[5].suit = "Hearts";
   arr[6].faceValue = "Seven"; arr[6].value = 7; arr[6].suit = "Hearts";
   arr[7].faceValue = "Eight"; arr[7].value = 8; arr[7].suit = "Hearts";
   arr[8].faceValue = "Nine"; arr[8].value = 9; arr[8].suit = "Hearts";
   arr[9].faceValue = "Ten"; arr[9].value = 10; arr[9].suit = "Hearts";
   arr[10].faceValue = "Jack"; arr[10].value = 10; arr[10].suit = "Hearts";
   arr[11].faceValue = "Queen"; arr[11].value = 10; arr[11].suit = "Hearts";
   arr[12].faceValue = "King"; arr[12].value = 10; arr[12].suit = "Hearts";

   arr[13].faceValue = "Ace"; arr[13].value = 0; arr[13].suit = "Clubs";
   arr[14].faceValue = "Two"; arr[14].value = 2; arr[14].suit = "Clubs";
   arr[15].faceValue = "Three"; arr[15].value = 3; arr[15].suit = "Clubs";
   arr[16].faceValue = "Four"; arr[16].value = 4; arr[16].suit = "Clubs";
   arr[17].faceValue = "Five"; arr[17].value = 5; arr[17].suit = "Clubs";
   arr[18].faceValue = "Six"; arr[18].value = 6; arr[18].suit = "Clubs";
   arr[19].faceValue = "Seven"; arr[19].value = 7; arr[19].suit = "Clubs";
   arr[20].faceValue = "Eight"; arr[20].value = 8; arr[20].suit = "Clubs";
   arr[21].faceValue = "Nine"; arr[21].value = 9; arr[21].suit = "Clubs";
   arr[22].faceValue = "Ten"; arr[22].value = 10; arr[22].suit = "Clubs";
   arr[23].faceValue = "Jack"; arr[23].value = 10; arr[23].suit = "Clubs";
   arr[24].faceValue = "Queen"; arr[24].value = 10; arr[24].suit = "Clubs";
   arr[25].faceValue = "King"; arr[25].value = 10; arr[25].suit = "Clubs";

   arr[26].faceValue = "Ace"; arr[26].value = 0; arr[26].suit = "Spades";
   arr[27].faceValue = "Two"; arr[27].value = 2; arr[27].suit = "Spades";
   arr[28].faceValue = "Three"; arr[28].value = 3; arr[28].suit = "Spades";
   arr[29].faceValue = "Four"; arr[29].value = 4; arr[29].suit = "Spades";
   arr[30].faceValue = "Five"; arr[30].value = 5; arr[30].suit = "Spades";
   arr[31].faceValue = "Six"; arr[31].value = 6; arr[31].suit = "Spades";
   arr[32].faceValue = "Seven"; arr[32].value = 7; arr[32].suit = "Spades";
   arr[33].faceValue = "Eight"; arr[33].value = 8; arr[33].suit = "Spades";
   arr[34].faceValue = "Nine"; arr[34].value = 9; arr[34].suit = "Spades";
   arr[35].faceValue = "Ten"; arr[35].value = 10; arr[35].suit = "Spades";
   arr[36].faceValue = "Jack"; arr[36].value = 10; arr[36].suit = "Spades";
   arr[37].faceValue = "Queen"; arr[37].value = 10; arr[37].suit = "Spades";
   arr[38].faceValue = "King"; arr[38].value = 10; arr[38].suit = "Spades";

   arr[39].faceValue = "Ace"; arr[39].value = 0; arr[39].suit = "Diamonds";
   arr[40].faceValue = "Two"; arr[40].value = 2; arr[40].suit = "Diamonds";
   arr[41].faceValue = "Three"; arr[41].value = 3; arr[41].suit = "Diamonds";
   arr[42].faceValue = "Four"; arr[42].value = 4; arr[42].suit = "Diamonds";
   arr[43].faceValue = "Five"; arr[43].value = 5; arr[43].suit = "Diamonds";
   arr[44].faceValue = "Six"; arr[44].value = 6; arr[44].suit = "Diamonds";
   arr[45].faceValue = "Seven"; arr[45].value = 7; arr[45].suit = "Diamonds";
   arr[46].faceValue = "Eight"; arr[46].value = 8; arr[46].suit = "Diamonds";
   arr[47].faceValue = "Nine"; arr[47].value = 9; arr[47].suit = "Diamonds";
   arr[48].faceValue = "Ten"; arr[48].value = 10; arr[48].suit = "Diamonds";
   arr[49].faceValue = "Jack"; arr[49].value = 10; arr[49].suit = "Diamonds";
   arr[50].faceValue = "Queen"; arr[50].value = 10; arr[50].suit = "Diamonds";
   arr[51].faceValue = "King"; arr[51].value = 10; arr[51].suit = "Diamonds";
}

void Player::shuffle()
{
   loadDeck();
   outstream << "<p>Deck is being shuffled<br>" << endl;
   srand((unsigned)time(0));
   for(int i = 0; i < deckSize; i++)
   {
      int randNum = rand() % 52;
      swap(arr[i], arr[randNum]);
   }
   for(int x = 0; x < deckSize; x++)
   {
     //  cout << randArr[x] << endl;
     deck *newCard = new deck;
     // int index = randArr[x];
     // arr[x] = arr[index];
     newCard->faceValue = arr[x].faceValue;
     newCard->value = arr[x].value;
     newCard->suit = arr[x].suit;
     cardStack.push(newCard);
   }
}

void Player::printDeck()
{

  for(int i = 0; i < 52; i++)
  {
     cout << cardStack.top()->faceValue << " of " << cardStack.top()->suit << "Value: " << cardStack.top()->value << endl;
     cardStack.pop();
   }
}


void Player::deal()
{
  player.clear();
  dealer.clear();
  totalPlayer = 0;
  totalDealer = 0;

  if(cardStack.empty())
  {
    outstream << "<p>Re-shuffling<br>" <<  endl;
    shuffle();
  }
  player.push_back(*cardStack.top());
  cardStack.pop();
  if(cardStack.empty())
  {
    outstream << "<p>Re-shuffling<br>" <<  endl;
    shuffle();
  }
  dealer.push_back(*cardStack.top());
  cardStack.pop();
  if(cardStack.empty())
  {
    outstream << "<p>Re-shuffling<br>" <<  endl;
    shuffle();
  }
  player.push_back(*cardStack.top());
  cardStack.pop();
  if(cardStack.empty())
  {
    outstream << "<p>Re-shuffling<br>" <<  endl;
    shuffle();
  }
  dealer.push_back(*cardStack.top());
  cardStack.pop();
  // outstream << "<p><b>Drawn hand: </b>" << player[0].faceValue << " of " << player[0].suit << ", ";
  // outstream << player[1].faceValue << " of " << player[1].suit << "<br>" << endl;
  int tot = 0;
  tot = player[0].value + player[1].value;
  outstream << "<p>Total hand value: " << tot << "<br>" << endl;

  outstream << "<p>Dealers top card: " << dealer[0].faceValue  << " of " << dealer[0].suit << "<br>" << endl;
  //cout << playerArr[i].faceValue << endl;
  for(int i = 0; i < 2; i++)
  {
    if(player[i].faceValue == "Ace")
    {
      string option;
      outstream << "<p>What value would you like your Ace to be?<br>" << endl;
      outstream << "<p>1) 1<br>" << endl;
      outstream << "<p>2) 11<br>" << endl;
      getline(cin, option);
      while(option != "1" || option != "2")
      {
        if(option == "1")
        {
          player[i].value = 1;
          outstream << "<p>Your Ace is worth 1<br>" << endl;
          break;
        }
        if(option == "2")
        {
          player[i].value = 11;
          outstream << "<p>Your Ace is worth 11<br>" << endl;
          break;
        }
        else
        {
          outstream << "<p>Invalid option, choose (1) for 1 or (2) for 11.<br>" << endl;
          getline(cin,option);
        }
      }
    }
  }

  if(dealer[0].faceValue == "Ace")
  {
    dealer[0].value = 11;
    outstream << "<p>Dealers Ace is worth 11<br>" << endl;
  }
  if(dealer[1].faceValue == "Ace")
  {
    dealer[1].value = 11;
    //outstream << "<p>Dealers Ace is worth 11<br>" << endl;
  }
  for(int k = 0; k < 2; k++)
  {
    totalPlayer = totalPlayer + player[k].value;
    totalDealer = totalDealer + dealer[k].value;
  }
  //caseFunction();
  if(totalDealer == 21 && totalPlayer == 21)
  {
     outstream << "<p>Draw<br>" << endl;
     setBet(0);
     exit(0);
  }
  else if(totalDealer == 21 && totalPlayer != 21)
  {
     outstream << "<h2>Dealer got blackjack, you lost.</h2>" << endl;
     outstream << "<br>" << endl;
     printHand('d');
     setCash(-1 * currentBet);
     setBet(0);
     gameOver = true;
  }
  else if(totalPlayer == 21 && totalDealer != 21)
  {
     outstream << "<h2>You got blackjack!</h2>" << endl;
     setCash(1.5 * currentBet);
     setBet(0);
     gameOver = true;
  }
 //  else
 //  {
 //     string d;
 //     outstream << "<br>" << endl;
 //     outstream << "<p>Would you like to double down? Y or N<br>" << endl;
 //     getline(cin,d);
 //     if(d == "Y" || d == "y")
 //     {
 //        doubleDown();
 //     }
 // }
}


void Player::playerBet()
{
  string bet = "";
  outstream << "<p>Enter your bet value: <br>" << endl;
  getline(cin, bet);
  setBet(stoi(bet));
}

int Player::playerOut()
{
  cash = cash + currentBet;
  return cash;
}

void Player::setCash(int cashMoney)
{
  cash = cash + cashMoney;
}
int Player::getCash()
{
   return cash;
}

void Player::setBet(int betMoney)
{
  currentBet = betMoney;
}
int Player::getBet()
{
   return currentBet;
}

void Player::hit(char letter)
{
  if(cardStack.empty())
  {
    outstream << "<p>Re-shuffling<br>" <<  endl;
    shuffle();
  }
   int i = 0;
   if(letter == 'P' || letter == 'p')
   {
     if(cardStack.top()->faceValue == "Ace")
     {
       string option;
       outstream << "<p>What value would you like your Ace to be?<br>" << endl;
       outstream << "<p>1) 1<br>" << endl;
       outstream << "<p>2) 11<br>" << endl;
       getline(cin, option);
       while(option != "1" || option != "2")
       {
         if(option == "1")
         {
           cardStack.top()->value = 1;
           outstream << "<p>Your Ace is worth 1<br>" << endl;
           break;
         }
         if(option == "2")
         {
           cardStack.top()->value = 11;
           outstream << "<p>Your Ace is worth 11<br>" << endl;
           break;
         }
         else
         {
           outstream << "<p>Invalid option, choose (1) for 1 or (2) for 11.<br>" << endl;
           getline(cin,option);
         }
       }
     }
      totalPlayer = totalPlayer + cardStack.top()->value;
      player.push_back(*cardStack.top());
      cardStack.pop();
   }
  else
  {
     if(cardStack.top()->faceValue == "Ace")
     {
        if(totalDealer <= 10)
        {
           cardStack.top()->value = 11;
        }
        else
        {
           cardStack.top()->value = 1;
        }
     }
      totalDealer = totalDealer + cardStack.top()->value;
      dealer.push_back(*cardStack.top());
      cardStack.pop();
  }
}

void Player::printHand(char let)
{
   if(let == 'P' ||let == 'p')
   {
     int i = 0;
     for(int i = 0; i < player.size(); i++)
     {
       outstream << "<p>" << player[i].faceValue << " of " << player[i].suit << "<br>";
       // if(i != player.size()-1)
       // {
       //   outstream << "<p>, ";
       // }
     }
     cout << endl;
   }
   else
   {
     if(let == 'D' ||let == 'd')
     {
       int x = 0;
       for(int x = 0; x < dealer.size(); x++)
       {
         outstream << "<p>" << dealer[x].faceValue << " of " << dealer[x].suit << "<br>";
         // if(x != dealer.size()-1)
         // {
         //   outstream << "<p>, ";
         // }
       }
     }
   }
}

int Player::caseFunction()
{
   if(totalPlayer == 21 && totalDealer != 21)
   {
      outstream << "<p>You reached 21<br>" << endl;
      dealerFunc();
      return 4;
   }
   else if(totalPlayer > 21)
   {
     outstream << "<p>Current Hand: " << endl;
     printHand('p');
     outstream << "<p>Total: " << totalPlayer << endl;
     outstream << "<br>" << endl;
     outstream << "<h2>You went over 21, you lost.</h2>" << endl;
     setCash(currentBet * -1);
     gameOver = true;
     return 4;
   }
   else
   {
     return 0;
   }
}

void Player::dealerFunc()
{
  bool d = false;
   outstream << "<p>Dealers full hand: " << endl;
   printHand('d');
   outstream << "<br>" << endl;
   outstream << "<p>Dealer total: " << totalDealer << endl;
   while(totalDealer < 16)
   {
     if(totalDealer > totalPlayer && totalDealer <= 21)
     {
        outstream << "<h2>Dealer has won</h2>" << endl;
        setCash(currentBet * -1);
        gameOver = true;
        d = true;
        break;
     }
      hit('d');
      outstream << "<br>" << endl;
      outstream << "<p>Dealers current hand: " << endl;
      printHand('d');
      outstream << "<br>" << endl;
      outstream << "<p>Dealer's total: " << totalDealer << endl;
    }
   if(totalDealer > 21)
   {
      outstream << "<br>" << endl;
      outstream << "<h2>Dealer has gone over 21, you won.</h2>" << endl;
      setCash(currentBet);
      gameOver = true;
      //exit(0);
   }
  else if(totalDealer > totalPlayer && d != true)
  {
     outstream << "<br>" << endl;
     outstream << "<h2>Dealer has won</h2>" << endl;
     setCash(currentBet * -1);
     gameOver = true;
  }
   else if(totalDealer == 21 && totalPlayer < 21)
   {
      outstream << "<br>" << endl;
      outstream << "<h2>Dealer wins</h2>" << endl;
      setCash(currentBet * -1);
      gameOver = true;
      //exit(0);
   }
   else if(totalDealer == totalPlayer)
   {
   outstream << "<br>" << endl;
     outstream << "<p>Draw" << endl;
     gameOver = true;
     //exit(0);

   }
   else if(totalDealer < totalPlayer)
   {
      outstream << "<br>" << endl;
      outstream << "<h2>Your hand beat the dealer, you win!</h2>" << endl;
      outstream << "<p>Current hand: " << endl;
      printHand('p');
      outstream << "<p>Total hand value: " << totalPlayer << endl;
      setCash(currentBet);
      gameOver = true;
   }
}

void Player::doubleDown()
{
   setBet(currentBet * 2);
   hit('p');
   if(totalPlayer > 21)
   {
     outstream << "<br>";
     outstream << "<p><b>Current hand: </b>" << endl;
     printHand('p');
     outstream << "<h2>You went over 21, you lost.</h2>" << endl;
     setCash(currentBet * -1);
     gameOver = true;
   }
   else
   {
     outstream << "<br" << endl;
     outstream << "<p><b>Current hand: </b>" << endl;
     printHand('p');
     outstream << "<p>Total hand value: " << totalPlayer << endl;
     outstream << "<br>" << endl;
         dealerFunc();
         gameOver = true;
   }
}
