#include <bits/stdc++.h>
using namespace std;
class ClubStats {
private:
    queue<char>form;
    string name;
    int mp, gd, pts;
public:
    ClubStats();
    ClubStats(string name);
    ClubStats(string name, int mp, int gd, int pts, queue<char>  form);
    void getStats() const;
    string getName() const;
    int getPoints() const;
    int getGD() const;
    void add(int goals1, int goals2);
};

class player{
protected:
    string name;
    int age;
    double height;
    char foot;
    string nationality;
    string position;
    string team;
    pair<int, int> ga;
    map<string, int>awards;
public:
    player();
    player(string name, int age, double height, char foot, string nationality, string
    position, string team, pair<int, int>ga, map<string, int>awards);
    void showPlayerInformation();
    void setPlayerInformation();
    string getName();
};
class u_player : public player{
    int ageGroup;
    char teamLevel;
public:
    using player::player;
    u_player();
    u_player(string& name, int& age, double& height, char& foot, string& nationality, string& position, string& team, pair<int, int>&ga, map<string, int>&awards, int ageGroup, char teamLevel);
    void showU_PlayerInformation();
    void setU_PlayerInformation();
    string getU_PlayerName();
};

class manager{
    string name;
    string team;
    string nationality;
    map<string, int>trophies;
public:
    manager();
    manager(string name, string team, string nationality, map<string, int>trophies);
    void showManagerInformation();
    void setManagerInformation();
};

class SquadCompare {
public:
    bool operator() (player a, player b) const;
};
class Match{
    string firstTeam;
    string secondTeam;
    int goals1;
    int goals2;
    vector<string>goalScorers;
public:
    Match();
    Match(string firstTeam, string secondTeam);
    Match(string firstTeam, string secondTeam, int goals1, int goals2, vector<string>goalScorers);
    string get1stTeamName() const;
    string get2ndTeamName() const;
    int get1stTeamGoals() const;
    int get2ndTeamGoals() const;
    vector<string>getGoalScorers() const;
};

class leagueStatsComp {
public:
    bool operator() (ClubStats a, ClubStats b) const;
};
class Team;
class TeamCompare{
public:
    bool operator() (Team a, Team b) const;
};

class Competition{
protected:
    string name;
    string country;
    map<string,int>topScorers;
    multiset<Team, TeamCompare>teams;
public:
    Competition();
    Competition(string name, string country, map<string,int>topScorers);
    void getTopScorers();
    void deleteClub(string &name);
    void eraseTeam(Team& club);
    multiset<Team, TeamCompare>getTeams();
};
class Team {
private:
    string name, stadium, foundingDate, country, league;
    ClubStats stats;
    map<string, int> trophies;
    multiset<player,SquadCompare> players;
public:
    Team();
    Team(string name, string stadium, string foundingDate, string country, ClubStats stats,
         map<string,int> trophies,string league);
    string getName() const;
    void getInfromation() const;
    void setInformation();
    void getPlayer(string &name) const;
    void showSquad();
    void transferPlayerIn(player& name);
    void transferPlayerOut(player& name);

};
class League: public Competition{
private:
    multiset<ClubStats, leagueStatsComp>leagueStats;
public:
    using Competition::Competition;
    string getName() const;
    Team getClub(string &name)const;
    void addMatch(const Match& match);
    void getStandings() const;
    void addPlayerToTeam(Team in, Team out , player &name);
    void addClub(Team club);

    void addToStats(Team club);
    void deleteTeam(string &clubName);

    void addTeam(Team club);
};

class Cup : public Competition{
    vector<vector<Match>>rounds;
    int round = 0;
    string winner = "N/A";
public:
    using Competition::Competition;
    void setRounds();
    void generateMatches();
    void getTeams() const;
    void getRounds() const;
    void toNextRound();
    void predictCompetition();
    void addClub(Team club);

    bool checkRunningCup();

    void resetCup();
};
