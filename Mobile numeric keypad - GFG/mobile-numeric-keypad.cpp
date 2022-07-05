// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int kp[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,0,10}};
	int dx[5]={0,0,-1,0,1};
	int dy[5]={0,-1,0,1,0};
	long long dp[11][27];
	long long dfs(int i,int j,int n){
	    if(i<0 || j<0 || i>=4 || j>=3 || kp[i][j]==10) return 0;
	    if(n<=1) return n;
	    if(dp[kp[i][j]][n]!=-1)return dp[kp[i][j]][n];
	    long long ans=0;
	    for(int d=0;d<5;++d)ans+=dfs(i+dx[d],j+dy[d],n-1);
	    return dp[kp[i][j]][n]=ans;
	    
	}
	long long getCount(int N)
	{
		// Your code goes here
		memset(dp,-1,sizeof(dp));
		long long ans=0;
		for(int i=0;i<4;++i)
		    for(int j=0;j<3;++j)ans+=dfs(i,j,N);
		 return ans;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends