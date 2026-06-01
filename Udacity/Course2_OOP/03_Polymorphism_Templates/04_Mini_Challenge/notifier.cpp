#include <iostream>
#include <string> 

class Notifier{
    public:
        // pure virtual
        virtual void send(const std::string& msg) const = 0; // making it pure virtual
        virtual ~Notifier() = default; 
};

class EmailNotifier : public Notifier{
    // TODO: implement to print: Email: <msg>
    void send(const std::string& msg)const override{ 
        std::cout << "Email: " << msg << std::endl;}
};

class SmsNotifier : public Notifier{
    // TODO: implement to print: SMS: <msg> 
    void send(const std::string& msg)const override { 
        std::cout << "SMS: " << msg << std::endl; }
};


// TODO: implement using BASE-CLASS REFERENCE (runtime dispatch, no pointers)
void broadcast(const Notifier& n, const std::string& msg){
    n.send(msg);
}

int main(){
    EmailNotifier email; 
    SmsNotifier sms; 

    // Scenario events:
    // 1) Onboarding email
    // 2) 2FA confirmation via SMS
    broadcast(email,"Welcome aboard!"); 
    broadcast(sms,  "Code123 confirmed.");

    return 0; 
}