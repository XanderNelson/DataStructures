#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct wordItem
{
  string word;
  int count=1;
};

bool isStopWord(string word, string ignoreWords[]);
void getStopWords(const char *ignoreWordFileName, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length);
void arraySort(wordItem uniqueWords[], int length);
void printTopN(wordItem uniqueWords[], int topN, int totalNumWords);

int main(int argc, char *argv[])
{
  if(argc != 4)
  {
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
  }

  int arrayDouble = 0;
  int N = stoi(argv[1]);

  string pink[50];
  getStopWords(argv[3], pink);

  int length = 100;
  int counter = 0;
  int uniqueNonIgnore = 0;
  string bookWord;
  wordItem *arr = new wordItem[length];

  ifstream inBook;
  inBook.open(argv[2]);
  if(inBook.is_open())
  {
      while(inBook >> bookWord)
      {
          if(counter == length)
            {
               for(int i = 0; i <= counter; i++)
              {

                if(bookWord == arr[i].word)
                {
                  arr[i].count = arr[i].count + 1;
                  uniqueNonIgnore++;
                }
              }
              length = length * 2;
              arrayDouble++;
              wordItem *tempArr = new wordItem[length];
              for(int j = 0; j < counter; j++)
                {
                  tempArr[j] = arr[j];
                }
              delete [] arr;
              arr = tempArr;
              tempArr = NULL;
            }
          else
          {
            bool test = isStopWord(bookWord, pink);
            if(test != true)
            {
              uniqueNonIgnore++;
              test = false;
              for(int i = 0; i <= counter; i++)
              {
                if(bookWord == arr[i].word)
                {
                  arr[i].count = arr[i].count + 1;
                  test = true;
                }
              }
              if(test == false)
                {
                  arr[counter].word = bookWord;
                  arr[counter].count = 1;
                  counter++;
                }
          }
        }
      }
      inBook.close();
    int tot = getTotalNumberNonStopWords(arr, counter);
    std::cout << "Array doubled: " << arrayDouble << endl;
    std::cout << "#" << endl;
    std::cout << "Unique non-common words: " << counter << endl;
    std::cout << "#" << endl;
    std::cout << "Total non-common words: " << uniqueNonIgnore << endl;
    std::cout << "#" << endl;
    arraySort(arr, counter);
    printTopN(arr, N, uniqueNonIgnore);
    //cout << tot << " " << uniqueNonIgnore << counter << endl;
  }
  else
  {
    cout << "Failed to open file." << endl;
    return 0;
  }
}


void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
  string line;
  ifstream inIgnore;
    int arrPlace = 0;
  inIgnore.open(ignoreWordFileName);
  if(inIgnore.fail())
  {
    cout << "Failed to open " << ignoreWordFileName << endl;
  }
  else
  {
    while(inIgnore >> line)
    {
        ignoreWords[arrPlace] = line;
        arrPlace++;
    }
  }
}
bool isStopWord(string word, string ignoreWords[])
{
  for(int i = 0; i <= 50; i++)
  {
    if(ignoreWords[i] == word)
    {
      return true;
    }
  }
  return false;
}


int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
  int totalUnique = 0;
  for(int i = 0; i < length; i++)
  {
    totalUnique = totalUnique + uniqueWords[i].count;
  }
  return totalUnique;
}

void arraySort(wordItem uniqueWords[], int length)
{
    wordItem temp;
  for(int i = 0; i <= length; i++)
  {
    for(int j = 0; j <= length; j++)
    {
        if(uniqueWords[j].count < uniqueWords[j+1].count)
        {
          temp = uniqueWords[j];
          uniqueWords[j] = uniqueWords[j+1];
          uniqueWords[j+1]=temp;
        }
    }
  }
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords)
{
  float probability;
  std::cout << "Probabilities of top " << topN << " most frequent words" << endl;
  std::cout << "---------------------------------------" << endl;
  for(int i = 0; i < topN; i++)
  {

    probability = (float)uniqueWords[i].count / (float)totalNumWords;
    cout << fixed << setprecision(4) << probability << " - " << uniqueWords[i].word << endl;
  }
}
