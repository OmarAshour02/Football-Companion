#include "Companion.h"

League laliga, bundesliga, seriea, premiereleague, ligue1;
Cup worldCup, euros, copaAmerica;

Team makeClub(string leagueName) {
    cout << "Enter club's name : ";
    string name;
    cin.ignore();
    getline(cin, name);
//    cin.ignore();
    cout << "Enter club's country : ";
    string country;
    cin >> country;
    cout << "Enter club's stadium : ";
    string stadium;
    cin.ignore();
    getline(cin, stadium);
    cout << "Enter club's founding date (DD/MM/YYYY): ";
    string foundingDate;
    cin >> foundingDate;
    cout << "How many trophies did the team win : ";
    int trophiesCount;
    cin >> trophiesCount;
    map<string, int> trophies;
    for (int i = 0; i < trophiesCount;) {
        cout << "Enter trophy name : ";
        string trophyName;
        cin.ignore();
        getline(cin, trophyName);
        cout << "How many times did the team win " << trophyName << "? ";
        int num;
        cin >> num;
        if (i + num <= trophiesCount)
            i += num;
        else {
            cout << "Invalid amount!\n";
            continue;
        }
        trophies[trophyName] += num;
    }
    return {name, stadium, foundingDate, country,
            ClubStats(), trophies, leagueName};
}

Match makeMatch() {
    string firstTeam, secondTeam;
    cout << "First team's name : ";
    cin.ignore();
    getline(cin, firstTeam);
    cout << "Second team's name : ";
    getline(cin, secondTeam);
    int goals1, goals2;
    cout << "How many goals did " << firstTeam << " score ? ";
    cin >> goals1;
    cout << "How many goals did " << secondTeam << " score ? ";
    cin >> goals2;
    vector<string> goalScorers;
    if (!(goals1 >= 0 and goals2 >= 0)) {
        cout << "Enter positive values\n";
        return {};
    }
    if (goals1 + goals2 > 0) {
        cin.ignore();
        cout << "Enter goalscorers : \n";
        for (int i = 0; i < goals1 + goals2; i++) {
            string name;
            getline(cin, name);
            goalScorers.push_back(name);
        }
    }
    return {firstTeam, secondTeam, goals1, goals2, goalScorers};
}

player makePlayer() {
    cout << "Enter player's name : ";
    string name;
    getline(cin, name);
    cout << "Enter player's age : ";
    int age;
    cin >> age;
    cout << "Enter player's height : ";
    double height;
    cin >> height;
    char foot;
    cout << "Enter player's foot (R/L): ";
    cin >> foot;
    foot = toupper(foot);
    while (!(foot == 'L' or foot == 'R')) {
        cout << "Enter player's foot (R/L): ";
        cin >> foot;
        foot = toupper(foot);
    }
    cout << "Enter player's nationality: ";
    string nationality;
    cin >> nationality;
    cout << "Enter player's position: ";
    string position;
    cin >> position;
    cout << "Enter player's team: ";
    string team;
    cin >> team;
    cout << "Enter player's career goals: ";
    int goals;
    cin >> goals;
    cout << "Enter player's career assists: ";
    int assists;
    cin >> assists;
    cout << "How many awards does he have? ";
    int awardCount;
    cin >> awardCount;
    map<string, int> awards;
    for (int i = 0; i < awardCount;) {
        cout << "Enter award's name: ";
        string awardName;
        cin >> awardName;
        cout << "Enter award's quantity: ";
        int awardQuantity;
        cin >> awardQuantity;
        if (i + awardQuantity <= awardCount)
            i += awardQuantity;
        else {
            cout << "Invalid amount!\n";
            continue;
        }
        awards[awardName] = awardQuantity;
    }
    return {name, age, height, foot, nationality, position, team, {goals, assists}, awards};
}

void operations(League &league) {
    string num = "0";
    while (true) {
        cout
                << "1. Show standings\n2. Show topscorers\n3. Add match\n4. Add club\n5. Delete club\n6. Add player\n7. View player\n"
                   "8. View clubs\n9. View club's information\n";
        cout << "10. Exit\n";
        cin >> num;
        if (num == "1")
            league.getStandings();
        else if (num == "2")
            league.getTopScorers();
        else if (num == "3")
            league.addMatch(makeMatch());
        else if (num == "4")
            league.addClub(makeClub(league.getName()));
        else if (num == "5") {
            cout << "Enter club's name : ";
            string name;
            cin.ignore();
            getline(cin, name);
            league.deleteTeam(name);
        } else if (num == "6") {
            cout << "Enter club's name : \n";
            string name;
            cin.ignore();
            getline(cin, name);
            Team team = league.getClub(name);
            if (team.getName() == "N/A")
                continue;
            player newPlayer = makePlayer();
            league.deleteClub(name);
            team.transferPlayerIn(newPlayer);
            league.addTeam(team);
            team.transferPlayerIn(newPlayer);
        } else if (num == "7") {
            cout << "Enter club's name that the player plays in : \n";
            string name;
            cin.ignore();
            getline(cin, name);
            Team team = league.getClub(name);
            if (team.getName() == "N/A")
                continue;
            else {
                cout << "Enter the player's name : ";
                string playerName;
                getline(cin, playerName);
                team.getPlayer(playerName);
            }
        } else if (num == "8") {
            multiset<Team, TeamCompare> leagueTeams = league.getTeams();
            for (auto &x: leagueTeams) {
                cout << x.getName() << '\n';
            }
        }
            /***/
        else if (num == "9") {
            cout << "Enter club's name : \n";
            string name;
            cin.ignore();
            getline(cin, name);
            Team team = league.getClub(name);
            if (team.getName().empty())
                cout << "Team not found \n";
            else
                team.getInfromation();
        } else if (num == "10") {
            return;
        } else {
            cout << "Enter a number between 1 - 10\n";
        }
    }
}

void clubFootball() {
    char num = '0';
    while (num != '6') {
        cout << "Which league do you want to access ?\n";
        cout << "1. La Liga\n2. BundesLiga\n3. SerieA\n4. Premiere League\n5. Ligue 1\n6. Exit\n";
        cin >> num;
        switch (num) {
            case '1':
                operations(laliga);
                break;
            case '2':
                operations(bundesliga);
                break;
            case '3':
                operations(seriea);
                break;
            case '4':
                operations(premiereleague);
                break;
            case '5':
                operations(ligue1);
                break;
            case '6':
                return;
            default:
                cout << "Enter a number between 1 - 5\n";
                break;
        }
    }
}


Team makeNation() {
    cout << "Enter nation's name : \n";
    string s;
    cin >> s;
    cout << "How many trophies did the nation win : ";
    int trophiesCount;
    cin >> trophiesCount;
    map<string, int> trophies;
    for (int i = 0; i < trophiesCount;) {
        cout << "Enter trophy name : ";
        string trophyName;
        cin.ignore();
        getline(cin, trophyName);
        cout << "How many times did the nation win " << trophyName << "? ";
        int num;
        cin >> num;
        if (i + num <= trophiesCount)
            i += num;
        else {
            cout << "Invalid amount!\n";
            continue;
        }
        trophies[trophyName] += num;
    }
    cout << "Enter the continent of this nation : ";
    string continent;
    cin >> continent;
    cout << "Enter the nation's staduim : ";
    string stadium;
    cin >> stadium;
    return {s, stadium, "", continent, ClubStats(), map<string, int>(), ""};
}

void cupOperations(Cup &cup) {
    if (cup.checkRunningCup()) {
        cout << "Do you wish to create new competition (y,n)\n";
        char c;
        cin >> c;
        c = tolower(c);
        if (c == 'y') {
            cup.resetCup();
            cout << "Enter number of teams (power of two): ";
            int nums;
            cin >> nums;
            while (log2(nums) != (int) log2(nums)) {
                cout << "Invalid number of teams, enter a power of 2 !\n";
                cin >> nums;
            }
            for (int i = 0; i < nums; i++) {
                cup.addClub(makeNation());
            }
            cup.setRounds();
            cup.generateMatches();
        }
    }
    int num = 1;
    while (true) {
        cout << "1. Show top scorers\n2. Show teams\n3. Proceed to next round\n"
                "4. Predict the competition\n5. Show fixtures\n6. Exit\n";
        cin >> num;
        switch (num) {
            case 1:
                cup.getTopScorers();
                break;
            case 2:
                cup.getTeams();
                break;
            case 3:
                cup.toNextRound();
                break;
            case 4:
                cup.predictCompetition();
                break;
            case 5:
                cup.getRounds();
                break;
            case 6:
                return;
            default:
                cout << "Enter a number between 1 - 5\n";
                break;
        }
    }
}

void nationalFootball() {
    cout << "Choose the tournament\n";
    cout << "1. World Cup\n2. Euros\n3. Copa America\n4. Exit\n";
    int cup;
    cin >> cup;
    switch (cup) {
        case 1:
            cupOperations(worldCup);
            break;
        case 2:
            cupOperations(euros);
            break;
        case 3:
            cupOperations(copaAmerica);
            break;
        case 4:
            return;
        default:
            cout << "Enter a number between 1 - 4\n";
            break;
    }
}

int main() {
    laliga = League("La liga", "Spain", map<string, int>());
    bundesliga = League("Bundesliga", "Germany", map<string, int>());
    seriea = League("Serie A", "Italy", map<string, int>());
    premiereleague = League("Premier League", "England", map<string, int>());
    ligue1 = League("Ligue 1", "France", map<string, int>());

    worldCup = Cup("World Cup", "International", map<string, int>());
    euros = Cup("Euros", "Europe", map<string, int>());
    copaAmerica = Cup("Copa America", "South America", map<string, int>());

    char num = '0';
    while (num != '3') {
        cout << "1. Club Football\n2. National Football \n3. Exit\n";
        cin >> num;
        switch (num) {
            case '1' :
                clubFootball();
                break;
            case '2':
                nationalFootball();
                break;
            case '3' :
                return 0;
            default:
                cout << "Enter a number between 1 - 3\n";
                break;
        }
    }
}
