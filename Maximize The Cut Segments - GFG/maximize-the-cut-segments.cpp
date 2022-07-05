// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int t[n+1];
        t[0]=0;
        for(int i=1;i<=n;i++){
            t[i]=-1;
            if(i-x>=0)t[i]=max(t[i],t[i-x]);
            if(i-y>=0)t[i]=max(t[i],t[i-y]);
            if(i-z>=0)t[i]=max(t[i],t[i-z]);
            if(t[i]!=-1)t[i]++;
        }
        return max(t[n],0);
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends