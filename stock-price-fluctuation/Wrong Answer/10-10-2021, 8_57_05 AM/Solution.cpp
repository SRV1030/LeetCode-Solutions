// https://leetcode.com/problems/stock-price-fluctuation

class StockPrice {
public: int mn=INT_MAX,mx=INT_MIN,c,mxt=-1,mnt=-1;
    unordered_map<int,int>mp;
    StockPrice() {
        mp.clear();
    }
    
    void update(int timestamp, int price) {
        if(mp.empty()){
            mp[timestamp]=price;
            c=price;
            mn=mx=price;
            mxt=mnt=timestamp;
        }
        else{
            mp[timestamp]=price;
            c=price;  
            if(timestamp==mxt){
                if(price>mx){
                    mx=price;
                    return;
                }
                int mxc=INT_MIN;
                for(auto&i:mp)
                    if(i.second>mxc){
                        mxc=i.second;
                        mxt=i.first;
                    }
                mx=mxc;
            }
            else if(timestamp==mnt){
                if(price<mn){
                    mn=price;
                    return;
                }
                int mnc=INT_MAX;
                for(auto&i:mp)
                    if(i.second<mnc){
                        mnc=i.second;
                        mnt=i.first;
                    }
                mn=mnc;
            }
            else if(price<mn){
                    mn=price;
                    mnt=timestamp;
                }
            else if(price>mx){
                    mx=price;
                    mxt=timestamp;
                }
            }
        
    }
    
    int current() {
        return c;
    }
    
    int maximum() {
        return mx;
    }
    
    int minimum() {
        return mn;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */