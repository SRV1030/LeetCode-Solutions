// https://leetcode.com/problems/the-number-of-full-rounds-you-have-played

class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int login=stoi(loginTime.substr(0,2))*60+stoi(loginTime.substr(3)),logout=stoi(logoutTime.substr(0,2))*60+stoi(logoutTime.substr(3));
        if(login>logout)logout+=(24*60);
        if(login%15)login+=15-(login%15);
        return (logout-login)/15;
    }
};