#ifndef CONDUCTOR_EXCEPTION_H
#define CONDUCTOR_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ConductorException : public exception {
private:
    string message;
public:
    ConductorException(const string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif