#include <chat/defs.h>
#include <algorithm>
#include <cctype>
#include <cstring>

#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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

std::string collapseTokens(std::vector<std::string> tokens, int begin, int end) {

    std::string out;
    for (int i = begin; i < end; ++i) {
        out += tokens[i] + " ";
    }
    return out.substr(0, out.size()-1);
}

std::string getIpAddress() {
    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;
    std::string address;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4

            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

            if (std::string(addressBuffer) == "127.0.0.1") {
                continue;
            }

            if (strncmp(addressBuffer ,"192.x.x.xxx", 3) == 0) {
                address += std::string(addressBuffer);
                break;
            }
        }
            
    }
    
    return address;
}
