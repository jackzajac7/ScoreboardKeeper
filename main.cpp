#include <iostream>
#include <vector>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

int main()
{
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
    for(int row=0; row<board.size(); row++)
    {
        cout<< "player " << playerNum++ << ": "; 
        for(int col=0; col<board[row].size(); col++)
        {
          cout <<board[row][col] << '|';
        }
        cout <<endl;
    }
  }
  return 0;
}
