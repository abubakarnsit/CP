#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <ctime>
using namespace std;
//pickcards2 overloaded randomly picks a card from a deck
int pickcards2(int*deck)
{
    double c;
    int toret;
    c=((double) rand() / (RAND_MAX));
    c=c*52;
    toret=(int)c;
    return toret;
}
//shuffle randomly shuffles a deck of cards
void shuffle(int*deck)
{
    for(int i=0;i<52;i++)
    {
        int ind=pickcards2(deck);
        int temp=deck[i];
        deck[i]=deck[ind];
        deck[ind]=temp;
    }
}
//pickcards overloaded randomly picks four cards from a deck
void pickcards(int*deck,int*pick)
{
    for(int i=0;i<4;i++)
    pick[i]=deck[pickcards2(deck)];
}
//isOneOFEachSuit tests if one card of each suit was picked
bool isoneofeachsuite(int*pick)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i!=j and (pick[i]/13==pick[j]/13))
            return false;
        }
    }
    return true;
}
//print displays the four cards picked
void print(int*picks)
{
    string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
								"10", "Jack", "Queen", "King"};
    for(int i=0;i<4;i++)
    {
        cout<<ranks[picks[i]%13]<<" of "<<suits[picks[i]/13]<<endl;
    }
}
int main()
{
    int decks[52];
    int picks[4];
    //initializing the cards
    for(int i=0;i<52;i++)
    decks[i]=i;
    int count=0;//no of picks
    srand(time(0));
    shuffle(decks);  //shuffle the cards
    do{
        pickcards(decks,picks);
        count++;
    }while(!isoneofeachsuite(picks));
    print(picks);//display the four cards
    //displaying the number of picks to get four cards from each suit
    cout<<"Number of picks: "<<count;
}