// https://leetcode.com/problems/encode-and-decode-tinyurl

class Solution {
public:
    string mp[10001];
    int c=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp[c++]=longUrl;
        return to_string(c-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));