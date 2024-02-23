https://leetcode.com/problems/valid-parentheses/submissions/1184337969/
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (!st.empty() && ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{'))) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return st.empty();
    }
};
