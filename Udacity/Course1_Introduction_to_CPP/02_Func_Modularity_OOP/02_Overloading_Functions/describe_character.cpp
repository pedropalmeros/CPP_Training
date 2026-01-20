/*
You’re designing a game where different characters and items need to be described on screen. 
Create a set of overloaded describe() functions that handle the following cases:

    A character name – print "Character: [name]"

    A character’s level – print "Level: [level]"

    A pair of coordinates – print "Location: ([x], [y])"

    A boolean flag for whether the character is alive – print "Status: Alive" or "Status: Dead"

Write a main() function that calls each version of describe() with appropriate data.
*/

#include <iostream>
#include <string>

// TODO: Write a function named describe that takes a string and prints "Character: [name]"
void describe(std::string Name) {
    // TODO
    std::cout << "Character: " << Name << std::endl;
}

// TODO: Write a function named describe that takes an int and prints "Level: [level]"
void describe(int level) {
    // TODO
    std::cout << "Level: " << level << std::endl;
}

// TODO: Write a function named describe that takes two doubles and prints "Location: ([x], [y])"
void describe(float x, float y) {
    // TODO
    std::cout << "Location: " << x << ", " << y << std::endl;
}

// TODO: Write a function named describe that takes a bool and prints "Status: Alive" or "Status: Dead"
void describe(bool isAlive) {
    // TODO
    if (isAlive){
        std::cout << "Status: Alive" << std::endl;
    }else{
        std::cout << "Status: Dead" << std::endl; 
    }

    //std::cout << "Status" << (isAlive ? "Alive" : "Dead") << std::endl;
}

int main() {
    std::string name = "Asha";
    int level = 7;
    double x = 13.2, y = 42.9;
    bool alive = true;

    // TODO: Call each overloaded version of describe()
    
    describe(name); 
    describe(level);
    describe(x,y);
    describe(alive);

    return 0;
}