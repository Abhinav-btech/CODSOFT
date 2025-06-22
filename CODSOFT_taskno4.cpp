#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display.\n";
            return;
        }

        cout << "\nTo-Do List:\n";
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].isCompleted = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            cout << "Task removed successfully.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;
    int taskNumber;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter the task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                todoList.viewTasks();
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                todoList.viewTasks();
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
