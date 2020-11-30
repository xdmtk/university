#include <dvr/defs.h>
#include <algorithm>
#include <cctype>
#include <cstring>

std::vector<std::string> splitString(std::string s, const std::string& delimiter) {

    size_t pos = 0;
    std::string token;
    std::vector<std::string> out;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        trim(token = s.substr(0, pos));
        out.emplace_back(token);
        s.erase(0, pos + delimiter.length());
    }
    trim(s);
    if (s.size()) {
        out.emplace_back(s);
    }
    return out;
}

inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

bool is_num(std::string str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

