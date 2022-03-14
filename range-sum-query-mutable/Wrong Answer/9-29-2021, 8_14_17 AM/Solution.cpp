// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public: vector<int>org,st;
    int n;
    int constree(int si,int sl,int sr){
        if(sl==sr){
            st[si]=org[sl];
            return st[si];
        }
        int m=sl+(sr-sl)/2;
        st[si]=constree(2*si+1,sl,m)+constree(2*si+2,m+1,sr);
        return st[si];
    }
    void updatetree(int si,int sl,int sr,int pos,int dif){
        if(sl>pos || sr<pos) return;
        st[si]+=dif;
        if(sl!=sr){
            int m=sl+(sr-sl)/2;
            updatetree(2*si+1,sl,m,pos,dif);
            updatetree(2*si+2,m+1,sr,pos,dif);            
        }
    }
    int gets(int si,int sl,int sr,int ql,int qr){
        if(ql<=sl && qr>=sr)return st[si];
        if(sr<ql || sl>ql) return 0;
        int m=sl+(sr-sl)/2;
        st[si]=gets(2*si+1,sl,m,ql,qr)+gets(2*si+2,m+1,sr,ql,qr);
        return st[si];  
    }
    NumArray(vector<int>& nums) {
        org=nums;
        n=org.size();
        st=vector<int>(4*n);
        constree(0,0,n-1);
    }
    
    void update(int index, int val) {
        int dif=val-org[index];
        org[index]=val;
        updatetree(0,0,n-1,index,dif);
    }
    
    int sumRange(int left, int right) {        
        return gets(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */