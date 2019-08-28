//leetcode68:Text Justification
/*
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
"This    is    an",
"example  of text",
"justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
"What   must   be",
"acknowledgment  ",
"shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
"to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
"Science  is  what we",
"understand      well",
"enough to explain to",
"a  computer.  Art is",
"everything  else  we",
"do                  "
]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
private:
	struct line
	{
		vector<string> strs;
		int length = 0;
	};
	line aLine;
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<line> lines;
		for (const auto &word : words) {
			//这一行空
			if (aLine.length == 0) {
				aLine.strs.emplace_back(word);
				aLine.length += word.size();
			}
			//这一行不空，能加新单词
			else if (aLine.length + word.size() + 1 <= maxWidth) {
				aLine.strs.emplace_back(word);
				aLine.length = aLine.length + 1 + word.size();
			}
			//这一行满了
			else {
				lines.emplace_back(aLine);
				aLine.strs.clear();
				aLine.length = 0;
				aLine.strs.emplace_back(word);
				aLine.length += word.size();
			}
		}
		lines.emplace_back(aLine);
		vector<string> res;
		for (int i = 0; i < lines.size() - 1; ++i) {
			res.emplace_back(justify(lines[i], maxWidth));
		}

		vector<string> lastv = lines[lines.size() - 1].strs;
		string lastLine = "";
		for (int i = 0; i < lastv.size() - 1; ++i) {
			lastLine = lastLine + lastv[i] + " ";
		}
		lastLine += lastv[lastv.size() - 1];
		if (lastLine.size() != maxWidth) lastLine += string(maxWidth - lastLine.size(), ' ');
		res.emplace_back(lastLine);
		return res;
	}

	string justify(line ln, int maxLength) {
		if (ln.strs.size() == 1) {
			if (maxLength == ln.strs[0].size()) return ln.strs[0];
			else return ln.strs[0] + string(maxLength - ln.strs[0].size(), ' ');
		} 
		int spaceNum = ln.strs.size() - 1;
		int spaceCharact = maxLength - (ln.length - spaceNum);
		int average = spaceCharact / spaceNum;
		int n = spaceCharact - average*spaceNum;
		string res = "";
		int idx = 0;
		for (; idx < n; ++idx) {
			res = res + ln.strs[idx] + string(average + 1, ' ');
		}
		for (; idx < spaceNum; ++idx) {
			res = res + ln.strs[idx] + string(average, ' ');
		}
		res += ln.strs[idx];
		return res;
	}
};

int main() {
	vector<string> v{ "ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country" };
	Solution sol;
	sol.fullJustify(v, 16);
}