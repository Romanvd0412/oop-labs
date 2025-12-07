#include "OpticalFiber.h"

OpticalFiber::OpticalFiber() : SignalConductor(), fibersCount(0), modeType("Unknown") {}

OpticalFiber::OpticalFiber(string n, double l, double p, int count, string mode) 
    : SignalConductor(n, l, p) {
    if (count <= 0) throw ConductorException("Fibers count must be at least 1!");
    fibersCount = count;
    modeType = mode;
}

void OpticalFiber::displayInfo() const {
    cout << "[Optical Fiber] Name: " << name 
         << ", Length: " << length << "m"
         << ", Price: " << getPrice() << "$"
         << ", Fibers: " << fibersCount 
         << ", Mode: " << modeType << endl;
}

void OpticalFiber::saveToFile(ofstream& out) const {
    int type = 2; // Ідентифікатор типу 2
    out.write((char*)&type, sizeof(type));

    SignalConductor::saveToFile(out);
    
    out.write((char*)&fibersCount, sizeof(fibersCount));
    
    size_t modeLen = modeType.size();
    out.write((char*)&modeLen, sizeof(modeLen));
    out.write(modeType.c_str(), modeLen);
}

void OpticalFiber::loadFromFile(ifstream& in) {
    SignalConductor::loadFromFile(in);
    
    in.read((char*)&fibersCount, sizeof(fibersCount));
    
    size_t modeLen;
    in.read((char*)&modeLen, sizeof(modeLen));
    char* tempMode = new char[modeLen + 1];
    in.read(tempMode, modeLen);
    tempMode[modeLen] = '\0';
    modeType = tempMode;
    delete[] tempMode;
}