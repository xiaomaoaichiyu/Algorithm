#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <deque>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mark[26] = {0};
        int cnt[26] = {0};
        for (int i =0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }

        stack<char> st;
        for (int i = 0; i < s.size(); i++){
            if (mark[s[i]-'a'] != 1) {
                while (!st.empty() && s[i] < st.top() && cnt[s[i]-'a']  > 0) {
                    mark[st.top() - 'a'] = 0;
                    st.pop();
                }
                st.push(s[i]);
                mark[s[i] - 'a'] = 1;
            }
            cnt[s[i] - 'a']--;
        }
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto res = s.removeDuplicateLetters("cbacdcbc");
    cout << res << endl;
}