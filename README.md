# 做题笔记

## leetcode1190

[ Reverse Substrings Between Each Pair of Parentheses ]( https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/ )

虫洞算法！

In the first pass, use a stack to find all paired parentheses.

Now just imgine that all parentheses are wormholes.
And the paired parentheses are connected to each other.

In the second pass,traverse through the paired parentheses and generate the result string `res`.

`i` is the index of current position.
`d` is the direction of traversing.

```c++
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> opened, pair(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                opened.push_back(i);
            if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')')
                i = pair[i], d = -d;
            else
                res += s[i];
        }
        return res;
    }
```

