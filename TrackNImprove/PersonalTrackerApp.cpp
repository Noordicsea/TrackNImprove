#include "PersonalTrackerApp.h"
#include "UserAuth.h"
#include <iostream>
#include <fstream>
#include <sstream>

PersonalTrackerApp::PersonalTrackerApp() {}

void PersonalTrackerApp::displayMainMenu() {
    std::cout << "Welcome back, " << currentUsername << ". Let's have a great day!" << std::endl;
    std::cout << "1. Input daily information" << std::endl;
    std::cout << "2. Track new dataset" << std::endl;
    std::cout << "3. See past data" << std::endl;
    std::cout << "4. Ask about my data" << std::endl;
    std::cout << "5. Logout" << std::endl;
}

std::string toJSON(const DailyInformation& info) {
    std::stringstream ss;
    ss << "{";
    ss << "\"category\": \"" << info.category << "\", ";
    ss << "\"subCategory\": \"" << info.subCategory << "\", ";
    ss << "\"value\": \"" << info.value << "\"";
    ss << "}";
    return ss.str();
}

void PersonalTrackerApp::inputDailyInformation() {
    char cont;
    do {
        DailyInformation info;
        std::cout << "Enter category: ";
        std::cin.ignore();
        std::getline(std::cin, info.category);
        std::cout << "Enter sub-category (leave blank if none): ";
        std::getline(std::cin, info.subCategory);
        std::cout << "Enter value (1-10 or true/false): ";
        std::getline(std::cin, info.value);
        dailyData.push_back(info);
        std::cout << "Continue adding data? (y/n): ";
        std::cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    // Save to JSON file
    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < dailyData.size(); ++i) {
        ss << toJSON(dailyData[i]);
        if (i != dailyData.size() - 1) {
            ss << ", ";
        }
    }.. ..
    ss << "]";

    std::string filename = currentUsername + "_daily_data.json";
    std::ofstream file(filename);
    if (file.is_open()) {
        file << ss.str();
        file.close();
        std::cout << "Data saved successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to save the data!" << std::endl;
    }
}

// Other private methods for additional functionalities (stub implementations)
void PersonalTrackerApp::trackNewDataset() {
    // Implementation here (currently just a placeholder)
}

void PersonalTrackerApp::seePastData() {
    // Implementation here (currently just a placeholder)
}

void PersonalTrackerApp::askAboutData() {
    // Implementation here (currently just a placeholder)
}


void PersonalTrackerApp::login() {
    std::string username, password;
    UserAuth userAuth; // Assuming you have an instance of UserAuth
    while (true) {
        std::cout << "Login to Track Progress" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (userAuth.checkCredentials(username, password)) {
            currentUsername = username;
            break;
        }
        else {
            std::cout << "Invalid credentials. Try again." << std::endl;
        }
    }
}

// Public method to run the application after user logs in
void PersonalTrackerApp::runApp() {
    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            inputDailyInformation();
            break;
        case 2:
            trackNewDataset();
            break;
        case 3:
            seePastData();
            break;
        case 4:
            askAboutData();
            break;
        case 5:
            std::cout << "Logging out..." << std::endl;
            return; // Exits the function, thereby ending the application
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    }
}
