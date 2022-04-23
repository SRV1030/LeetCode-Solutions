class Solution {
public:

    // Encodes a URL to a shortened URL.

    unordered_map<string,string> mp;
    int num = 0;

    string encode(string longUrl) {

        num++;
        string addon = to_string(num);
        string ans = "http://tinyurl.com/";
        ans+=string(addon);
        mp[ans] = longUrl;
        return ans;

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};