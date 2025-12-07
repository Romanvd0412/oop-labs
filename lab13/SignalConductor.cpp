#include "SignalConductor.h"

SignalConductor::SignalConductor() : name("Unknown"), length(0), pricePerMeter(0) {}

SignalConductor::SignalConductor(string n, double l, double p) {
    if (l < 0 || p < 0) {
        throw ConductorException("Error: Length and Price must be positive!");
    }
    name = n;
    length = l;
    pricePerMeter = p;
}

void SignalConductor::saveToFile(ofstream& out) const {
    size_t nameLen = name.size();
    out.write((char*)&nameLen, sizeof(nameLen));
    out.write(name.c_str(), nameLen);
    out.write((char*)&length, sizeof(length));
    out.write((char*)&pricePerMeter, sizeof(pricePerMeter));
}

void SignalConductor::loadFromFile(ifstream& in) {
    size_t nameLen;
    in.read((char*)&nameLen, sizeof(nameLen));
    
    char* tempName = new char[nameLen + 1];
    in.read(tempName, nameLen);
    tempName[nameLen] = '\0';
    name = tempName;
    delete[] tempName;

    in.read((char*)&length, sizeof(length));
    in.read((char*)&pricePerMeter, sizeof(pricePerMeter));
}

double SignalConductor::getPrice() const {
    return length * pricePerMeter;
}

bool SignalConductor::operator<(const SignalConductor& other) const {
    return this->getPrice() < other.getPrice();
}