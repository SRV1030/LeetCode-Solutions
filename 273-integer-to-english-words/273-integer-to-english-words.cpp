class Solution {
public:
    vector<string> things = {"", "", "Thousand", "Million", "Billion"};
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"}; 
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> specials = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  
    const string HUNDRED = "Hundred";
  
    string small(int no) {
      if(no >= 1 && no <= 9) return ones[no];
      if(no >= 10 && no <= 19) return specials[no%10]; 
      if(no <= 99) {
        int d = no / 10;
        return tens[d] + (no % 10 ? (" " + small(no%10)) : "");
      }
      int d = no / 100;
      return ones[d] + " " + HUNDRED + (no % 100 ? (" " + small(no%100)) : "");
    }
  
    string big(int no, int c) {
      if(no == 0) return "";
      string ans = big(no/1000, c+1);
      int rem = no % 1000;
      if(rem != 0) {
        ans += (!ans.empty() ? " " :"" ) + small(rem) + (c == 0 || c == 1 ? "" : " " ) + things[c];
      }
      return ans;
    }
  
    string numberToWords(int num) {
      if(num == 0) return "Zero";
      return big(num, 1);
    }
};