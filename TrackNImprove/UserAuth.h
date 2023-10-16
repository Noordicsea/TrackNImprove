//UserAuth.h
#ifndef USER_AUTH_H
#define USER_AUTH_H
#include <string>
#include <map>
class UserAuth {
private:
    std::map<std::string, std::string> users;
public:
    UserAuth();
    bool checkCredentials(const std::string& username, const std::string& password);
};
#endif //USER_AUTH_H
