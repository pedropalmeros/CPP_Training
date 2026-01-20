#include <functional>
 
template<typename A, typename B, typename C = std::less<>>
constexpr bool fun(A a, B b, C cmp = C{})
{
    return cmp(a, b);
}
 
static_assert(fun(1, 2) == true);
static_assert(fun(1.0, 1) == false);
static_assert(fun(1, 2.0) == true);
static_assert(std::less<int>{}(5, 5.6) == false);   // 5 < 5 (warn: implicit conversion)
static_assert(std::less<double>{}(5, 5.6) == true); // 5.0 < 5.6
static_assert(std::less<int>{}(5.6, 5.7) == false); // 5 < 5 (warn: implicit conversion)
static_assert(std::less{}(5, 5.6) == true);         // less<void>: 5.0 < 5.6
 
int main() {}