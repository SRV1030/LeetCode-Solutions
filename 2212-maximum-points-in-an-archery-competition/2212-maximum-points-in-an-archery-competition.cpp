class Solution {
public:
    vector<int> bobarr;
    int mxs=-1;
    void solve(int nA,vector<int>& al,int i,int sc,vector<int>&arr){
        if(i==al.size()){
            if(sc>mxs){
                bobarr=arr;
                mxs=sc;
                bobarr[0]=nA;
            }
            return;            
        }        
        arr.push_back(0);
        solve(nA,al,i+1,sc,arr);
        arr.pop_back();
        if(al[i]+1<=nA){
            arr.push_back(al[i]+1);
            nA-=(al[i]+1);
            sc+=i;
            solve(nA,al,i+1,sc,arr);
            arr.pop_back();
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
         vector<int> arr;
        solve(numArrows,aliceArrows,0,0,arr);
        return bobarr;
    }
};