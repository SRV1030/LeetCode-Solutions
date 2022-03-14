// https://leetcode.com/problems/simple-bank-system

class Bank {
public:
    vector<long long> bal;
    Bank(vector<long long>& balance) {
        bal=balance;
    }
    
    bool transfer(int a1, int a2, long long money) {
        if(a1>bal.size() || a2>bal.size() || money>bal[a1-1]) return false;
        bal[a1-1]-=money;
        bal[a2-1]+=money;
        return true;
    }
    
    bool deposit(int a1, long long money) {
        if(a1>bal.size()) return false;
        bal[a1-1]+=money;
        return true;
    }
    
    bool withdraw(int a1, long long money) {
        if(a1>bal.size() || money>bal[a1-1]) return false;
        bal[a1-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */