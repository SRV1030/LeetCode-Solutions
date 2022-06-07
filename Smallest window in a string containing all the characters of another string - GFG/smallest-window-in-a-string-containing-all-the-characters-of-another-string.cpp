// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>mp(257),ms(257);
        for(auto&i:p)mp[i]++;
        int d=p.size(),c=0,st=0,mn=INT_MAX,ind=-1;
        for(int i=0;i<s.size();++i){
            ms[s[i]]++;
            if(ms[s[i]]<=mp[s[i]])c++;
            if(c==d){
                while(st<s.size() && (ms[s[st]]==0 || ms[s[st]]>mp[s[st]]) ){
                    if(ms[s[st]]>mp[s[st]])ms[s[st]]--;
                    ++st;
                }
                int l=i-st+1;
                if(l<mn){
                    mn=l;
                    ind=st;
                }
            }
        }
        return ind==-1?"-1":s.substr(ind,mn);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends