//leetcode638:Shopping Offers
/*
In LeetCode Store, there are some kinds of items to sell. Each item has a price.

However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.

Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.

You could use any of special offers as many times as you want.

Example 1:
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation:
There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B.
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
Example 2:
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation:
The price of A is $2, and $3 for B, $4 for C.
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C.
You cannot add more items, though only $9 for 2A ,2B and 1C.
Note:
There are at most 6 kinds of items, 100 special offers.
For each item, you need to buy at most 6 of them.
You are not allowed to buy more items than you want, even if that would lower the overall price.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//使用动态规划能做，但是会非常麻烦，因为有最多六种商品，需要一个六层循环
//class Solution {
//public:
//	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
//		/*
//		动态规划：
//		商品i的价格为Price(i)
//		搭配组和j的价格为SPPrice(j),包含的各商品数量为向量SPNum(j)
//		先要求买各商品数量为向量Total
//		对于特定数量的商品向量x，其花销最小为f(x)
//		则：
//		f(x+i*1) = f(x) + Price(i)
//		f(x+SPNum(j)) = f(x) + SPPrice(j)
//		*/
//		int itemNum = price.size();
//		unordered_map<vector<int>, int> f;
//		f[vector<int>(6, 0)] = 0;
//		for (int i1 = 0; i1 < needs[0]; ++i1) {
//			if (needs[1]) {
//				for (int i2 = 0; i2 < needs[1]; ++i2) {
//					if (needs[2]) {
//						for (int i3 = 0; i3 < needs[1]; ++i3) {
//							if (needs[3]) {
//								for (int i4 = 0; i4 < needs[1]; ++i4) {
//									if (needs[4]) {
//										for (int i5 = 0; i5 < needs[1]; ++i5) {
//											if (needs[5]) {
//												for (int i6 = 0; i6 < needs[1]; ++i6) {
//													
//												}
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//
//	}
//	vector<int> vecPlus(vector<int> a, vector<int> b) {
//		vector<int> res;
//		for (auto i : a) res.push_back(i);
//		for (int i = 0; i < b.size(); ++i) {
//			res[i] = res[i] + b[i];
//		}
//		return res;
//	}
//	bool isZero(vector<int> v) {
//		for (auto i : v) {
//			if (i != 0) return false;
//		}
//		return true;
//	}
//
//};