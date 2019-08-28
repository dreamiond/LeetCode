//leetcode804:Unique Morse Code Words
/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation:
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".


Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_map<char, string> dic=
		{
			{'a',".-" },
			{'b',"-..." },
			{'c',"-.-." },
			{'d',"-.." },
			{'e',"." },
			{'f',"..-." },
			{'g',"--." },
			{'h',"...." },
			{'i',".." },
			{ 'j',".---" },
			{ 'k',"-.-" },
			{ 'l', ".-.." },
			{ 'm',"--" },
			{ 'n', "-." },
			{ 'o', "---" },
			{ 'p',".--." },
			{ 'q', "--.-" },
			{ 'r',".-." },
			{ 's',"..." },
			{ 't', "-" },
			{ 'u',"..-" },
			{ 'v', "...-" },
			{ 'w',".--" },
			{ 'x', "-..-" },
			{ 'y',"-.--" },
			{ 'z', "--.." }
		};
		unordered_set<string> transformation;
		for (auto str : words) {
			string temp;
			for (auto i : str) {
				temp += dic[i];
			}
			transformation.insert(temp);
		}
		return transformation.size();
	}

};

//int main() {
//	vector<string> v = { "gin", "zen", "gig", "msg" };
//	Solution sol;
//	cout<<sol.uniqueMorseRepresentations(v);
//}