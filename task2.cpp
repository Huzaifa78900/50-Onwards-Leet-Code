#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    string name;
    int remaining;
    Task* next;
    Task(string n, int d) : name(n), remaining(d), next(nullptr) {}
};

int main() {
    Task *tail = nullptr;
    int quantum = 2;
    auto addTask = [&](string name, int duration) {
        Task* n = new Task(name, duration);
        if (!tail) { tail = n; n->next = n; }
        else { n->next = tail->next; tail->next = n; tail = n; }
    };

    addTask("Compile", 5);
    addTask("Backup", 3);
    addTask("Download", 2);
    cout << "Round-robin scheduling (time quantum = " << quantum << ")\n";
    int elapsed = 0;
    Task* prev = tail;
    Task* cur = tail->next;

    while (tail) {
        int slice = min(quantum, cur->remaining);
        cur->remaining -= slice;
        elapsed += slice;
        cout << "t=" << elapsed << ": " << cur->name
             << " ran for " << slice << " unit(s)";
        if (cur->remaining == 0) {
            cout << " -> completed";
            if (cur == cur->next) { delete cur; tail = nullptr; cur = nullptr; }
            else {
                prev->next = cur->next;
                if (cur == tail) tail = prev;
                Task* done = cur; cur = cur->next; delete done;
            }
        } else {
            cout << " -> " << cur->remaining << " remaining";
            prev = cur; cur = cur->next;
        }
        cout << "\n";
        if (cur && !tail) break;
    }
    cout << "All tasks completed.\n";
    return 0;
}
