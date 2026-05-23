#include <algorithm>
#include <vector>
#include <iostream>

int main() {
std::vector<int> v = {1, 2, 3};

std::for_each(v.begin(), v.end(),
[](int x) { std::cout << x << " "; });
// 1 2 3
}