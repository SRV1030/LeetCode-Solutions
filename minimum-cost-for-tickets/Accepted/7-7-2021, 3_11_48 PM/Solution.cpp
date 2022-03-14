// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:   
    int binsearch(vector<int> &days, int i, int target)
{
	int j = days.size() - 1;

	while(i <= j)
	{
		int mid = (i+j)/2;
		if(target == days[mid] || (days[mid]<target && mid+1 < days.size() && days[mid+1] > target))
			return mid + 1;
		else if(target > days[mid])
			i = mid + 1;
		else
			j = mid - 1;
	}

	return -1;
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>ans(n,0);
       for(int i=n-1;i>=0;i--){
          int d6 = binsearch(days,i,days[i]+6);
		int d29 = binsearch(days,i,days[i]+29);

           int a=costs[0], b=costs[1], c=costs[2];
           if(i+1<n)a+=ans[i+1];
           if(d6>=0 && d6<n)b+=ans[d6];
           if(d29>=0 && d29<n)c+=ans[d29];
           ans[i]=min(a,min(b,c));           
       }
        return ans[0];
    }
};