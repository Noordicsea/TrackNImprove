//DataManager.cpp
#include "DataManager.h"
#include <fstream>
#include <sstream>
DataManager::DataManager() {
}
void DataManager::addDailyInformation(const DailyInformation& info) {
    dailyData.push_back(info);
}
std::string DataManager::exportDataAsJSON() const {
    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < dailyData.size(); ++i) {
        ss << dailyData[i].toJSON(); 
        if (i != dailyData.size() - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}
bool DataManager::saveDataToFile(const std::string& filename) const { 
    std::ofstream file(filename);
    if (file.is_open()) {
        file << exportDataAsJSON();
        file.close();
        return true;
    }
    return false;
}