//leetcode599:Minimum Index Sum of Two Lists
/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	struct IntDefaultedTo2000 {
		int num = 2000;
	};
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, pair<IntDefaultedTo2000, IntDefaultedTo2000>> dict;
		for (int i = 0; i < list1.size();++i) {
			dict[list1[i]].first.num = i;
		}
		for (int i = 0; i < list2.size(); ++i) {
			dict[list2[i]].second.num = i;
		}
		vector<string> res;
		int minimumIndexSum = 2000;
		for (auto str : dict) {
			if (str.second.first.num + str.second.second.num == minimumIndexSum) {
				res.push_back(str.first);
			}
			else if (str.second.first.num + str.second.second.num < minimumIndexSum) {
				minimumIndexSum = str.second.first.num + str.second.second.num;
				res.clear();
				res.push_back(str.first);
			}
		}
		return res;
	}
};