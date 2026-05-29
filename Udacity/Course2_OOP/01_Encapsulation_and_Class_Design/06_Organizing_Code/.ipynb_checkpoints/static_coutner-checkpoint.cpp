/************************************************
 * Task: 
 * Create a class Connection that tracks how many instances are active at any time.
 * REQUIREMENTS:
 * - static constexpr int MAX_ACTIVE = 2; 
 * - static inline activeCount = 0; 
 * - CONSTRUCTOR: if creating another instance would exceed MAX_ACTIVE,
 *                  throw std::runtime_error("Too many connections (MAX=2)"). Otherwise
 *                  increment the counter and print. Connection opened. Active:
 * - DESTRUCTOR: Decrement the counter and print: Connection closed. Active:
 * 
 * In main() (no input), demonstrate:
 * - Opening two connections successfully,
 * - Falling to open a third(catch and print the exception message),
 * - Then opening another after one goes out of scope.
 * EXPECTED OUTPUT:
 * Start
 * Connection opened. Active: 1
 * Connection opened. Active: 2
 * Exception: Too many connections (MAX=2)
 * Connection closed. Active 1
 * Connection opened. Active 2
 * Connection closed. Active 1
 * Connection closed. Active 0
 * Done
 */

 #include <iostream>
 #include <stdexcept>