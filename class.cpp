#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class player
{
    public:
    int number;
    string name;
    int matchplayed;
    string district;
    int age;
    int runs;
    int boundries;
    int overs;
    int wickets;
    list<player>li;
    public:
    void addplayer()
    {
        if(li.size()>30)
        {
            cout<<"team is already full "<<endl;
            return;
        }
        int a,b,c,d,e,f,g;
        string h,i;
        cout<<"enter player number :"<<endl;
        cin>>a;
        cout<<"enter players name: "<<endl;
        cin>>g;
        cout<<"enter the number of matches he played: ";
        cin>>b;
        cout<<"Enter his district: "<<endl;
        cin>>i;
        cout<<"enter his age: "<<endl;
        cin>>c;
        cout<<"enter his runs: "<<endl;
        cin>>d;
        cout<<"enter his boundries: "<<endl;
        cin>>e;
        cout<<"enter his bowling overs: "<<endl;
        cin>>f;
        cout<<"enter his wickets: "<<endl;
        cin>>g;
        li.push_back({a,h,b,i,c,d,e,f,g});
    }

    void deleteplayer()
    {
        int num;
        cout<<"Enter the player number you want to delete: "<<endl;
        cin>>num;
        for(list<player>::iterator it=li.begin();it!=li.end();++it)
        {
            if(it->number==num)
            {
                it=li.erase(it);
            }
        }
    }

    void updateplayer()
    {
        int num;
        cout<<"Enter the player number you want to update: "<<endl;
        cin>>num;
         for(list<player>::iterator it=li.begin();it!=li.end();++it)
        {
            if(it->number==num)
            {
                int b,c,d,e,f,g;
                string h,i;
                cout<<"enter players name: "<<endl;
                cin>>g;
                it->name=g;
                cout<<"enter the number of matches he played: ";
                cin>>b;
                it->matchplayed=b;
                cout<<"Enter his district: "<<endl;
                cin>>i;
                it->district=i;
                cout<<"enter his age: "<<endl;
                cin>>c;
                it->age=c;
                cout<<"enter his runs: "<<endl;
                cin>>d;
                it->runs=d;
                cout<<"enter his boundries: "<<endl;
                cin>>e;
                it->boundries=e;
                cout<<"enter his bowling overs: "<<endl;
                cin>>f;
                it->overs=f;
                cout<<"enter his wickets: "<<endl;
                cin>>g;
                it->wickets=g;
                return;
            }
            cout<<"player not found!  "<<endl;
        }
    }

        void showlist()
        {
            //iterating through the list and printing the value 
            list <player> :: iterator it;
            for(it = li.begin(); it != li.end(); ++it)
            {
                cout<<"player number: "<<it->number<<endl;
                cout<<"player name: "<<it->name<<endl;
                cout<<"player matches played: "<<it->matchplayed<<endl;
                cout<<"player district: "<<it->district<<endl;
                cout<<"player age: "<<it->age<<endl;
                cout<<"player runs: "<<it->runs<<endl;
                cout<<"player boundries: "<<it->boundries<<endl;
                cout<<"player overs: "<<it->overs<<endl;
                cout<<"player wickets: "<<it->wickets<<endl;    
            }
            cout <<endl<<endl;
        }

        void average()
        {
            int num;
            cout<<"Enter the player number you want to see average: "<<endl;
            cin>>num;
            for(list<player>::iterator it=li.begin();it!=li.end();++it)
            {
                if(it->number==num)
                 {
                     float x,y;
                     x=it->runs/it->matchplayed;
                     cout<<"average of runs is : "<<x<<endl;
                     y=it->wickets/it->matchplayed;
                     cout<<"average of runs is : "<<y<<endl;
                     return;
                 }
            }
            cout<<"player not found! "<<endl;
        }

   void bestbatman()
     {
       list<player>::iterator it2;
        float maxi=-100000.0;
       for(list<player>::iterator it=li.begin();it!=li.end();++it)
            {
                float aver=it->runs/it->matchplayed;
                if(aver>maxi)
                {
                    it2=it;
                    maxi=aver;
                }
            }
            cout<<"player with the maximum run average is "<<it2->name<<" with average of "<<maxi<<endl;
     }
      void bestbowler()
        {
            list<player>::iterator it2;
            float maxi=-10000.0;
            for(list<player>::iterator it=li.begin();it!=li.end();++it)
                    {
                        float aver=it->wickets/(it->matchplayed);
                        if(aver>maxi)
                        {
                            it2=it;
                            maxi=aver;
                        }
                    }

            cout<<"player with the maximum run average is "<<it2->name<<" with average of "<<maxi<<endl;
         }
         bool compare(player p1,player p2)
         {
             float a=p1.runs/p1.matchplayed;
             float a2=p2.runs/p2.matchplayed;
             return(a<a2);
         }

         void sortbat()
         {
             sort(li.begin(),li.end(),compare);
             showlist();
         }

         bool compare1(player p1,player p2)
         {
             float a=p1.wickets/p1.matchplayed;
             float a2=p2.wickets/p2.matchplayed;
             return(a<a2);
         }

         void sortbowler()
         {
             sort(li.begin(),li.end(),compare1);
             showlist();
         }
};

int main()
{
      player p;
      int choice;
      while (1)
        {
        cout<<"1. add player profile\n";
        cout<<"2. delete player profile\n";
        cout<<"3. update player profile\n";
        cout<<"4. view all player profile\n";
        cout<<"5. calculate an average runs and wickets for a selected player\n";
        cout<<"6. show the best batsman on run average\n";
        cout<<"7. show the best batsman on wicket average\n";
        cout<<"8. sort the player batsman on run average\n";
        cout<<"9. sort the player batsman on wicket average\n";
        cout<<"10. Exit\n";
        cout<<"\n Your choice ?";
        cin>>choice ;
        switch(choice)
        {
            case 1 :
                p.addplayer();
                break ;     
            case 2 :
                p.deleteplayer();
                break;
            case 3:
                p.updateplayer();
                break ;
            case 4:
                p.showlist();
                break;
            case 5:
                p.average();
                break;
                case 6:
                p.bestbatman();
                break;
            case 7:
                p.bestbowler();
                break;
            case 8:
                p.sortbat();
                break;
            case 9:
                p.sortbowler();
                break;
            case 10 :
                exit(0);
        }
    }
}

