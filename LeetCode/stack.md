# ����ջ����Ŀ

## <a name="1021">1021</a>. [ɾ������������](https://leetcode-cn.com/problems/remove-outermost-parentheses/)

**���**��
��������ƥ�䣬���������**ԭ��**����ͨ��������ʵ�֣������Ҽ���'('��')'�������ߵĸ�����ȵ�ʱ�����һ����Ч����С��λ
�����ʾ����[a,b]����'('��')'�ĸ�������ʼ����Ϊ[0,0]
- (()): �����������Ϊ[1,0],[2,0],[2,1],[2,2]��������ȵ�ʱ������**ԭ��**������
- (()()): [1,0],[2,0],[2,1],[3,1],[3,2],[3,3]

�����ڱ����Ĺ�����ʹ�������ķ����Ϳ���ʵ��**ԭ��**�Ĳ���

������trick�ǳ�ʼ����L=1�����Һ���**ԭ��**�ĵ�һ��'('�ı�������������������ã�(������)

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


## <a name="������03.04">������03.04</a>. [��ջΪ��](https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci/)

ûɶ�ý��ģ�
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