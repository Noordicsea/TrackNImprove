// DailyInformation.h
#pragma once
#include <string>
#include <sstream>
class DailyInformation {
public:
    std::string category;
    std::string subCategory;
    std::string value;
    DailyInformation() : category(""), subCategory(""), value("") {
    }
    DailyInformation(const std::string& category, const std::string& subCategory, const std::string& value)
        : category(category), subCategory(subCategory), value(value) {
    }
    std::string toJSON() const {
        std::stringstream ss;
        ss << "{";
        ss << "\"category\": \"" << category << "\", ";
        ss << "\"subCategory\": \"" << subCategory << "\", ";
        ss << "\"value\": \"" << value << "\"";
        ss << "}";
        return ss.str();
    }
};
