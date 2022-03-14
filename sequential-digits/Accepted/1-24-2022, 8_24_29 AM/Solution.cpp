// https://leetcode.com/problems/sequential-digits

// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         string l=to_string(low),h=to_string(high);
//         string p="123456789";
//         int s=l.size(),e=h.size();
//         vector<int> ans;
//         for(int sz=s;sz<=e;sz++){
//             for(int i=0;i+sz<10;i++){
//                 int v=stoi(p.substr(i,sz));
//                 if(v<low) continue;
//                 if(v>high) return ans;
//                 ans.push_back(v);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
	// generating the sequence
    void generate(int start, int inc,vector<int>& sequence){
        while(start%10!=0){
            sequence.push_back(start);
            start += inc;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> starts = {12,123,1234,12345,123456,1234567,12345678};
        vector<int> increments = {11,111,1111,11111,111111,1111111,11111111};
        vector<int> sequence;
		
        for(int i = 0; i < increments.size(); i++){
            generate(starts[i],increments[i],sequence);
        }
		
        vector<int> ans;
        for(int i = 0; i < sequence.size(); i++){
            if(sequence[i]>= low and sequence[i]<=high)
                ans.push_back(sequence[i]);
        }
		
		// The  start vector contains upto 8 digits only
		// so we are checking for the 9 digit also and only 123456789 satisfies the sequence
        if(123456789<=high and 123456789>=low)
            ans.push_back(123456789);
			
        return ans;
    }
};