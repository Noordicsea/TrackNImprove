/*#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

class DailyInformation {
public:
    std::string category;
    std::string subCategory;
    std::string value;
};

std::string toJSON(const DailyInformation& info) {
    std::stringstream ss;
    ss << "{";
    ss << "\"category\": \"" << info.category << "\", ";
    ss << "\"subCategory\": \"" << info.subCategory << "\", ";
    ss << "\"value\": \"" << info.value << "\"";
    ss << "}";
    return ss.str();
}

class PersonalTrackerApp {
private:
    std::map<std::string, std::string> users;
    std::string currentUsername;
    std::vector<DailyInformation> dailyData;
    void displayMainMenu() {
        std::cout << "Welcome back, " << currentUsername << ". Let's have a great day!" << std::endl;
        std::cout << "1. Input daily information" << std::endl;
        std::cout << "2. Track new dataset" << std::endl;
        std::cout << "3. See past data" << std::endl;
        std::cout << "4. Ask about my data" << std::endl;
        std::cout << "5. Logout" << std::endl;
        // Add more options as needed
    }
    void inputDailyInformation() {
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
        }
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

    void trackNewDataset() {
        std::cout << "Choose the new data points you want to track:" << std::endl;
        // Implementation here
    }

    void seePastData() {
        std::cout << "Displaying past data:" << std::endl;
        // Implementation here
    }

    void askAboutData() {
        std::cout << "Ask about your data:" << std::endl;
        // Implementation here
    }

public:
    PersonalTrackerApp() {
        users["gertin"] = "password"; // Default credentials
    }

    void login() {
        std::string username, password;
        while (true) {
            std::cout << "Login to Track Progress" << std::endl;
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            if (users.find(username) != users.end() && users[username] == password) {
                currentUsername = username;
                break;
            }
            else {
                std::cout << "Invalid credentials. Try again." << std::endl;
            }
        }
    }

    void runApp() {
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
                return;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
            }
        }
    }
};

int main() {
    PersonalTrackerApp app;
    app.login();
    app.runApp();
    return 0;
}
*/