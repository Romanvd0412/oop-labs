#ifndef CONDUCTOR_PROCESSOR_H
#define CONDUCTOR_PROCESSOR_H

#include "SignalConductor.h"
#include <vector>
#include <iostream>

using namespace std;

class ConductorProcessor {
public:
    ConductorProcessor();
    ~ConductorProcessor();

    void calculateAndDisplayStats(const vector<SignalConductor*>& conductors) const;
};

#endif