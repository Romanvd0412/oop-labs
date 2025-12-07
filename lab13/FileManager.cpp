#include "FileManager.h"

void FileManager::saveList(const vector<SignalConductor*>& list, const string& filename) {
    ofstream outFile(filename, ios::binary);
    
    if (!outFile.is_open()) {
        throw ConductorException("Cannot open file for writing: " + filename);
    }

    size_t size = list.size();
    outFile.write((char*)&size, sizeof(size));

    for (const auto* item : list) {
        item->saveToFile(outFile);
    }

    outFile.close();
    cout << "Data saved to " << filename << " successfully." << endl;
}

void FileManager::loadList(vector<SignalConductor*>& list, const string& filename) {
    ifstream inFile(filename, ios::binary);
    
    if (!inFile.is_open()) {
        throw ConductorException("Cannot open file for reading: " + filename);
    }

    for (auto* item : list) delete item;
    list.clear();

    size_t size;
    inFile.read((char*)&size, sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        int type;
        inFile.read((char*)&type, sizeof(type));

        SignalConductor* newItem = nullptr;
        if (type == 1) {
            newItem = new CoaxialCable();
        } else if (type == 2) {
            newItem = new OpticalFiber();
        }

        if (newItem) {
            newItem->loadFromFile(inFile);
            list.push_back(newItem);
        }
    }

    inFile.close();
    cout << "Data loaded from " << filename << " successfully." << endl;
}