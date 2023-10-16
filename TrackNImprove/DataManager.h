#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include <fstream>
#include <string>
#include <vector>
#include "DailyInformation.h"

class DataManager {
private:
    std::vector<DailyInformation> dailyData;

public:
    DataManager();  // Declare the default constructor
    void addDailyInformation(const DailyInformation& info);
    std::string exportDataAsJSON() const;
    bool saveDataToFile(const std::string& filename) const;
};

#endif
