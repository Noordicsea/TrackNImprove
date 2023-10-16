//PersonalTrackerApp.h
#ifndef PERSONAL_TRACKER_APP_H
#define PERSONAL_TRACKER_APP_H
#include "UserAuth.h"
#include "DataManager.h"
class PersonalTrackerApp {
private:
    UserAuth userAuth;
    DataManager dataManager;
    std::string currentUsername;
    std::vector<DailyInformation> dailyData;
    void inputDailyInformation();
public:
    PersonalTrackerApp();
    void trackNewDataset();
    void seePastData();
    void askAboutData();
    void displayMainMenu();
    void login();
    void runApp();
};
#endif //PERSONAL_TRACKER_APP_H
