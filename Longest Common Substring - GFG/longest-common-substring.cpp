// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int t[n+1][m+1];
        int l=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)t[i][j]=0;
                else{
                    if(s1[i-1]==s2[j-1]){
                        t[i][j]=1+t[i-1][j-1];
                        if(t[i][j]>l)l=t[i][j];
                    } 
                    else t[i][j]=0;
                }
            }
        return l;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends