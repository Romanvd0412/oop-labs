#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "SignalConductor.h"
#include "CoaxialCable.h"
#include "OpticalFiber.h"
#include <vector>

class FileManager {
public:
    static void saveList(const vector<SignalConductor*>& list, const string& filename);
    
    static void loadList(vector<SignalConductor*>& list, const string& filename);
};

#endif