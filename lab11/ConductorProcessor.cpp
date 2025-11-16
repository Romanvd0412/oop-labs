#include "ConductorProcessor.h"
#include "CoaxialCable.h"
#include "OpticalFiber.h"
#include <numeric>
#include <iomanip>

ConductorProcessor::ConductorProcessor() {
    cout << "ConductorProcessor (Friend Class) created." << endl;
}

ConductorProcessor::~ConductorProcessor() {
    cout << "ConductorProcessor (Friend Class) destroyed." << endl;
}

void ConductorProcessor::calculateAndDisplayStats(const vector<SignalConductor*>& conductors) const {
    if (conductors.empty()) {
        cout << "\nNo conductors to process." << endl;
        return;
    }

    double totalLength = 0.0;
    double totalMaxFrequency = 0.0;
    int opticalCount = 0;

    cout << "\n--- Processing Conductor Stats (via Friend Class) ---" << endl;

    for (const auto* conductor : conductors) {
        totalLength += conductor->length;
        totalMaxFrequency += conductor->maxFrequency;

        if (const OpticalFiber* fiber = dynamic_cast<const OpticalFiber*>(conductor)) {
            opticalCount++;
            cout << "Found Optical Fiber (" << fiber->manufacturer 
                 << ") with core diameter: " << fiber->coreDiameter << " um" << endl;
        }
    }

    double averageMaxFrequency = totalMaxFrequency / conductors.size();

    cout << "\nCalculation Results:" << endl;
    cout << fixed << setprecision(2);
    cout << "Total Length of all conductors: " << totalLength << " m" << endl;
    cout << "Average Max Frequency: " << (averageMaxFrequency / 1e9) << " GHz" << endl;
    cout << "Total Optical Fibers processed: " << opticalCount << endl;
    cout << "----------------------------------------------------" << endl;
}