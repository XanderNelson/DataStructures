#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>

#include "Player.hpp"
using namespace std;

Player::Player()
{
  totalPlayer = 0;
  totalDealer = 0;
  for(int i = 0; i < handSize; i++)
  {
    dealerArr[i].faceValue = "";
    dealerArr[i].value = 0;
    dealerArr[i].suit = "";
    playerArr[i].faceValue = "";
    playerArr[i].value = 0;
    playerArr[i].suit = "";
  }
  cash = 0;
}

Player::~Player()
{
  totalPlayer = 0;
  totalDealer = 0;
  for(int i = 0; i < handSize; i++)
  {
    dealerArr[i].faceValue = "";
    dealerArr[i].value = 0;
    dealerArr[i].suit = "";
    playerArr[i].faceValue = "";
    playerArr[i].value = 0;
    playerArr[i].suit = "";
  }
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
   cout << "Deck is being shuffled" << endl;
   srand((unsigned)time(0));
   for(int i = 0; i < deckSize; i++)
   {
      int randNum = rand() % 52;
      swap(arr[i], arr[randNum]);
      //fisher-yates
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
     cout << cardStack.top()->faceValue << " of " << cardStack.top()->suit << endl;
     cardStack.pop();
   }
}


void Player::deal()
{
   // cout << cardStack.top()->faceValue << endl;
   // cout << cardStack.top()->value << endl;
   // cout << cardStack.top()->suit << endl;
  playerArr[0] = *cardStack.top();
  cout <<"here" << endl;
  cardStack.pop();
  cout <<"here1" << endl;
  dealerArr[0].faceValue = cardStack.top()->faceValue;
  dealerArr[0].value = cardStack.top()->value;
  dealerArr[0].suit = cardStack.top()->suit;
  cardStack.pop();
  playerArr[1].faceValue = cardStack.top()->faceValue;
  playerArr[1].value = cardStack.top()->value;
  playerArr[1].suit = cardStack.top()->suit;;
  cardStack.pop();
  dealerArr[1].faceValue = cardStack.top()->faceValue;
  dealerArr[1].value = cardStack.top()->value;
  dealerArr[1].suit = cardStack.top()->suit;
  cardStack.pop();
  cout << "Drawn hand: " << playerArr[0].faceValue << " of " << playerArr[0].suit << ", ";
  cout << playerArr[1].faceValue << " of " << playerArr[1].suit << endl;

  cout << "Dealers top card: " << dealerArr[0].faceValue  << " of " << dealerArr[0].suit << endl;
  //cout << playerArr[i].faceValue << endl;
  for(int i = 0; i < 2; i++)
  {
    if(playerArr[i].faceValue == "Ace")
    {
      string option;
      cout << "What value would you like your Ace to be?" << endl;
      cout << "1) 1" << endl;
      cout << "2) 11" << endl;
      getline(cin, option);
      while(option != "1" || option != "2")
      {
        if(option == "1")
        {
          playerArr[i].value = 1;
          cout << "Your Ace is worth 1" << endl;
          break;
        }
        if(option == "2")
        {
          playerArr[i].value = 11;
          cout << "Your Ace is worth 11" << endl;
          break;
        }
        else
        {
          cout << "Invalid option, choose (1) for 1 or (2) for 11." << endl;
          getline(cin,option);
        }
      }
    }
  }

  if(dealerArr[0].faceValue == "Ace")
  {
    dealerArr[0].value = 11;
    cout << "Dealers Ace is worth 11" << endl;
  }
  for(int k = 0; k < 2; k++)
  {
    totalPlayer = totalPlayer + playerArr[k].value;
    totalDealer = totalDealer + dealerArr[k].value;
  }
  //caseFunction();
}


void Player::playerBet()
{
  string bet = "";
  cout << "Enter your bet value: " << endl;
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
   int i = 0;
   if(letter == 'P' || letter == 'p')
   {

     while(playerArr[i].value != 0)  // vector not array
     {
        i++;
     }
     playerArr[i].faceValue = cardStack.top()->faceValue;
     playerArr[i].value = cardStack.top()->value;
     playerArr[i].suit = cardStack.top()->suit;
     totalPlayer = totalPlayer + cardStack.top()->value;
     cardStack.pop();

   }
  else
  {
  int x = 0;
  while(dealerArr[x].value != 0)
  {
     x++;
  }
  dealerArr[x].faceValue = cardStack.top()->faceValue;
  dealerArr[x].value = cardStack.top()->value;
  dealerArr[x].suit = cardStack.top()->suit;
  totalDealer = totalDealer + cardStack.top()->value;
  cardStack.pop();
  }
}

void Player::printHand(char let)
{
   if(let == 'P' ||let == 'p')
   {
     int i = 0;
     while(playerArr[i].value != 0)
     {
       cout << playerArr[i].faceValue << " of " << playerArr[i].suit;
       if(playerArr[i+1].value != 0)
       {
         cout << ", ";
       }
       i++;
     }


     cout << endl;
   }
   else
   {
     if(let == 'D' ||let == 'd')
     {
       int x = 0;
       while(dealerArr[x].value != 0)
       {
         cout << dealerArr[x].faceValue << " of " << dealerArr[x].suit;
         if(dealerArr[x+1].value != 0)
         {
           cout << ", ";
         }
         x++;
       }
     }
   }
}

int Player::caseFunction()
{

   if(totalDealer == 21 && totalPlayer == 21)
   {
      cout << "Draw" << endl;
      setBet(0);
      return 1;
   }
   else if(totalDealer == 21 && totalPlayer != 21)
   {
      cout << "Dealer got blackjack, you lost." << endl;
      setCash(-1 * currentBet);
      setBet(0);
      return 2;
   }
   else if(totalPlayer == 21 && totalDealer != 21)
   {
      cout << "You got blackjack!" << endl;
      setCash(1.5 * currentBet);
      setBet(0);
      return 3;
   }
   else if(totalPlayer > 21)
   {
     cout << "You went over 21, you lost." << endl;
     setCash(-1 * currentBet);
     setBet(0);
     return 4;
     }
   else
   {
     return 0;
   }
}
