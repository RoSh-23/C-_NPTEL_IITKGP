#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Playable {
public:
   virtual void play() = 0;    // LINE-1
};

class Music : public Playable {
public:
     string getMusicType(int i) {      // LINE-2

        string MusicType[] = { "Rock", "Jazz", "Pop", "Folk", 
                               "Classical", "Blues", "Heavy Metal" };
        if (i >= 0 && i < 7)
            return MusicType[i];
        else
            return "unknown";
    }
    void play();
};

class Game : public Playable {
public:
    string  getGameType(int i) {      // LINE-3

        string GameType[] = { "Action", "Action-adventure", "Adventure", 
                              "Role-playing", "Simulation", "Strategy", 
                              "Sports", "Puzzle" };
        if (i >= 0 && i < 8)
            return GameType[i];
        else
            return "unknown";
    }
    void play();
};

class Player {
    Playable *_pt;
    string type;
public:
    Player(Playable *pt) : _pt(pt) { }
    void play(int i){
        _pt->play();
        if (typeid(*_pt) == typeid(Music))      // LINE-4 
   
            type = ((Music*)_pt)->getMusicType(i);

        if (typeid(*_pt) == typeid(Game))       // LINE-5

void square :: area() { cout << (s * s) << " "; }
void cube :: area() { cout << (6 * s * s) << " "; }
void cube :: volume() { cout << (s * s * s) << " "; }

int main() {
    int n;
    cin >> n;
    shape *s[2] = {new square(n), new cube(n)};
    caller(s[0]);
    caller(s[1]);
    return 0;
}