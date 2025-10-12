#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {10, 20, 30, 40, 50};

    // Iterate and print each element
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    mySet.insert(30);

    return 0;
}