// https://leetcode.com/problems/find-in-mountain-array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bnpeak(MountainArray &marr){
        int l=0,r=marr.length()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m-1>=0 && m+1<marr.length() && (marr.get(m-1)<marr.get(m) && marr.get(m)>marr.get(m+1))) return m;
            else if(m-1>=0 && marr.get(m-1)>marr.get(m))r=m-1;
            else l=m+1;
        }
        return -1;
    }
    int bnsearchlft(MountainArray &marr,int l,int r,int k){
        while(l<=r){
            int m=l+(r-l)/2;
            if(marr.get(m)==k) return m;
            else if(marr.get(m)>k) r=m-1;
            else l=m+1;
        }
        return -1;
    }
    int bnsearchrt(MountainArray &marr,int l,int r,int k){
        while(l<=r){
            int m=l+(r-l)/2;
            if(marr.get(m)==k) return m;
            else if(marr.get(m)>k) l=m+1;
            else r=m-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakInd=bnpeak(mountainArr),mx=mountainArr.get(peakInd);
        if(mx==target) return peakInd;
        else if(mx<target) return -1;
        int bnlft=bnsearchlft(mountainArr,0,peakInd,target);
        int bnrt=bnsearchrt(mountainArr,peakInd,mountainArr.length()-1,target);
        if(bnlft!=-1 && bnrt!=-1) return min(bnlft,bnrt);
        else return bnlft!=-1?bnlft:bnrt;
    }
};