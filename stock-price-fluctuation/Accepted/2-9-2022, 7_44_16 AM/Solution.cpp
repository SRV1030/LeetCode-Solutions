// https://leetcode.com/problems/stock-price-fluctuation

class StockPrice {
public:
    
    int price;
    multiset<int> m;
    map<int, int> value;
    int mx;
    
    StockPrice() {
        price = 0;
        mx = 0;
    }
    
    void update(int timestamp, int p) {
        price = p;
        if ( value.count(timestamp) ) {
            m.erase ( m.find(value[timestamp]) );
        }
        
        m.insert ( price );
        value[timestamp] = price;
        mx = max (mx, timestamp);
    }
    
    int current() {
        return value[mx];
    }
    
    int maximum() {
        return *m.rbegin();
    }
    
    int minimum() {
        return *m.begin();
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