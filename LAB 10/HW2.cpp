#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool done;
};

vector<Task> loadTasks(const string& filename) {
    vector<Task> tasks;
    ifstream inFile(filename);
    string line;
    while (getline(inFile, line)) {
        bool isDone = false;
        if (!line.empty() && line.substr(0, 6) == "[DONE]") {
            isDone = true;
            line = line.substr(7);
        }
        tasks.push_back({line, isDone});
    }
    return tasks;
}

void saveTasks(const vector<Task>& tasks, const string& filename) {
    ofstream outFile(filename);
    for (const auto& task : tasks) {
        if (task.done) {
            outFile << "[DONE] " << task.description << endl;
        } else {
            outFile << task.description << endl;
        }
    }
}

void addTask(const string& filename) {
    string task;
    cout << "Enter task description: ";
    getline(cin, task);
    ofstream outFile(filename, ios::app);
    outFile << task << endl;
}

void viewTasks(const vector<Task>& tasks) {
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].done) cout << "[DONE] ";
        cout << tasks[i].description << endl;
    }
}

void markTaskDone(vector<Task>& tasks, const string& filename) {
    int num;
    viewTasks(tasks);
    cout << "Enter task number to mark as done: ";
    cin >> num;
    cin.ignore();
    if (num >= 1 && num <= tasks.size()) {
        tasks[num - 1].done = true;
        saveTasks(tasks, filename);
    }
}

int main() {
    string filename = "tasks.txt";
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Exit\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            addTask(filename);
        } else if (choice == 2) {
            vector<Task> tasks = loadTasks(filename);
            viewTasks(tasks);
        } else if (choice == 3) {
            vector<Task> tasks = loadTasks(filename);
            markTaskDone(tasks, filename);
        } else {
            break;
        }
    }
    return 0;
}
