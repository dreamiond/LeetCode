//leetcode535:Encode and Decode TinyURL
/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
private:
	vector<char> dic{ '0','1','2','3','4','5','6','7','8','9',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
	};
	int num = 0;
	unordered_map<string, string> code;
public:

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string shortUrl = to62(num++);
		code[shortUrl] = longUrl;
		return shortUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return code[shortUrl];
	}

	string to62(int num) {
		string res = "";
		while (num) {
			res = dic[num % 62] + res;
			num /= 62;
		}
		res = string(7 - res.size(), 0) + res;
		return res;
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));