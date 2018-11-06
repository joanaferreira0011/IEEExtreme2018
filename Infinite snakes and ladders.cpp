#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Pos {
    int x;
    int y;
};

struct Snake {
    Pos head;
    Pos tail;
};

struct Ladder {
    Pos start;
    Pos end;
};

struct Player {
    Pos pos = {0,1};
    bool won = false;
};

void checkForTransitions(Player * pl, vector<Snake> * sn, vector<Ladder> * ld) {
    Pos position = (*pl).pos;
    bool changed = false;
    for (unsigned i = 0; i < (*sn).size(); i++) {
        if (position.x == (*sn).at(i).head.x && position.y == (*sn).at(i).head.y) {
            (*pl).pos.x = (*sn).at(i).tail.x;
            (*pl).pos.y = (*sn).at(i).tail.y;
            changed = true;
            break;
        }
    }
    if (!changed) {
        for (unsigned i = 0; i < (*ld).size(); i++) {
            if (position.x == (*ld).at(i).start.x && position.y == (*ld).at(i).start.y) {
                (*pl).pos.x = (*ld).at(i).end.x;
                (*pl).pos.y = (*ld).at(i).end.y;
                changed = true;
                break;
            }
        }
    }
    if (changed) checkForTransitions(pl, sn, ld);
}

int main() {
    int n;
    cin >> n;
    
    int horiSize = n+1;
    int vertSize = n;
    
    cin >> n; // number of players
    vector<Player> players(n);
    
    n = 0;
    cin >> n; // number of snakes
    vector<Snake> snakes;
    for (int i = 0; i < n; i++) {
        Snake s;
        cin >> s.head.x >> s.head.y >> s.tail.x >> s.tail.y;
        snakes.push_back(s);
    }
    
    n = 0;
    cin >> n; // number of ladders
    vector<Ladder> ladders;
    for (int i = 0; i < n; i++) {
        Ladder l;
        cin >> l.start.x >> l.start.y >> l.end.x >> l.end.y;
        ladders.push_back(l);
    }
    
    n=0;
    cin >> n;
    int userIndex = 0;
    for (int i = 0; i < n; i++) { //Number of rolls
        int roll1, roll2;
        cin >> roll1 >> roll2;
        int total = roll1 + roll2;
        
        Player * pl = NULL;
        for (unsigned z = 0; z < players.size(); z++) {
            if (!players.at(z).won) {
                pl = &players.at(userIndex);
                break;
            } else {
                userIndex = (userIndex+1)%players.size();
            }
        }
        if (pl == NULL) break; // if all players finished the game
        
        userIndex = (userIndex+1) % players.size();
        
        for (int step = 0; step < total; step++) {
            int x = (*pl).pos.x;
            int y = (*pl).pos.y;
            if (y % 2 != 0) { // If odd line -> left to right movement
                if (x == 0 && y == 1)
                    (*pl).pos.x++;
                else if (x == horiSize-1) {
                    (*pl).pos.y++;
                } else {
                    (*pl).pos.x++;
                }
            } else { // If even line -> right to left
                if (x == 1 && y == vertSize) {
                    (*pl).pos.x--;
                    (*pl).won = true; // HANDLE PLAYER WON
                    break;
                }
                else if (x == 1) {
                    (*pl).pos.y++;
                } else {
                    (*pl).pos.x--;
                }
            }            
        }

        if ((*pl).won) continue;

        checkForTransitions(pl, &snakes, &ladders);
        if ((*pl).pos.x == 0 && (*pl).pos.y == vertSize) {
            (*pl).won = true;
        }
    }
    
    for (unsigned i = 0; i < players.size(); i++) {
        cout << (i+1) << " ";
        if (players.at(i).won) cout << "winner" << endl;
        else {
            cout << players.at(i).pos.x << " " << players.at(i).pos.y << endl;
        }
    }
}