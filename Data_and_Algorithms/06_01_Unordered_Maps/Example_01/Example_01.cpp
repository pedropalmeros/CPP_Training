#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an empty unordered_map
    std::unordered_map<int, std::string> colors;

    // Initialize using an initializer list
    std::unordered_map<int, std::string> fruits = {
        {1, "Apple"},
        {2, "Banana"},
        {3, "Orange"}
    };

    // Display the initialized map
    std::cout << "Fruits map contains:" << std::endl;
    for (const auto& pair : fruits) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

}