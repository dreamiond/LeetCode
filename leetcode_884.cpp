//leetcode884:Uncommon Words from Two Sentences
/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words.

You may return the list in any order.



Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]


Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

//class Solution {
//public:
//	vector<string> uncommonFromSentences(string A, string B) {
//		unordered_set<string> sentence1, sentence2;
//		vector<string> aSplit = split(A), bSplit = split(B);
//		for (auto i : aSplit) sentence1.insert(i);
//		for (auto i : bSplit) sentence2.insert(i);
//		/*cout << "split:" << endl;
//		cout << "a:" << endl;
//		for (auto i : aSplit) cout << i << " ";
//		cout << endl<<"b:" << endl;
//		for (auto i : bSplit) cout << i << " ";*/
//		vector<string> aOnce = appearOnce(aSplit), bOnce = appearOnce(bSplit);
//		/*cout << "once:" << endl;
//		cout << "a:" << endl;
//		for (auto i : aOnce) cout << i << " ";
//		cout << endl<<"b:" << endl;
//		for (auto i : bOnce) cout << i << " ";*/
//		vector<string> res;
//		for (auto i : aOnce) {
//			if (sentence2.find(i) == sentence2.end()) res.push_back(i);
//		}
//		for (auto i : bOnce) {
//			if (sentence1.find(i) == sentence1.end()) res.push_back(i);
//		}
//		return res;
//	}
//	vector<string> split(string s) {
//		int start = 0;
//		vector<string> res;
//		for (int i = 0; i < s.size(); ++i) {
//			if (s[i] == ' ') {
//				res.push_back(s.substr(start, i - start));
//				start = i + 1;
//			}
//		}
//		res.push_back(s.substr(start, s.size() - start));
//		return res;
//	}
//	vector<string> appearOnce(vector<string> s) {
//		unordered_map<string,int> dict;
//		vector<string> res;
//		for (auto i : s) {
//			dict[i] = dict[i] + 1;
//			//cout << i << " " << dict[i] << endl;
//		}
//		for (auto i : dict) {
//			if (i.second == 1) res.push_back(i.first);
//		}
//		return res;
//	}
//};
//
////void main() {
////	string a = "s z z z s", b = "s z ejt";
////	Solution sol;
////	sol.uncommonFromSentences(a, b);
////	//vector<string> aSplit = sol.split(a);
////	//for (auto i : aSplit) cout << i << " ";
////	//vector<string> aOnce = sol.appearOnce(aSplit);
////	//cout << endl;
////	//for (auto i : aOnce) cout << i << " ";
////}

class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		unordered_map<string,int> dict;
		istringstream iss(A + " " + B);
		while (iss >> A) dict[A]++;
		vector<string> res;
		for (auto i : dict) {
			if (i.second == 1) res.push_back(i.first);
		}
		return res;
	}
};