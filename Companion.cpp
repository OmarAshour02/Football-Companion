#include "Companion.h"
#include <random>
// Club stats

ClubStats::ClubStats() {
    name = "N/A";
    mp = 0;
    gd = 0;
    pts = 0;
    form = {};
}
ClubStats::ClubStats(string name) {
    this->name = name;
    mp = 0;
    gd = 0;
    pts = 0;
    form = {};
}
ClubStats::ClubStats(string name, int mp, int gd, int pts, queue<char> form) {
    this->name = name;
    this->mp = mp;
    this->gd = gd;
    this->pts = pts;
    this->form = form;
}
void ClubStats::getStats() const {
    cout << name << "\t" << mp << "\t" << gd << "\t"  << pts << "\t";
    queue <char> temp = form;
    while(!temp.empty()) {
        cout << temp.front();
        temp.pop();
    }
    cout << '\n';
}
int ClubStats::getPoints() const {
    return pts;
}
int ClubStats::getGD() const {
    return gd;
}
string ClubStats::getName()const {
    return name;
}
void ClubStats::add(int goals1, int goals2){
    if(goals1 > goals2)
        pts += 3, form.push('W');
    else if(goals1 == goals2)
        pts++, form.push('D');
    else form.push('L');
    if(form.size() > 5)
        form.pop();
    gd += goals1 - goals2;
    mp++;
}



player::player(){
    name = nationality = team = position = "N/A";
    age = 0;
    height = 0.0;
    ga = {0, 0};
    foot = ' ';
}
player::player(string name, int age, double height, char foot, string nationality,
               string position, string team, pair<int, int>ga, map<string, int>awards) {
    for(auto & x : name)
        x = tolower(x);
    this->name = name;
    this->age = age;
    this->height = height;
    this->foot = foot;
    this->nationality = nationality;
    this->position = position;
    this->team = team;
    this->ga = ga;
    this->awards = awards;
}
void player::showPlayerInformation() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years old\n";
    cout << "Height: " << height << " CM\n";
    cout << "Nationality: " << nationality << endl;
    cout << "Position: " << position << endl;
    cout << "Team: " << team << endl;
    cout << "Goals: " << ga.first << endl;
    cout << "Assists: " << ga.second << endl;
    cout << "Awards:\n";
    for(auto& [name, quantity] : awards)
        cout << quantity << " x " << name << endl;
}
void player::setPlayerInformation() {
    char Cont = 'y';
    while(tolower(Cont) == 'y'){
        cout << "What do you want to edit?\n";
        cout << "1. Name\n2. Age\n3. Height\n4. Nationality\n5. Position\n6. Club\n7. Goals\n8. Assists\n9. Awards\n";
        cout << "Enter Choice: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                for(auto & x : name)
                    x = tolower(x);
                break;
            case 2:
                cout << "Enter new age: ";
                cin >> age;
                break;
            case 3:
                cout << "Enter new height: ";
                cin >> height;
                break;
            case 4:
                cout << "Enter new nationality: ";
                cin >> nationality;
                break;
            case 5:
                cout << "Enter new position: ";
                cin >> position;
                break;
            case 6:
                cout << "Enter new team: ";
                cin.ignore();
                getline(cin, team);
                break;
            case 7:
                cout << "Enter new number of goals: ";
                cin >> ga.first;
                break;
            case 8:
                cout << "Enter new number of assists: ";
                cin >> ga.second;
                break;
            case 9:{
                cout << "1. Add new award\n2. Delete new award\n3. Change quantity\n";
                int awardChoice;            cin >> awardChoice;
                string awardName;
                int awardQuantity;
                if(awardChoice == 1){
                    cout << "Enter award name: ";
                    cin.ignore();
                    getline(cin, awardName);
                    cout << "Enter quantity: ";
                    cin >> awardQuantity;
                    awards[awardName] = awardQuantity;
                }else if(awardChoice == 2){
                    cout << "Enter award name: ";
                    cin.ignore();
                    getline(cin, awardName);
                    if(awards[awardName])
                        awards.erase(awardName);
                    else cout << "Invalid award!\n";
                }else{
                    cout << "Enter award name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter new quantity: ";
                    cin >> awardQuantity;
                    if(awards[awardName])
                        awards[awardName] = awardQuantity;
                    else cout << "Invalid award!\n";
                }
            }
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
        showPlayerInformation();
        cout << "Do you want to continue editing this player(Y\\N)? ";
        cin >> Cont;
    }
}
string player::getName() {
    return name;
}


u_player::u_player() : u_player::player(){
    ageGroup = 0;
    teamLevel = ' ';
}
u_player::u_player(string &name, int &age, double &height, char &foot, string &nationality, string &position, string &team, pair<int, int> &ga, map<string, int> &awards,
                   int ageGroup, char teamLevel) : u_player(name, age, height, foot, nationality, position, team, ga, awards) {
    this->ageGroup = ageGroup;
    this->teamLevel = teamLevel;
}
void u_player::showU_PlayerInformation() {
    u_player::showPlayerInformation();
    cout << "Age group: U-" << ageGroup << endl;
    cout << "Team level: " << teamLevel << endl;
}
void u_player::setU_PlayerInformation() {
    char Cont = 'y';
    while(tolower(Cont) == 'y'){
        cout << "What do you want to edit?\n";
        cout << "1. Name\n2. Age\n3. Height\n4. Nationality\n5. Position\n6. Club\n7. Goals\n8. Assists\n9. Awards\n10. Age Group\n11. Team level\n";
        cout << "Enter Choice: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                break;
            case 2:
                cout << "Enter new age: ";
                cin >> age;
                break;
            case 3:
                cout << "Enter new height: ";
                cin >> height;
                break;
            case 4:
                cout << "Enter new nationality: ";
                cin >> nationality;
                break;
            case 5:
                cout << "Enter new position: ";
                cin >> position;
                break;
            case 6:
                cout << "Enter new team: ";
                cin.ignore();
                getline(cin, team);
                break;
            case 7:
                cout << "Enter new number of goals: ";
                cin >> ga.first;
                break;
            case 8:
                cout << "Enter new number of assists: ";
                cin >> ga.second;
                break;
            case 9:{
                cout << "1. Add new award\n2. Delete award\n3. Change quantity\n";
                int awardChoice;            cin >> awardChoice;
                string awardName;
                int awardQuantity;
                if(awardChoice == 1){
                    cout << "Enter award name: ";
                    cin.ignore();
                    getline(cin, awardName);
                    cout << "Enter quantity: ";
                    cin >> awardQuantity;
                    awards[awardName] = awardQuantity;
                }else if(awardChoice == 2){
                    cout << "Enter award name: ";
                    cin.ignore();
                    getline(cin, awardName);
                    if(awards[awardName])
                        awards.erase(awardName);
                    else cout << "Invalid award!\n";
                }else{
                    cout << "Enter award name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter new quantity: ";
                    cin >> awardQuantity;
                    if(awards[awardName])
                        awards[awardName] = awardQuantity;
                    else cout << "Invalid award!\n";
                }
            }
                break;
            case 10:
                cout << "Enter new age group: ";
                cin >> ageGroup;
                break;
            case 11:
                cout << "Enter new team Level(A, B or C): ";
                int temp;               cin >> temp;
                temp = toupper(temp);
                if(temp != 'A' && temp != 'B' && temp != 'C')
                    cout << "Invalid level!\n";
                else ageGroup = temp;
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
        showU_PlayerInformation();
        cout << "Do you want to continue editing this player(Y\\N)? ";
        cin >> Cont;
    }
}
string u_player::getU_PlayerName() {
    return name;
}


manager::manager(){
    name = team = nationality = "N/A";
    trophies.clear();
}
manager::manager(string name, string team, string nationality, map<string, int> trophies) {
    this->name = name;
    this->nationality = nationality;
    this->team = team;
    this->trophies = trophies;
}
void manager::showManagerInformation(){
    cout << "Name: " << name << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "Team: " << team << endl;
    if(trophies.size()){
        cout << "Trophies: \n";
        for(auto &[Name, quantity] : trophies)
            cout << quantity << "x " << Name << endl;
    }
}
void manager::setManagerInformation() {
    char Cont = 'y';
    while (tolower(Cont) == 'y') {
        cout << "What do you want to edit?\n";
        cout << "1. Name\n2. Nationality\n3. Team\n4. Trophies\n";
        cout << "Enter Choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                break;
            case 2:
                cout << "Enter new nationality: ";
                cin >> nationality;
                break;
            case 3:
                cout << "Enter new team: ";
                cin.ignore();
                getline(cin, team);
                break;
            case 4: {
                cout << "1. Add new trophy\n2. Delete trophy\n3. Change quantity\n";
                int trophyChoice;
                cin >> trophyChoice;
                string trophyName;
                int trophyQuantity;
                if (trophyChoice == 1) {
                    cout << "Enter trophy name: ";
                    cin.ignore();
                    getline(cin, trophyName);
                    cout << "Enter quantity: ";
                    cin >> trophyQuantity;
                    trophies[trophyName] = trophyQuantity;
                } else if (trophyChoice == 2) {
                    cout << "Enter trophy name: ";
                    cin.ignore();
                    getline(cin, trophyName);
                    if (trophies[trophyName])
                        trophies.erase(trophyName);
                    else cout << "Invalid award!\n";
                } else {
                    cout << "Enter trophy name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter new quantity: ";
                    cin >> trophyQuantity;
                    if (trophies[trophyName])
                        trophies[trophyName] = trophyQuantity;
                    else cout << "Invalid trophy!\n";
                }
            }
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
        showManagerInformation();
        cout << "Do you want to continue editing this manager(Y\\N)? ";
        cin >> Cont;
    }
    Cont = 'y';
}



bool SquadCompare::operator()(player a, player b) const {
    return a.getName() < b.getName();
}
Team::Team(string name, string stadium, string foundingDate, string country, ClubStats stats,
           map<string,int> trophies, string league) : name(name), stadium(stadium),
                                                      foundingDate(foundingDate),country(country), stats(stats), trophies(trophies), league(league){}
Team::Team() {
    name = stadium = foundingDate = country = league = "N/A";
    trophies = map<string, int>();
    stats = ClubStats();
}
string Team::getName() const {
    return name;
}
void Team::getInfromation() const {
    char c = 'y';
    while(c == 'y') {
        cout << "Please choose number of the information of the club you need to represent : \n";
        cout << "1 : Club's name\n";
        cout << "2 : Club's stadium\n";
        cout << "3 : Club's founding date\n";
        cout << "4 : Club's country\n";
        cout << "5 : Club's trophies\n";
        cout << "6 : Club's league\n";
        cout << "7 : All Club's information\n";
        cout << "8 : Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Club's name : " << name << '\n';
                break;
            }
            case 2: {
                cout << "Club's stadium : " << stadium << '\n';
                break;
            }
            case 3: {
                cout << "Club's founding date : " << foundingDate << '\n';
                break;
            }
            case 4: {
                cout << "Club's country : " << country << '\n';
                break;
            }
            case 5: {
                if ((int) trophies.size()) {
                    cout << "Club's trophies : \n";
                    for(pair<string, int> trophy : trophies)
                        cout << trophy.second << "x " << trophy.first << endl;
                } else {
                    cout << "The club has no trophies\n";
                }
                break;
            }
            case 6: {
                cout << "Club's league : " << league << '\n';
                break;
            }
            case 7: {
                cout << "Club's name : " << name << '\n';
                cout << "Club's stadium : " << stadium << '\n';
                cout << "Club's founding date : " << foundingDate << '\n';
                cout << "Club's country : " << country << '\n';
                if ((int) trophies.size()) {
                    cout << "Club's trophies : \n";
                    for(pair<string, int> trophy : trophies) {
                        cout <<"The club won "<<trophy.first << " " << trophy.second << " times\n";
                    }
                } else {
                    cout << "The club has no trophies\n";
                }
                cout << "Club's league : " << league << '\n';
                break;
                default:
                    cout << "Enter a number from 1 - 8 \n";
                break;
            }
            case 8 :
                return;
        }
        cout << "Do you want to know any other information ? (y/n)\n";
        cin >> c;
    }
}
void Team::setInformation() {
    char c = 'y';
    while(c == 'y') {
        cout << "Please choose number of the information of the club you need to change : \n";
        cout << "1 : Club's name\n";
        cout << "2 : Club's stadium\n";
        cout << "3 : Club's founding date\n";
        cout << "4 : Club's country\n";
        cout << "5 : Add a club Trophies\n";
        cout << "6 : Club's league\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                string newName;
                cin >> newName;
                name = newName;
                cout << "Club's name is changed to " << name << " successfully ! \n";
                break;
            }
            case 2: {
                string newStadium;
                cin >> newStadium;
                stadium = newStadium;
                cout << "Club's stadium is changed to " << stadium << " successfully ! \n";
                break;
            }
            case 3: {
                string newFoundingDate;
                cin >> newFoundingDate;
                foundingDate = newFoundingDate;
                cout << "Club's founding date is changed to " << foundingDate << " successfully ! \n";
                break;
            }
            case 4: {
                string newCountry;
                cin >> newCountry;
                country = newCountry;
                cout << "Club's country is changed to " << country << " successfully ! \n";
                break;
            }
            case 5: {
                cout << "Enter trophy name: \n";
                string trophy;
                cin >> trophy;
                cout << "How many trophies did the club win?\n";
                int quantity;
                cin >> quantity;
                trophies[trophy] = quantity;
                break;
            }
            case 6: {
                // Emad
                break;
            }
            default : {
                cout << "Enter a number between 1 - 6 \n";
                break;
            }
        }
        cout << "Do you want to change any other information ? (y/n)\n";
        cin >> c;
    }
}
void Team::transferPlayerIn(player& newPlayer) {
    players.insert(newPlayer);
}
void Team::transferPlayerOut(player& name) {
    players.erase(name);
}
void Team::showSquad() {
    for(auto x : players){
        cout << x.getName() << '\n';
    }
}

void Team::getPlayer(string &name) const {
    for(auto & x : name)
        x = tolower(x);
    for(auto  x : players){
        string tmp = x.getName();
        cout << tmp << '\n';
        for(auto & y : tmp)
            y = tolower(y);
        if(tmp == name){
            x.showPlayerInformation();
            return;
        }
    }
    cout << "Player is not found\n";
}


Match::Match() {
    firstTeam = "N/A";
    secondTeam = "N/A";
    goals1 = 0;
    goals2 = 0;
    goalScorers.clear();
}
Match::Match(string firstTeam, string secondTeam) : firstTeam(firstTeam), secondTeam(secondTeam){}
Match::Match(string firstTeam, string secondTeam, int goals1, int goals2, vector<string> goalScorers) {
    this->firstTeam = firstTeam;
    this->secondTeam = secondTeam;
    this->goals1 = goals1;
    this->goals2 = goals2;
    this->goalScorers = goalScorers;
}
string Match:: get1stTeamName() const{
    return firstTeam;
}
string Match:: get2ndTeamName() const{
    return secondTeam;
}
int Match::get1stTeamGoals() const{
    return goals1;
}
int Match::get2ndTeamGoals() const{
    return goals2;
}
vector<string> Match::getGoalScorers() const{
    return goalScorers;
};

bool leagueStatsComp::operator()(ClubStats a, ClubStats b) const {
    if(a.getPoints() == b.getPoints())
        return a.getGD() > b.getGD();
    return a.getPoints() > b.getPoints();
}
Competition::Competition() {
    name = country = "N/A";
    topScorers = map<string,int>();
}
bool TeamCompare::operator()(Team a, Team b) const {
    return a.getName() < b.getName();
}
Competition::Competition(string name, string country, map<string,int>topScorers): name(name),
                                                                                  country(country), topScorers(topScorers) {
}
void Competition :: getTopScorers() {
    cout << "------------------------\n";
    cout << name << " top goalscorers: \n";
    int rank = 1;
    vector<pair<int, string>>v;
    for(auto &i : topScorers)
        v.push_back({i.second, i.first});
    sort(v.rbegin(), v.rend());
    for(auto &i : v)
        cout << rank++ << ".\t" << i.second << "\t" << i.first << endl;
}
void League :: addClub(Team club){
    leagueStats.insert(ClubStats(club.getName()));
    teams.insert(club);
}

void Competition :: deleteClub(string &clubName) {
    for(auto& x : clubName)
        x = tolower(x);
    for(const auto& club : teams) {
        string x = club.getName();
        for(auto& i : x)
            i = tolower(i);
        if (x == clubName) {
            teams.erase(club);
            return;
        }
    }
    cout << "Invalid club name\n";
}
void League:: deleteTeam(string &clubName){
    deleteClub(clubName);
    int pos(0);
    for(const auto &club : leagueStats) {
        string Name = club.getName();
        for(auto& i : Name)
            i = tolower(i);
        if (Name == clubName) {
            leagueStats.erase(next(leagueStats.begin(), pos));
            return;
        }
        pos++;
    }
}
void League::addMatch(const Match& match) {
    string first = match.get1stTeamName();
    string second = match.get2ndTeamName();
    for(auto & x : first)
        x = tolower(x);
    for(auto &x : second)
        x = tolower(x);
    if(first == second)
        return void(cout << "Both teams are the same!\n");
    ClubStats temp1, temp2;
    bool check1 = false, check2 = false;
    int pos1(0),pos2(0),curr(0);
    for(auto &x : leagueStats){
        string currName = x.getName();
//        cout << currName << '\n';
        for(auto & x : currName)
            x = tolower(x);
        if (currName == first)
            check1 = true, pos1 = curr;
        else if (currName == second)
            check2 = true;
        curr++;
    }
    if(!check1) return void(cout << "Invalid team: " << match.get1stTeamName()<< endl);
    if(!check2) return void(cout << "Invalid team: " << match.get2ndTeamName() << endl);
    for(auto i : leagueStats) {
        string currName = i.getName();
        for(auto & x : currName)
            x = tolower(x);

        if (currName == first)
            temp1 = i;
        else if (currName == second)
            temp2 = i;
    }
    leagueStats.erase(next(leagueStats.begin(),pos1));
    curr = 0;
    for(auto &x : leagueStats){
        string currName = x.getName();
        for(auto & x : currName)
            x = tolower(x);
        if (currName == second)
            pos2 = curr;
        curr++;
    }
    leagueStats.erase(next(leagueStats.begin(),pos2));
    temp1.add(match.get1stTeamGoals(), match.get2ndTeamGoals());
    temp2.add(match.get2ndTeamGoals(), match.get1stTeamGoals());
    leagueStats.insert(temp1);
    leagueStats.insert(temp2);
    for(const auto& i : match.getGoalScorers())
        topScorers[i]++;
}
void League::getStandings() const {
    cout << "------------------------\n";
    cout << name << " standings: \n";
    cout << "Pos\tNam\tMP\tgd\tpts\tform\n";
    int rank = 1;
    for(auto &i : leagueStats)
        cout << rank++ << ".\t", i.getStats();
}
string League::getName() const {
    return name;
}
void League:: addTeam(Team club){
    teams.insert(club);
}
void League::addToStats(Team club){
    leagueStats.insert(ClubStats(club.getName()));
}

void League::addPlayerToTeam(Team in, Team out , player &name) {
    in.transferPlayerIn(name);
    out.transferPlayerOut(name);
}

Team League::getClub(string &name) const {
    for(auto & x : name)
        x = tolower(x);
    for(auto & x : teams){
        string teamName = x.getName();
        for(auto &y : teamName)
            y = tolower(y);
        if(teamName == name)
            return x;
    }
    Team team;
    cout << "Club Not found\n";
    return team;
}



multiset<Team, TeamCompare> Competition::getTeams(){
    return teams;
}

void Competition::eraseTeam(Team& club) {
    teams.erase(teams.find(club));
}


// Why it doesn't work
void Cup::setRounds(){
    rounds.assign((int)log2(teams.size()),vector<Match>());
}
void Cup::resetCup(){
    rounds.clear();
    winner = "N/A";
    round = 0;
    topScorers.clear();
    teams.clear();
}
void Cup::generateMatches() {
    if(rounds.empty()){
        cout << "You need to set rounds size first !\n";
        return;
    }
    if(log2(teams.size()) != (int) log2(teams.size())){
        cout << "Invalid number of teams !\n";
        return;
    }
    srand(unsigned(time(nullptr)));
    vector<Team> cupTeams(teams.begin(),teams.end());
    shuffle(cupTeams.begin(),cupTeams.end(),mt19937(random_device()()));
    for(int i = 0; i < (int)cupTeams.size(); i += 2){
        rounds[round].emplace_back(cupTeams[i].getName(), cupTeams[i + 1].getName());
    }
}
void Cup::getTeams() const {
    if(log2(teams.size()) != (int) log2(teams.size())){
        cout << "Invalid number of teams !\n";
        return;
    }
    cout << "Teams at the " << name << " are : \n";
    for(const auto& x : teams)
        cout <<"- " << x.getName() << "\n";
}
bool Cup::checkRunningCup(){
    return (winner != "NA" or rounds.empty());
}
void Cup::getRounds() const {
    if(log2(teams.size()) != (int) log2(teams.size())){
        cout << "Invalid number of teams !\n";
        return;
    }
    if(winner != "N/A"){
        cout << winner << " is the winner of " << name << " ! \n";
        return;
    }
    cout << '\n';
    for(auto & i : rounds){
        if(!i.empty()){
            if (i.size() * 2 == 2)
                cout << "Final";
            else if(i.size() * 2 == 4)
                cout << "Semi-final";
            else if(i.size() * 2 == 8)
                cout << "Quarter-final";
            else
                cout << "Round of 16";
            cout << " of the " << name << '\n';
            for(auto & j : i){
                cout << j.get1stTeamName() << " X " << j.get2ndTeamName() << '\n';
            }
        }
        cout << '\n';
    }
}
void Cup::toNextRound() {
    if(log2(teams.size()) != (int) log2(teams.size())){
        cout << "Invalid number of teams !\n";
        return;
    }
    if(round == log2((int)teams.size())){
        cout << "No more rounds to proceed\n";
        return;
    }
    if(rounds.empty() or rounds[0].empty()){
        cout << "No tournament to start\n";
        return;
    }
    int teamsQualified = 0;
    string firstTeam, secondTeam;
    for(auto & i : rounds[round]){
        int goals1 = 0, goals2 = 0;
        cout << "The result of : " << i.get1stTeamName() << " X " << i.get2ndTeamName() << '\n';
        cout << "Enter the goals for " << i.get1stTeamName() << ": ";
        cin >> goals1;
        cout << "Enter the goals for " << i.get2ndTeamName() << ": ";
        cin >> goals2;
        while(goals1 == goals2){
            cout << "The score can't be equal ! \n";
            cout << "Enter the goals for " << i.get1stTeamName() << ": ";
            cin >> goals1;
            cout << "Enter the goals for " << i.get2ndTeamName() << ": ";
            cin >> goals2;
        }
        cout << "Enter goal scorers : \n";
        cin.ignore();
        for(int j = 0; j < goals1 + goals2; j++){
            string name;
            getline(cin,name);
            topScorers[name]++;
        }
        if(!teamsQualified){
            if(goals1 > goals2)
                firstTeam = i.get1stTeamName();
            else
                firstTeam = i.get2ndTeamName();
        }
        else{
            if(goals1 > goals2)
                secondTeam = i.get1stTeamName();
            else
                secondTeam = i.get2ndTeamName();
        }
        if(round == log2(teams.size()) - 1){
            if(goals1 > goals2)
                winner = i.get1stTeamName();
            else
                winner = i.get2ndTeamName();
        }
        teamsQualified++;
        if(teamsQualified == 2){
            rounds[round + 1].emplace_back(firstTeam, secondTeam);
            teamsQualified = 0;
        }
    }
    round++;
}
void Cup::predictCompetition() {
    if(log2(teams.size()) != (int) log2(teams.size())){
        cout << "Invalid number of teams !\n";
        return;
    }
    if(rounds.empty() or rounds[0].empty()){
        cout << "No tournament to start\n";
        return;
    }
    srand(time(nullptr));
    vector<vector<Match>>temp = rounds;
    int teamsQualified = 0;
    string theWinner;
    string firstTeam, secondTeam;
    int tmpRounds = 0;
    for(int i = 0; i < (int)log2(teams.size()); i++){
        if(!temp[i].empty()) {
            cout << "The results for round " << temp[i].size() * 2 << " are\n";
            for (auto &j: temp[i]) {
                int goals1 = rand() % 5, goals2 = rand() % 5;
                while (goals1 == goals2)
                    goals1 = rand() % 5, goals2 = rand() % 5;
                cout << j.get1stTeamName() << " " << goals1 << " : " << goals2 << " " << j.get2ndTeamName() << '\n';
                if (!teamsQualified) {
                    if (goals1 > goals2)
                        firstTeam = j.get1stTeamName();
                    else
                        firstTeam = j.get2ndTeamName();
                } else {
                    if (goals1 > goals2)
                        secondTeam = j.get1stTeamName();
                    else
                        secondTeam = j.get2ndTeamName();
                }
                if (temp[i].size() == 1){
                    cout << "\n------------------------\n";
                    if (goals1 > goals2)
                        theWinner = j.get1stTeamName();
                    else
                        theWinner = j.get2ndTeamName();
                    cout << theWinner << " Won the " << name << '\n';
                    cout << "------------------------\n";

                    return;
                }
                teamsQualified++;
                if (teamsQualified == 2) {
                    temp[tmpRounds + 1].push_back(Match(firstTeam, secondTeam));
                    teamsQualified = 0;
                }
            }
            cout << '\n';
        }
        tmpRounds++;
    }
}

void Cup::addClub(Team club) {
    teams.insert(club);
}



