#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title, content;
    Node *prev, *next;
    Node(string t, string c) : title(t), content(c), prev(nullptr), next(nullptr) {}
};

class NotesList {
    Node *head = nullptr, *tail = nullptr;
public:
    void add(string title, string content) {
        Node* n = new Node(title, content);
        if (!tail) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
    }
    void remove(string title) {
        Node* cur = head;
        while (cur && cur->title != title) cur = cur->next;
        if (!cur) { cout << "Note not found.\n"; return; }
        if (cur->prev) cur->prev->next = cur->next; else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev; else tail = cur->prev;
        delete cur;
        cout << "Deleted note: " << title << "\n";
    }
    void forward() const {
        cout << "\nForward notes:\n";
        for (Node* p = head; p; p = p->next)
            cout << "- " << p->title << ": " << p->content << "\n";
    }
    void backward() const {
        cout << "\nReverse notes:\n";
        for (Node* p = tail; p; p = p->prev)
            cout << "- " << p->title << ": " << p->content << "\n";
    }
    ~NotesList() {
        while (head) { Node* t = head; head = head->next; delete t; }
    }
};

int main() {
    NotesList notes;
    notes.add("DSA Revision", "Review linked lists");
    notes.add("Project Idea", "Build a task tracker");
    notes.add("Meeting", "Friday at 10 AM");
    notes.forward();
    notes.backward();
    notes.remove("Project Idea");
    notes.forward();
    return 0;
}
