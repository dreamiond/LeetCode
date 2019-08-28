//leetcode609:Find Duplicate File in System
/*
Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

Example 1:

Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]


Note:

No order is required for the final output.
You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].
The number of files given is in the range of [1,20000].
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. Directory path and file info are separated by a single blank space.


Follow-up beyond contest:
Imagine you are given a real file system, how will you search files? DFS or BFS?
If the file content is very large (GB level), how will you modify your solution?
If you can only read the file by 1kb each time, how will you modify your solution?
What is the time complexity of your modified solution? What is the most time-consuming part and memory consuming part of it? How to optimize?
How to make sure the duplicated files you find are not false positive?
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//ע�⣺�����ʱ�򣬿�����unordered_map<x,vector<y>>����unordered_multimap<x,y>

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>> content2Path;
		vector<vector<string>> res;
		for (auto s : paths) {
			int idx = 0;
			while (s[idx] != ' ') ++idx;
			string path = s.substr(0, idx);
			for (int i = idx + 1, leftParentheses = idx + 1, rightParentheses = idx - 1; i < s.size(); ++i) {
				if (s[i] == '(') {
					leftParentheses = i;
				}
				else if (s[i] == ')') {
					string wholePath = path + "/" + s.substr(rightParentheses + 2, leftParentheses - rightParentheses - 2);
					string content = s.substr(leftParentheses + 1, i - leftParentheses - 1);
					rightParentheses = i;
					content2Path[content].emplace_back(wholePath);
				}
			}
		}
		for (auto cp : content2Path) {
			if (cp.second.size() > 1) {
				res.emplace_back(cp.second);
			}
		}
		return res;
	}
};

//int main() {
//	vector<string> path{ "root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)" };
//	Solution sol;
//	sol.findDuplicate(path);
//}