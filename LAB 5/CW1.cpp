#include <iostream>
#include <string>
using namespace std;

class Engine{
    int horsepower;
    float size;
    bool isrunning;
    public:
    Engine(){
        isrunning = false;
    }
    void start(){
        cout << "Engine started" << endl;
        isrunning = true;
    }
    void stop(){
        cout << "Engine stopped" << endl;
        isrunning = false;
    }

};

class car{
    Engine engine;
    int year;
    int name;
    public:
    car(){
        year = 0;
        name = 0;
    }
    car(Engine e, int y, int n){
        engine = e;
        year = y;
        name = n;
    }
    void startcar(){
        engine.start();
    }
    void stopcar(){
        engine.stop();
    }
};

int main(){
    Engine e1;
    car c1(e1, 2010, 1);
    c1.startcar();
    c1.stopcar();
    return 0;
}