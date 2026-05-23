#include <algorithm>   // std::min_element
#include <iostream>
#include <vector>
#include <algorithm>

struct Ticket {
    int id;
    int wait_minutes;  // how long they’ve waited
    int severity;      // 1 = critical (most urgent), 5 = minor
};

static std::vector<Ticket*> open_list;

// Return the ticket with the smallest score = wait_minutes + severity * 10.
// Remove it from open_list and return it.
Ticket* NextTicket() {
    if (open_list.empty()) return nullptr;

    // TODO: use std::min_element with a lambda comparator comparing the score
    // auto best_it = std::min_element(open_list.begin(), open_list.end(), /* lambda here */);

    auto best_it = std::min_element(open_list.begin(), open_list.end(),[](const Ticket* a,const Ticket* b){
        int aScore = a->wait_minutes + a->severity * 10; 
        int bScore = b->wait_minutes + b->severity * 10;
        return aScore < bScore;
    });

    // TODO: store *best_it in a pointer, erase it from open_list, return it
    Ticket* best = *best_it;
    open_list.erase(best_it);
    return best; // replace
}

int main() {
    Ticket a{101,  5, 3}; // score = 5 + 30  = 35
    Ticket b{102, 12, 2}; // score = 12 + 20 = 32  (best first)
    Ticket c{103,  0, 4}; // score = 0 + 40  = 40

    open_list = { &a, &b, &c };

    while (!open_list.empty()) {
        Ticket* t = NextTicket();
        if (!t) break;
        int score = t->wait_minutes + t->severity * 10;
        std::cout << "Serving ticket id=" << t->id << " (score=" << score << ")\n";
        // (In a real system, you’d now process the ticket.)
    }
    return 0;
}
