#include <iostream>
#include <string>
using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice, please wait" << endl;
        for (long i = 1; i <= 1000000000; ++i) {}
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice, please wait" << endl;
        for (long i = 1; i <= 1000000000; ++i) {}
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
    Blend blender;
    Grind grinder;
public:
    void makeJuice() {
        cout << "Starting juice making process..." << endl;
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready!" << endl;
    }
};

int main() {
    JuiceMaker juicer;
    juicer.makeJuice();
    return 0;
}