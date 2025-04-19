#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Logger {
private:
    vector<string> logs;
    const size_t maxLogs = 1000;
    const string authKey = "audit";

    void store(string level, string source, string message) {
        string entry = "[" + level + "] [" + source + "]: " + message;
        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin());
        }
        logs.push_back(entry);
    }

public:
    void info(string source, string message) {
        store("INFO", source, message);
    }

    void warn(string source, string message) {
        store("WARN", source, message);
    }

    void error(string source, string message) {
        store("ERROR", source, message);
    }

    vector<string> getLogs(string key) {
        if (key == authKey) {
            return logs;
        } else {
            cout << "Access denied." << endl;
            return {};
        }
    }
};

int main() {
    Logger log;

    log.info("network", "Connection successful");
    log.warn("network", "Packet delay detected");
    log.error("db", "Failed to connect to database");
    log.info("ui", "User clicked button");

    for (int i = 1; i <= 5; ++i) {
        log.info("task", "Task " + to_string(i) + " done");
    }

    vector<string> fakeTry = log.getLogs("wrong");
    cout << "\nFake audit: " << fakeTry.size() << " entries\n";

    vector<string> realTry = log.getLogs("audit");
    cout << "\nReal audit logs:\n";
    for (string s : realTry) {
        cout << s << endl;
    }

    return 0;

}