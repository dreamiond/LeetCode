//leetcode874:Walking Robot Simulation
/*
A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles.

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.



Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)


Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <math.h>

using namespace std;

struct VectorHash {
	int operator()(const vector<int>& v) const {
		hash<int> hasher;
		int seed = 0;
		for (int i : v) {
			seed ^= hasher(i);
		}
		return seed;
	}
};
using MySet = unordered_set<vector<int>, VectorHash>;


class Solution {
private:
	const int TURNLEFT = -2, TURNRIGHT = -1;
	const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int face = UP;
		vector<int> pos = { 0,0 };
		MySet obs;
		int res = 0;
		for (auto i : obstacles) obs.insert(i);
		for (auto v : commands) {
			if (v == TURNLEFT) face = (face + 3) % 4;
			else if (v == TURNRIGHT) face = (face + 1) % 4;
			else {
				move(pos, face, v, obs, res);
			}
		}
		cout << pos[0] << ";" << pos[1] << endl;
		return res;
	}
	void move(vector<int> &pos, int face, int dis, const MySet &obs,int &res) {
		if (face == UP) {
			while (dis--) {
				++pos[1];
				if (obs.find(pos) != obs.end()) { --pos[1]; break; }
			}
		}
		else if (face == DOWN) {
			while (dis--) {
				--pos[1];
				if (obs.find(pos) != obs.end()) { ++pos[1]; break; }
			}
		}
		else if (face == LEFT) {
			while (dis--) {
				--pos[0];
				if (obs.find(pos) != obs.end()) { ++pos[0]; break; }
			}
		}
		else {
			while (dis--) {
				++pos[0];
				if (obs.find(pos) != obs.end()) { --pos[0]; break; }
			}
		}
		res = max(res, pos[0] * pos[0] + pos[1] * pos[1]);
	}
};

//class Solution {
//public:
//	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//		unordered_set<string> obs;
//		for (auto i:obstacles) obs.insert(to_string(i[0]) + "#" + to_string(i[1]));
//		int res = 0, dir = 0, x = 0, y = 0;
//		vector<vector<int>> ds = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
//		for (int i = 0; i<commands.size(); i++) {
//			if (commands[i] == -2) dir--;
//			else if (commands[i] == -1) dir++;
//			else {
//				for (int j = 0; j<commands[i]; j++) {
//					string pos = to_string(x + ds[dir][0]) + "#" + to_string(y + ds[dir][1]);
//					if (obs.find(pos) != obs.end()) break;
//					x += ds[dir][0], y += ds[dir][1];
//				}
//				res = max(res, x*x + y*y);
//			}
//			if (dir == -1) dir = 3;
//			if (dir == 4) dir = 0;
//		}
//		return res;
//	}
//};

//void main() {
//	vector<int> command{ 4,-1,4,-2,4 };
//	vector<vector<int>> obs{ {2,4} };
//	Solution sol;
//	cout << sol.robotSim(command, obs) << endl;
//}