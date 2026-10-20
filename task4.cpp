#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    int seconds;
    Song *prev, *next;
    Song(string n, int s) : name(n), seconds(s), prev(nullptr), next(nullptr) {}
};

int main() {
    Song *first = nullptr, *last = nullptr;
    auto addSong = [&](string name, int duration) {
        Song* s = new Song(name, duration);
        if (!first) first = last = s;
        else { last->next = s; s->prev = last; last = s; }
    };
    addSong("Morning Light", 210);
    addSong("City Drive", 185);
    addSong("Blue Skies", 240);
    last->next = first;
    first->prev = last;

    Song* current = first;
    cout << "Now playing: " << current->name << "\n";
    current = current->next;
    cout << "Next: " << current->name << "\n";
    current = current->next;
    cout << "Next: " << current->name << "\n";
    current = current->prev;
    cout << "Previous: " << current->name << "\n";
    current = last->next;
    cout << "Loop to first: " << current->name << "\n";
    cout << "Playlist (seconds):\n";
    Song* p = first;
    do {
        cout << "- " << p->name << " (" << p->seconds << " sec)\n";
        p = p->next;
    } while (p != first);
    // Break the circular links before freeing the nodes.
    last->next = nullptr; first->prev = nullptr;
    while (first) { Song* t = first; first = first->next; delete t; }
    return 0;
}
