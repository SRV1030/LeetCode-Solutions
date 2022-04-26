class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int mnC=0,edges=0;
        vector<bool>inMST(n,false);
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        while(edges<n){
            int currEd=INT_MAX;
            int currN=-1;
            for(int node=0;node<n;node++){
                if(inMST[node])continue;
                if(currEd>dis[node]){
                    currEd=dis[node];
                    currN=node;
                }
            }
            mnC+=currEd;
            edges++;
            inMST[currN]=true;
            for(int nxtN=0;nxtN<n;nxtN++){
                if(inMST[nxtN])continue;
                int wt=abs(points[currN][0]-points[nxtN][0])+abs(points[currN][1]-points[nxtN][1]);
                if(dis[nxtN]>wt)dis[nxtN]=wt;
            }
        }
        return mnC;
    }
};