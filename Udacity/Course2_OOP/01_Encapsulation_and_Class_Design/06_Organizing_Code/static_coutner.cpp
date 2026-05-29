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

 class Connection{
    public:
        // Limit and counter
        static constexpr int MAX_ACTIVE = 2; 
        static inline int activeCount = 0; 

        // TODO: in constructor, if activeCount >= MAX_ACTIVE -> throw runtime_error("Too many connections (MAX=2)")
        // Othersie ++activeCount and print "Connection opened. Active <count>"
        Connection(); 

        // TODO: In dtor, --activateCount and print "Connection closed. Active: <count>"
        ~Connection();
 };

 Connection::Connection(){
    if (activeCount >= MAX_ACTIVE){
        throw std::out_of_range("Too many connections (MAX=2)");
        return;
    }
    ++activeCount;
    std::cout << "Connection opened. Active: " << activeCount << "\n";
 }

 Connection::~Connection(){
    --activeCount;
    std::cout << "Connection closed. Active: "  << activeCount << "\n";
 }
 
 int main(){
    std::cout << "Start\n"; 
        // Open 1st and 2nd connections
        Connection c1;
        {
            Connection c2; 
            
            // Attempt 3rd -> should fail and be caught
            try{
                Connection c3; 
            }catch (const std::exception& e){
                std::cout << "Exception: " << e.what() << "\n";
            }
        }// c2 leaves scope here

        // Now it should be possbile to open again 
        Connection c3; 


        std::cout << "Done\n";
 }