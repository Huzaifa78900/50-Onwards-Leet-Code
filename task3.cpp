#include <iostream>
#include <string>
using namespace std;

struct Task {
    int id;
    string description, status;
    Task *prev, *next;
    Task(int i, string d) : id(i), description(d), status("Pending"),
                            prev(nullptr), next(nullptr) {}
};

class TaskTracker {
    Task *head = nullptr, *tail = nullptr;
public:
    void add(int id, string desc) {
        Task* t = new Task(id, desc);
        if (!tail) head = tail = t;
        else { tail->next = t; t->prev = tail; tail = t; }
    }
    void show() const {
        cout << "Project task board:\n";
        for (Task* p = head; p; p = p->next)
            cout << "#" << p->id << " [" << p->status << "] " << p->description << "\n";
    }
    void complete(int id) {
        for (Task* p = head; p; p = p->next)
            if (p->id == id) { p->status = "Completed"; return; }
        cout << "Task ID not found.\n";
    }
    ~TaskTracker() {
        while (head) { Task* t = head; head = head->next; delete t; }
    }
};

int main() {
    TaskTracker board;
    board.add(1, "Design database");
    board.add(2, "Create login page");
    board.add(3, "Test user registration");
    board.complete(1);
    board.show();
    return 0;
}
