# 关于栈的题目

## <a name="1021">1021</a>. [删除最外层的括号](https://leetcode-cn.com/problems/remove-outermost-parentheses/)

**题解**：
对于括号匹配，这里提出的**原语**可以通过计数来实现，从左到右计数'('和')'，当二者的个数相等的时候就是一个有效的最小单位
下面的示例用[a,b]代表'('和')'的个数，初始设置为[0,0]
- (()): 这里从左到右数为[1,0],[2,0],[2,1],[2,2]。就是相等的时候满足**原语**的条件
- (()()): [1,0],[2,0],[2,1],[3,1],[3,2],[3,3]

所以在遍历的过程中使用上述的方法就可以实现**原语**的查找

这个题的trick是初始设置L=1，并且忽略**原语**的第一个'('的遍历，利用想等条件重置！(见代码)

<br>

```
class Solution {
public:
    string removeOuterParentheses(string s) {
        int L = 1, R = 0;
        string res;
        for (int i=1; i<s.size(); i++) {
            if (s[i]=='(')
                L++;
            else
                R++;
            if (L == R) {
                i++;
                L=1;
                R=0;
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

```
<br>


## <a name="面试题03.04">面试题03.04</a>. [化栈为队](https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci/)

没啥好讲的：
```
#include<stack>
class MyQueue {
    stack<int> ps;
    stack<int> pk;
    bool Psflag = true;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        bool Psflag = true;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (Psflag) {
            ps.push(x);
        }else {
            while (!pk.empty()) {
                ps.push(pk.top());
                pk.pop();
            }
            Psflag = true;
            ps.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if (Psflag){
            while (!ps.empty()) {
                pk.push(ps.top());
                ps.pop();
            }
            Psflag = false; 
        }
        res = pk.top();
        pk.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (Psflag){
            while (!ps.empty()) {
                pk.push(ps.top());
                ps.pop();
            }
            Psflag = false;
        }
        return pk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return ps.empty() && pk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

<br>

## 