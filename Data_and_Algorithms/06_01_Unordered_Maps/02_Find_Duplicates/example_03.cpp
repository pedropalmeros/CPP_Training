#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    std::unordered_map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 35;

    // Find an existing element
    std::string key_to_find = "Bob";
    auto it = ages.find(key_to_find);

    if (it != ages.end()) {
        std::cout << "Found " << key_to_find << ": " << it->second << std::endl;
    } else {
        std::cout << key_to_find << " not found." << std::endl;
    }

    // Attempt to find a non-existent element
    std::string non_existent_key = "David";
    it = ages.find(non_existent_key);

    if (it != ages.end()) {
        std::cout << "Found " << non_existent_key << ": " << it->second << std::endl;
    } else {
        std::cout << non_existent_key << " not found." << std::endl;
    }

    return 0;
}