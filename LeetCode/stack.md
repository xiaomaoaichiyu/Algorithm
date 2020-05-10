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

## <a name="682">682</a>. [棒球比赛](https://leetcode-cn.com/problems/baseball-game/)

本身没啥难点，需要注意的两点
- 变量记得初始化，你不知道对方的平台是否默认清零！
- stoi(s)比起atoi(s.c_str())的数度更快?不知道是不是因为平台的原因！
  - [函数区别](https://blog.csdn.net/yky__xukai/article/details/79554963)
    - atoi不会提醒越界（数字大小超过int范围），会直接在边界截断，即返回最大的int或者最小的int
    - 而stoi会报错！
  - 应该是因为atoi先要把string变为char const*所以慢

<br>

## <a name="225">225</a>. [用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)
和题目<a href="#面试题03.04">面试题03.04</a>类似

三种思路
- 两个队列实现栈：入栈O(1)，出栈O(n)，可以记录栈顶元素，使得Top()为O(1)。每次出栈都转换到两一个队列中，在转换回来
- 两个队列实现栈：入栈O(n)，出栈O(1)。入栈时把q1的转移到q2，入栈后再移回来。出栈每次弹出q1的队首
- 一个队列。入站的时候，循环替换，把元素放到队首，出栈直接弹出
  - q.push(q.peek())：把元素取出来加到后边

### queue的使用
- queue.front() : 返回队首元素
- queue.pop() : 弹出队首元素，但是不返回值
- queue.push() : 入队
- queue.empty() : 判断是否为空
- queue.back() : 访问队尾元素

<br>

## <a name="232">232</a>. [用栈实现队列](https://leetcode-cn.com/problems/implement-queue-using-stacks/)
知识点：
- 两个栈实现队列：s1和s2，s1用来入队，s2用来出队，每次出队的时候都把s1的放到s2，然后出队；这样，即使s2有数据，不影响s1的入队，而且s2在未空前可以一直出队！
- 摊还分析
  - 就是通过上述的表述我们发现，出队的复杂度最坏是n，而且，从s1到s2总共就会走n步，剩下的出队，都是O(1)的，所以出队的平均事件复杂度为O((n+n-1) / n) = O(1)
