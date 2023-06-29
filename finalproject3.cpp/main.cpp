#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <windows.h>
using namespace std;

static int pi=0;
//--------------------------sakht-bazikon
struct createplayer
{
    char name[10];
    int price;
    int speed;
    int finishing;
    int defence;
    int playerID;//shenase adadi bazikon
    int teamIDplayer=0;//shenase teami ke bazikon ozveshe
    string post;
    int tempdefence;
    int tempspeed;
    int tempfinishing;
}player[200];
//--------------------------sakht-team
struct createteam
{
    char name[10];
    int money;
    int teamID;//shenase adadi team
    createplayer arrplayers11[11];
    int players11=0;//tedad bazikonaye team
    int power;
    int temppower;
    int score=0;
    int goalwin=0;
    int goallose=0;
    int wins=0;
    int losses=0;
    int draws=0;
    int goaldifference=0;

}team[20];
//---------------------------------temp mode
//struct playertemp
//{
    //int speed;
    //int finishing;
    //int defence;
//};
//--------------------------sakht-bazikon
void CreatePlayer()
{
    cin>>player[pi].name>>player[pi].price>>player[pi].speed>>player[pi].finishing>>player[pi].defence;
    player[pi].playerID=pi;
    //cout<<player[pi].name<<" "<<player[pi].price<<" "<<player[pi].speed<<" "<<player[pi].finishing<<" "<<player[pi].defence<<" "<<player[pi].playerID<<endl;
    if((player[pi].defence>player[pi].finishing) && (player[pi].defence>player[pi].speed))
    {
        player[pi].post="defender";
    }
    if((player[pi].speed>player[pi].finishing) && (player[pi].speed>player[pi].defence))
    {
        player[pi].post="midfielder";
    }
    if((player[pi].finishing>player[pi].speed) && (player[pi].finishing>player[pi].defence))
    {
        player[pi].post="striker";
    }
    if((player[pi].speed==player[pi].finishing) && (player[pi].speed==player[pi].defence))
    {
        player[pi].post="normal";
    }
    //cout<<player[pi].post<<endl;
    pi++;
}
//-----------------------------sakht-team
static int ti=0;
int CreateTeam()
{
    int n=10;
    char teamname[n];
    cin>>teamname;
    bool same=false;
    for(int i=0;i<20;i++)
    {
        if(strcmp(teamname,team[i].name)==0)//teami ba in esm az ghabl vojood dare ya na
        {
            same=true;
            break;
        }
    }
    if(same==false)
    {
        cin>>team[ti].money;
        strcpy(team[ti].name,teamname);
        team[ti].teamID=ti;
        //cout<<team[ti].name<<" "<<team[ti].money<<" "<<team[ti].teamID<<endl;
        ti++;
    }
}
//-------------------------------------kharid-bazikon
//static int k=0;
int BuyPlayer()
{
    int playerID,teamID;
    cin>>playerID>>teamID;
    //cout<<pi<<endl;
    if(playerID-1>=pi)//----------------------------shenase adadi bazikon kharej az mahdoode
    {
        printf("\e[0;91m");
        cout<<"player with the id"<<" "<<playerID<<" "<<"doesnt exist"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(teamID-1>=ti)
    {
        printf("\e[0;91m");
        cout<<"team with the id"<<" "<<teamID<<" "<<"doesnt exist"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(team[teamID-1].money<player[playerID-1].price)
    {
        printf("\e[0;91m");
        cout<<"the team cant afford to buy this player"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(player[playerID-1].teamIDplayer!=0)
    {
        printf("\e[0;91m");
        cout<<"player already has a team"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(team[teamID-1].players11>=11)
    {
        printf("\e[0;91m");
        cout<<"team is full"<<endl;
        printf("\e[0m");
        return 0;
    }
    else
    {
        team[teamID-1].money =team[teamID-1].money-player[playerID-1].price;//-------pool ro azash kam mikone
        player[playerID-1].teamIDplayer=teamID;//--------------------------------shenase adadi team ro mide be bazikon
        team[teamID-1].power+=(player[playerID-1].speed+player[playerID-1].finishing+player[playerID-1].defence);
        team[teamID-1].players11++;//--------------------------------------------tedad ozv haye team ro afzayesh mide
        printf("\e[0;92m");
        cout<<"player"<<" "<<playerID<<" "<<"added to the team"<<" "<<teamID<<" "<<"successfully"<<endl;
        printf("\e[0m");
    }

}
//---------------------------------------foroosh-bazikon
int SellPlayer()
{
    int playerID,teamID;
    cin>>playerID>>teamID;
    if(teamID-1>ti)//------------------------------shenase adadi team toye mahdode hast ya na
    {
        printf("\e[0;91m");
        cout<<"team doesnt exist"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(player[playerID-1].teamIDplayer!=teamID)//----in bazikon mal in team hast ya na
    {
        printf("\e[0;91m");
        cout<<"team doesnt have this player"<<endl;
        printf("\e[0m");
        return 0;
    }
    else
    {
        team[teamID-1].money =team[teamID-1].money+player[playerID-1].price;
        player[playerID-1].teamIDplayer=0;
        team[teamID-1].power-=(player[playerID-1].speed+player[playerID-1].finishing+player[playerID-1].defence);
        team[teamID-1].players11--;
        printf("\e[0;92m");
        cout<<"player"<<" "<<playerID<<" "<<"removed from the team"<<" "<<teamID<<" "<<"successfully"<<endl;
        printf("\e[0m");
    }

}
//------------------------------------------random-number
int RandNumber(int MIN ,int MAX)
{
    static int Runcount=0;
    Runcount++;
    if(Runcount==1)
        srand(time(0));
    MAX++;
    double value=rand()*1.0/RAND_MAX;
    int result=value*(MAX-MIN)+MIN;
    return result;

}
//-----------------------------------------random-random-number
int RandNumber2()
{
    int sum=0;
    for(int i=0;i<10;i++)
    {
        int random=RandNumber(1,100);
        sum=sum+random;
    }
    return sum;
}
//---------------------------------------------weather
string Weather()
{
    string weather;
    int weathernum=RandNumber2()%4;
    if(weathernum+1==1)
    {
        weather="cloudy";
    }
    if(weathernum+1==2)
    {
        weather="snowy";
    }
    if(weathernum+1==3)
    {
        weather="sunny";
    }
    if(weathernum+1==4)
    {
        weather="rainy";
    }
    return weather;
}
//------------------------------------------tabe bazi doostane
int FriendlyMatch()
{
    int teamID1,teamID2;
    cin>>teamID1>>teamID2;
    if((teamID1-1)>ti || (teamID2-1)>ti)
    {
        printf("\e[0;91m");
        cout<<"team doesnt exist"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(team[teamID1-1].players11<11 || team[teamID2-1].players11<11)
    {
        printf("\e[0;91m");
        cout<<"the game can not be held due to loss of the players"<<endl;
        printf("\e[0m");
        return 0;
    }
    else
    {
        if(team[teamID1-1].power==team[teamID2-1].power)
        {
            cout<<"the match is draw"<<endl;
            return 0;
        }
        else if(team[teamID1-1].power>team[teamID2-1].power)
        {
            cout<<"team"<<" "<<teamID1<<" "<<"win"<<endl;
            return 0;
        }
        else if(team[teamID1-1].power<team[teamID2-1].power)
        {
            cout<<"team"<<" "<<teamID2<<" "<<"win"<<endl;
            return 0;
        }
    }
}
//-----------------------------------------------tabe-goal
int Goal()
{
    int randomG=RandNumber2()%100;
    if(randomG>=1 && randomG<=50)
    {
        return 1;
    }
    else if(randomG>50 && randomG<=80)
    {
        return 2;
    }
    else if(randomG>80 && randomG<=95)
    {
        return 3;
    }
    else if(randomG>95 && randomG<=100)
    {
        return RandNumber(4,10);//---------------------bishtarin goal momken=10
    }
}

//---------------------------------------------------match
int Match()
{
    int teamID1,teamID2;
    cin>>teamID1>>teamID2;
    if((teamID1-1)>=ti || (teamID2-1)>=ti)
    {
        printf("\e[0;91m");
        cout<<"team doesnt exist"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(team[teamID1-1].players11<11 || team[teamID2-1].players11<11)
    {
        printf("\e[0;91m");
        cout<<"the game can not be held due to loss of the players"<<endl;
        printf("\e[0m");
        return 0;
    }
    else
    {
        printf("\e[0;93m");
        cout<<"team"<<" "<<team[teamID1-1].name<<" "<<":"<<endl;
        printf("\e[0m");
        for(int i=0;i<=pi;i++)
        {
            if(player[i].teamIDplayer==teamID1)
            {
                cout<<player[i].name<<" "<<player[i].post<<endl;
            }
        }
        cout<<endl;
        printf("\e[0;93m");
        cout<<"team"<<" "<<team[teamID2-1].name<<" "<<":"<<endl;
        printf("\e[0m");
        for(int i=0;i<=pi;i++)
        {
            if(player[i].teamIDplayer==teamID2)
            {
                cout<<player[i].name<<" "<<player[i].post<<endl;
            }
        }
        cout<<endl;
        string weather=Weather();
        printf("\e[0;94m");
        cout<<"weather news for today is : "<<weather<<endl;
        printf("\e[0m");
        if(weather=="cloudy")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    int tempdefence,tempfinishing,tempspeed;
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    team[teamID1-1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);

                }
                if(player[i].teamIDplayer==teamID2)
                {
                    int tempdefence,tempfinishing,tempspeed;
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    team[teamID2-1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);

                }

            }

        }
        else if(weather=="snowy")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="defender")
                        player[i].tempdefence=-( player[i].tempdefence);
                    team[teamID1-1].temppower+=( player[i].tempdefence+ player[i].tempfinishing+ player[i].tempspeed);
                }
                if(player[i].teamIDplayer==teamID2)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="defender")
                        player[i].tempdefence=-( player[i].tempdefence);
                    team[teamID2-1].temppower+=( player[i].tempdefence+ player[i].tempfinishing+ player[i].tempspeed);
                }
            }

        }
        else if(weather=="sunny")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="striker")
                        player[i].tempfinishing=player[i].tempfinishing-10;
                    team[teamID1-1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
                if(player[i].teamIDplayer==teamID2)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="striker")
                        player[i].tempfinishing=player[i].tempfinishing-10;
                    team[teamID2-1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
            }

        }
        else if(weather=="rainy")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="midfielder")
                        player[i].tempfinishing=(player[i].tempfinishing/2);
                    team[teamID1-1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
                if(player[i].teamIDplayer==teamID2)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="midfielder")
                        player[i].tempfinishing=(player[i].tempfinishing/2);
                    team[teamID2-1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
            }

        }
        int goalnumber1,goalnumber2;
        if(team[teamID1-1].temppower==team[teamID2-1].temppower)
        {
            cout<<"the match is draw"<<endl;
            goalnumber1=Goal();
            cout<<"goal number of team"<<" "<<team[teamID1-1].name<<" "<<"with ID"<<" "<<teamID1<<" "<<": "<<goalnumber1<<endl;
            cout<<"goal number of team"<<" "<<team[teamID2-1].name<<" "<<"with ID"<<" "<<teamID2<<" "<<": "<<goalnumber1<<endl;
            return 0;
        }
        else if(team[teamID1-1].temppower>team[teamID2-1].temppower)
        {
            cout<<"team"<<" "<<teamID1<<" "<<"with name"<<" "<<team[teamID1-1].name<<" "<<"win"<<endl;
            goalnumber1=Goal();
            cout<<"goal number of team"<<" "<<team[teamID1-1].name<<" "<<"with ID"<<" "<<teamID1<<" "<<": "<<goalnumber1<<endl;
            goalnumber2=RandNumber(0,(goalnumber1-1));
            cout<<"goal number of team"<<" "<<team[teamID2-1].name<<" "<<"with ID"<<" "<<teamID2<<" "<<": "<<goalnumber2<<endl;
            return 0;
        }
        else if(team[teamID1-1].temppower<team[teamID2-1].temppower)
        {
            cout<<"team"<<" "<<teamID2<<" "<<"with name"<<" "<<team[teamID2-1].name<<" "<<"win"<<endl;
            goalnumber2=Goal();
            cout<<"goal number of team"<<" "<<team[teamID2-1].name<<" "<<"with ID"<<" "<<teamID2<<" "<<": "<<goalnumber2<<endl;
            goalnumber1=RandNumber(0,(goalnumber2-1));
            cout<<"goal number of team"<<" "<<team[teamID1-1].name<<" "<<"with ID"<<" "<<teamID1<<" "<<": "<<goalnumber1<<endl;
            return 0;
        }

    }
}
//------------------------------------------------timer
void timer(int sec)
{
    Sleep(sec*1000);
}
//-----------------------------------------match-for-league
int MatchForLeague(int teamID1,int teamID2)
{
    if((teamID1)>=ti || (teamID2)>=ti)
    {
        printf("\e[0;91m");
        cout<<"team doesnt exist"<<endl;
        printf("\e[0m");
        return 0;
    }
    else if(team[teamID1].players11<11 || team[teamID2].players11<11)
    {
        printf("\e[0;91m");
        cout<<"the game can not be held due to loss of the players"<<endl;
        printf("\e[0m");
        return 0;
    }
    else
    {
        printf("\e[0;93m");
        cout<<"team"<<" "<<team[teamID1].name<<" "<<":"<<endl;
        printf("\e[0m");
        for(int i=0;i<=pi;i++)
        {
            if(player[i].teamIDplayer==teamID1+1)
            {
                cout<<player[i].name<<" "<<player[i].post<<endl;
            }
        }
        cout<<endl;
        printf("\e[0;93m");
        cout<<"team"<<" "<<team[teamID2].name<<" "<<":"<<endl;
        printf("\e[0m");
        for(int i=0;i<=pi;i++)
        {
            if(player[i].teamIDplayer==teamID2+1)
            {
                cout<<player[i].name<<" "<<player[i].post<<endl;
            }
        }
        cout<<endl;
        string weather=Weather();
        printf("\e[0;94m");
        cout<<"weather news for today is : "<<weather<<endl;
        printf("\e[0m");
        if(weather=="cloudy")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    int tempdefence,tempfinishing,tempspeed;
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    team[teamID1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);

                }
                if(player[i].teamIDplayer==teamID2)
                {
                    int tempdefence,tempfinishing,tempspeed;
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    team[teamID2].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);

                }

            }

        }
        else if(weather=="snowy")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="defender")
                        player[i].tempdefence=-( player[i].tempdefence);
                    team[teamID1].temppower+=( player[i].tempdefence+ player[i].tempfinishing+ player[i].tempspeed);
                }
                if(player[i].teamIDplayer==teamID2)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="defender")
                        player[i].tempdefence=-( player[i].tempdefence);
                    team[teamID2].temppower+=( player[i].tempdefence+ player[i].tempfinishing+ player[i].tempspeed);
                }
            }

        }
        else if(weather=="sunny")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="striker")
                        player[i].tempfinishing=player[i].tempfinishing-10;
                    team[teamID1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
                if(player[i].teamIDplayer==teamID2)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="striker")
                        player[i].tempfinishing=player[i].tempfinishing-10;
                    team[teamID2].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
            }

        }
        else if(weather=="rainy")
        {
            for(int i=0;i<=pi;i++)
            {
                if(player[i].teamIDplayer==teamID1)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="midfielder")
                        player[i].tempfinishing=(player[i].tempfinishing/2);
                    team[teamID1].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
                if(player[i].teamIDplayer==teamID2)
                {
                    player[i].tempdefence=player[i].defence;
                    player[i].tempfinishing=player[i].finishing;
                    player[i].tempspeed=player[i].speed;
                    if(player[i].post=="midfielder")
                        player[i].tempfinishing=(player[i].tempfinishing/2);
                    team[teamID2].temppower+=(player[i].tempdefence+player[i].tempfinishing+player[i].tempspeed);
                }
            }

        }
        Beep(400,1000);
        int goalnumber1,goalnumber2;
        if(team[teamID1].temppower==team[teamID2].temppower)
        {
            cout<<"the match is draw"<<endl;
            goalnumber1=Goal();

            team[teamID1].goalwin+=goalnumber1;
            team[teamID1].goallose+=goalnumber1;
            team[teamID1].score++;
            team[teamID1].draws++;
            team[teamID1].goaldifference=team[teamID1].goalwin-team[teamID1].goallose;

            team[teamID2].goalwin+=goalnumber1;
            team[teamID2].goallose+=goalnumber1;
            team[teamID2].score++;
            team[teamID2].draws++;
            team[teamID2].goaldifference=team[teamID2].goalwin-team[teamID2].goallose;

            cout<<"goal number of team"<<" "<<team[teamID1].name<<" "<<"with ID"<<" "<<teamID1<<" "<<": "<<goalnumber1<<endl;
            cout<<"goal number of team"<<" "<<team[teamID2].name<<" "<<"with ID"<<" "<<teamID2<<" "<<": "<<goalnumber1<<endl;
            return 0;
        }
        else if(team[teamID1].temppower>team[teamID2].temppower)
        {
            cout<<"team"<<" "<<teamID1<<" "<<"with name"<<" "<<team[teamID1].name<<" "<<"win"<<endl;
            goalnumber1=Goal();
            cout<<"goal number of team"<<" "<<team[teamID1].name<<" "<<"with ID"<<" "<<teamID1<<" "<<": "<<goalnumber1<<endl;
            goalnumber2=RandNumber(0,(goalnumber1-1));
            cout<<"goal number of team"<<" "<<team[teamID2].name<<" "<<"with ID"<<" "<<teamID2<<" "<<": "<<goalnumber2<<endl;

            team[teamID1].goalwin+=goalnumber1;
            team[teamID1].goallose+=goalnumber2;
            team[teamID1].score+=3;
            team[teamID1].wins++;
            team[teamID1].goaldifference=team[teamID1].goalwin-team[teamID1].goallose;

            team[teamID2].goalwin+=goalnumber2;
            team[teamID2].goallose+=goalnumber1;
            team[teamID2].losses++;
            team[teamID2].goaldifference=team[teamID2].goalwin-team[teamID2].goallose;
            return 0;
        }
        else if(team[teamID1].temppower<team[teamID2].temppower)
        {
            cout<<"team"<<" "<<teamID2<<" "<<"with name"<<" "<<team[teamID2].name<<" "<<"win"<<endl;
            goalnumber2=Goal();
            cout<<"goal number of team"<<" "<<team[teamID2].name<<" "<<"with ID"<<" "<<teamID2<<" "<<": "<<goalnumber2<<endl;
            goalnumber1=RandNumber(0,(goalnumber2-1));
            cout<<"goal number of team"<<" "<<team[teamID1].name<<" "<<"with ID"<<" "<<teamID1<<" "<<": "<<goalnumber1<<endl;

            team[teamID2].goalwin+=goalnumber2;
            team[teamID2].goallose+=goalnumber1;
            team[teamID2].score+=3;
            team[teamID2].wins++;
            team[teamID2].goaldifference=team[teamID2].goalwin-team[teamID2].goallose;

            team[teamID1].goalwin+=goalnumber1;
            team[teamID1].goallose+=goalnumber2;
            team[teamID1].losses++;
            team[teamID1].goaldifference=team[teamID1].goalwin-team[teamID1].goallose;
            return 0;
        }

    }
}
//-------------------------------------------------league
int League()
{
    int arrleague[ti];
    int teams;
    for(int i=0;i<ti;i++)
    {
        if(team[i].players11==11)
        {
            static int teamcount=0;
            arrleague[teamcount]=i;
            //teams=teamcount;
            teamcount++;
            teams=teamcount;
        }
    }
    printf("\e[0;93m");
    cout<<"number of teams in this league : "<<teams<<endl;//----------teams+1 nabood teams bood
    printf("\e[0m");
    for(int i=0;i<teams;i++)
    {
        for(int j=i+1;j<teams;j++)
        {
            MatchForLeague(arrleague[i],arrleague[j]);
            //cout<<team[arrleague[i]].players11<<endl;
        }
    }
//--------------------------------------------------------------------------sort table
    for (int i=0;i<teams;i++)
        for(int j=0;j<teams-1-i;j++)
            if(team[arrleague[j]].score<team[arrleague[j+1]].score)
                swap(arrleague[j],arrleague[j+1]);

    for(int i=0;i<teams;i++)
        for(int j=0;j<teams-1-i;j++)
            if(team[arrleague[j]].score==team[arrleague[j+1]].score)
                if(team[arrleague[j]].goaldifference<team[arrleague[j+1]].goaldifference)
                    swap(arrleague[j],arrleague[j+1]);

//------------------------------------------------------------------------table
    cout<<endl<<endl;
    timer(1);
    Beep(500,500);
    printf("\e[0;92m");
    cout<<"                                        3"<<endl;
    timer(1);
    Beep(600,500);
    cout<<"                                        2"<<endl;
    timer(1);
    Beep(700,500);
    cout<<"                                        1"<<endl;
    timer(1);
    Beep(650,1000);
    cout<<"                                     READY?!";
    printf("\e[0m");
    timer(2);
    cout<<endl<<endl;
    cout<<"                                 |LEAGUE TABLE|"<<endl<<endl;
    printf("\033[0;36m");
    cout
            << left
            << setw(10)
            << "Name"
            << left
            << setw(10)
            << "Score"
            << left
            << setw(10)
            << "GoalWin"
            << left
            << setw(10)
            << "GoalLose"
            << left
            << setw(10)
            << "Wins"
            << left
            << setw(10)
            << "Losses"
            << left
            << setw(10)
            << "Draws"
            << left
            << setw(10)
            << "GoalDiffrence"
            << left
            << endl;
    printf("\033[0m");

    for (int i=0; i<teams; i++)
    {

                cout
                        << left
                        << setw(10)
                        << team[arrleague[i]].name
                        << left
                        << setw(10)
                        << team[arrleague[i]].score
                        << left
                        << setw(10)
                        << team[arrleague[i]].goalwin
                        << left
                        << setw(10)
                        << team[arrleague[i]].goallose
                        << left
                        << setw(10)
                        << team[arrleague[i]].wins
                        << left
                        << setw(10)
                        << team[arrleague[i]].losses
                        << left
                        << setw(10)
                        << team[arrleague[i]].draws
                        << left
                        << setw(10)
                        << team[arrleague[i]].goaldifference
                        << endl;


    }

//--------------------------------------------------------------sefr kardan hame chi
    for (int i=0; i<ti; i++)
    {
        for(int j=0;j<teams;j++)
        {
            if(i==arrleague[j])
            {
                team[i].score=0;
                team[i].goalwin=0;
                team[i].goallose=0;
                team[i].wins=0;
                team[i].losses=0;
                team[i].draws=0;
                team[i].goaldifference=0;
                //cout<<team[i].score<<endl;
                //cout<<team[i].goalwin<<endl;
                //cout<<team[i].goallose<<endl;
                //cout<<team[i].wins<<endl;
                //cout<<team[i].losses<<endl;
                //cout<<team[i].draws<<endl;
                //cout<<team[i].goaldifference<<endl;
            }
        }
    }


}
//-----------------------------------------tabe-chi-mikhay
int DoWhat()
{
    int n=10;
    char arrdastoor1[n];
    char arrdastoor2[n];
    printf("\033[0;33m");
    cout<<"WLCOME TO THE FOOTBALL MATCH! "<<endl<<endl;
    printf("\033[0m");
    printf("\e[0;93m");
    cout<<"What do you want to do here?"<<" "<<"Enter: "<<endl<<endl;
    printf("\e[0m");
    cout<<"{new player} to create a new player."<<endl;
    cout<<"{new team} to create a new team."<<endl;
    cout<<"{buy} to buy a new player for a team."<<endl;
    cout<<"{sell} to remove a player from a team."<<endl;
    cout<<"{friendlyMatch} to start a friendly match between two teams."<<endl;
    cout<<"{Match} to start a real match between two teams."<<endl;
    cout<<"{BeginLeague} to start a league."<<endl;
    do
    {
        cin>>arrdastoor1;
        if(strcmp(arrdastoor1,"new")==0)
        {
            cin>>arrdastoor2;
            if(strcmp(arrdastoor2,"player")==0)
                CreatePlayer();
            if(strcmp(arrdastoor2,"team")==0)
                CreateTeam();
        }
        if(strcmp(arrdastoor1,"buy")==0)
            BuyPlayer();
        if(strcmp(arrdastoor1,"sell")==0)
            SellPlayer();
        if(strcmp(arrdastoor1,"friendlyMatch")==0)
            FriendlyMatch();
        if(strcmp(arrdastoor1,"Match")==0)
            Match();
        if(strcmp(arrdastoor1,"BeginLeague")==0)
            League();
    }while(strcmp(arrdastoor1,"end")!=0);
    if(strcmp(arrdastoor1,"end")==0)
        return 0;
}
//-----------------------------------------

int main()
{
    system("cls");
    DoWhat();

    return 0;
}
