# <a name="LeetCode">LeetCode</a>

## 20. 有效的括号

检查括号是否匹配，可以通过ASCII的值来进行；

相差1或者2就是匹配的。

<br>
<br>

## 42. 接雨水

这个问题的思路就是，每个位置的水都是取决于其左右两端最高位置中的较小的一个！

 

使用栈相当于是从横向的角度计算水：

- 栈顶元素是小于次顶的元素的，如果这个时候扫描到的数大于栈顶元素，那么cur和stack[Top-1]就把栈顶元素围起来了，可以接水
- 这个图里的，4和6把5围起来，可以接水为1；同时，计算完毕后把5退栈，6入栈
- 然后7把（456，这里主要是距离）围起来，和3计算围起来的水
- 这样子每一次计算相当于横向计算

- 使用栈的方法：

```cpp
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
```

<br>
<br>

## 71. 简化路径
使用stack的时候，vector和list都可以当作stack来用，不一定非要使用stack。

## <a name="84">84</a>
单调栈

## 85. 最大矩形
采用了84题的思路；
思考全部的矩形的情况：
- 逐渐考虑多行矩阵：一开始一行，依次增加一行(m[0:1], m[0:2], m[0:3]...)
- 对于每一个矩阵，可以看作是<a href="#LeetCode">LeetCode</a>



## 316. 去除重复字母
### 解题思路
采用贪心算法-栈实现
- 依次遍历每个字母，计算所有的字母的个数

**第二次遍历**：
- 考虑栈顶元素和当前遍历元素
    - 如果当前遍历元素s[i]大于栈顶元素，那么可以直接压栈
    - 如果当前遍历元素s[i]小于栈顶元素，那么考虑下面的情况
        -栈顶元素的个数>0，说明后面还有这个字母，可以退栈（因为栈顶元素字母序大，且后面还有这个字母，所以这里不需要栈顶的字母了）
        - 反之代表栈顶字母是最后一个，不应该退栈
    - 把遍历的字母s[i]压栈，并且标记。

c++实现，使用stack，为了标记之前已经压栈的字母，使用数组mark，计数使用数组cnt


### 代码

```cpp
#include <stack>

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mark[26] = {0};
        int cnt[26] = {0};
        //计算字母的个数
        for (int i =0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }

        stack<char> st;
        for (int i = 0; i < s.size(); i++){
            //如果字母已经压栈，就不考虑了
            if (mark[s[i]-'a'] != 1) {
                //如果s[i]字母序小并且栈顶元素个数>0(代表后面还有栈顶元素)
               while (!st.empty() && s[i] < st.top() && cnt[st.top()-'a']  > 0) {
                    mark[st.top() - 'a'] = 0;
                    st.pop();
                }
                st.push(s[i]);
                mark[s[i] - 'a'] = 1;
            }
            //每一次都要把遍历字母的个数-1
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
```



