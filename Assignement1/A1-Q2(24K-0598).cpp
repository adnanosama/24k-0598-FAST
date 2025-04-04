#include <iostream>
#include <string>

using namespace std;

class Ball {
private:
    int x, y;
public:
    Ball() : x(0), y(0) {}
    Ball(int x, int y) : x(x), y(y) {}

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    pair<int, int> getPosition() const {
        return {x, y};
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class Goal {
private:
    int goalX, goalY;
public:
    Goal(int x, int y) : goalX(x), goalY(y) {}

    bool isGoalReached(const Ball &ball) {
        return ball.getX() == goalX && ball.getY() == goalY;
    }
};

class Robot {
private:
    string name;
    int hits;
public:
    Robot(string n) : name(n), hits(0) {}

    void hitBall(Ball &ball, const string &direction) {
        hits++;

        if (direction == "up") {
            ball.move(0, 1);
        } else if (direction == "down") {
            ball.move(0, -1);
        } else if (direction == "left") {
            ball.move(-1, 0);
        } else if (direction == "right") {
            ball.move(1, 0);
        }
    }

    int getHits() const { return hits; }
    string getName() const { return name; }
};

class Team {
public:
    string teamName;
    Robot *player;

    Team(string name, Robot *p) : teamName(name), player(p) {}
};

class Game {
private:
    Team *teamOne;
    Team *teamTwo;
    Ball ball;
    Goal goal;

public:
    Game(Team *t1, Team *t2) : teamOne(t1), teamTwo(t2), goal(3, 3) {}

    void startGame() {
        cout << "Game Started!" << endl;
        play(teamOne);
        play(teamTwo);
        declareWinner();
    }

    void play(Team *team) {
        ball = Ball(0, 0);        
        string direction;
        while (!goal.isGoalReached(ball)) {
            cout << team->teamName << "'s turn. Enter direction (up/down/left/right): ";
            cin >> direction;
            team->player->hitBall(ball, direction);
            cout << "Ball position: (" << ball.getX() << ", " << ball.getY() << ")\n";
            
            if (goal.isGoalReached(ball)) {
                cout << "Goal reached!\n";
                break;
            }
        }
    }

    void declareWinner() {
        int hitsOne = teamOne->player->getHits();
        int hitsTwo = teamTwo->player->getHits();

        cout << "Results:\n";
        cout << teamOne->teamName << " Hits: " << hitsOne << endl;
        cout << teamTwo->teamName << " Hits: " << hitsTwo << endl;

        if (hitsOne < hitsTwo) {
            cout << teamOne->teamName << " Wins!" << endl;
        } else if (hitsOne > hitsTwo) {
            cout << teamTwo->teamName << " Wins!" << endl;
        } else {
            cout << "It's a Draw!" << endl;
        }
    }
};

int main() {
    Robot r1("Robot1"), r2("Robot2");
    Team t1("Team1", &r1), t2("Team2", &r2);
    Game g(&t1, &t2);

    g.startGame();

    return 0;
}
