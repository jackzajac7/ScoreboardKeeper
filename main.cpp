#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

void printScoreboard(vector < vector <int> > score);
int randomBetween(int first, int second);

int main()
{
  srand((int) time(0));
  int periods;
  int teams;

  cout<<"How many competitors? ";
  cin>>teams;
  cout<<"How many scoring periods? ";
  cin>>periods;

  if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
      teams > MAX_TEAMS || periods > MAX_PERIODS )
  {
    cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
    cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
    return 0;
  }
  else
  {
   //make scoreboard and fill it with zeros
    vector <vector <int> > board;
    board.resize(teams);
    for(int r=0; r<teams; r++)
    {
        board[r].resize(periods);
        for(int c=0; c<periods; c++)
        {
            board[r][c]=0;
        }
    }
     //once created, display the scoreboard
    int playerNum = 1;
    cout<< "SCOREBOARD" <<endl;
    for(int row=0; row<board.size(); row++)
    {
        cout<< "Player " << playerNum++ << ": "; 
        for(int col=0; col<board[row].size(); col++)
        {
          cout <<board[row][col] << '|';
        }
        cout <<endl;
    }
    printScoreboard(board);
  }
  return 0;
}


void printScoreboard(vector < vector <int> > score)
{
    for(int r=0; r<score.size(); r++)
    {
        for(int c=0; c<score[r].size(); c++)
        {
            score[r][c]=randomBetween(0, 9);
        }
    }
    int playerNum = 1;
    cout<< "SCOREBOARD" <<endl;
    for(int row=0; row<score.size(); row++)
    {
        cout<< "Player " << playerNum++ << ": "; 
        for(int col=0; col<score[row].size(); col++)
        {
          cout <<score[row][col] << '|';
        }
        cout <<endl;
    }
}

int randomBetween(int first, int second)
{
  if(first > second)
  {
    return second + rand()%(first-second+1);
  }
  else if(first < second)
  {
    return first + rand()%(second-first+1);
  }
}