#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <deque>

using namespace std;

#include<stack>
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (int i=0; i < S.size(); i++) {
            if (!st.empty() && S[i] == st.top()) {
                st.pop();
                continue;
            }
            st.push(S[i]);
        }

        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }   
};

int main()
{
    Solution st;
    auto res = st.removeDuplicates("dawd");

    cout << res << endl;
}