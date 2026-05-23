#include <algorithm>
#include <vector>
#include <iostream>

int main() {
std::vector<int> v = {1, 2, 3};

int count = 0; 

std::for_each(v.begin(), v.end(),
    [&count](int x){
        if(x > 100) count++;
    });

std::cout << "value of count: " << count << std::endl; 
}