#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = filesystem;

class Logger {
private:
    int logCount = 1;
    string baseName = "log";
    string extension = ".txt";
    ofstream outFile;
    const size_t MAX_FILE_SIZE = 1024 * 1024; // 1MB
    string currentFileName;

    void openNewLogFile() {
        currentFileName = baseName + to_string(logCount) + extension;
        outFile.open(currentFileName, ios::app);
    }

    void rotateLog() {
        outFile.close();
        logCount++;
        openNewLogFile();
    }

    size_t getFileSize(const string& filename) {
        if (fs::exists(filename)) {
            return fs::file_size(filename);
        }
        return 0;
    }

public:
    Logger() {
        openNewLogFile();
    }

    ~Logger() {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    void log(const string& message) {
        if (getFileSize(currentFileName) >= MAX_FILE_SIZE) {
            rotateLog();
        }

        outFile << message << endl;
    }
};

int main() {
    Logger logger;

    for (int i = 1; i <= 100000; ++i) {
        logger.log("Log entry number: " + to_string(i));
    }

    cout << "Logging done. Check log files.\n";
    return 0;
}
