//UserAuth.cpp
#include "UserAuth.h"

UserAuth::UserAuth() {
    users["gertin"] = "password"; // Default credentials
}

bool UserAuth::checkCredentials(const std::string& username, const std::string& password) {
    return users.find(username) != users.end() && users[username] == password;
}
