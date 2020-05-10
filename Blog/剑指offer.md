#剑指offer
## 二维数组的查找
>在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
### 暴力算法：无脑遍历
- 时间复杂度$O(n^2)$

### 因为每行都是递增，从上到下也是递增
- 左下角和右上角的元素有特殊性。以右上角为例，开始元素选择右上角元素：
  - 比当前元素小的必定在同行的左边，row不变，col--
  - 比当前元素大的元素必定在下面，row++，col不变
  - 一直循环，直到找到target返回true
  - 或者找不到，row和col越界返回false


## 替换空格
>请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy

解题思路：
~~使用内置函数replaceall肯定可以，但是面试题这么做是蠢！~~
### 空间换时间
另开一块空间，遍历原字符串，遇到‘ ’就换成“%20”，否则直接复制字符。这种做法需要额外的空间
### 在源字符串上操作
- 先前序扫描一遍，找出有几个‘ ’, 记为num
- 这时就能计算出修改后的字符串长度 l2 = l1 + num * 2
- 然后再后序扫描原字符串
  - 不是‘ ’，那么str[l2--] = str[l1--]
  - 否则str[l2--]='0'; str[l2--]='2'; str[l2--]='%'; l1--;

```
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int num = 0;
        int l = 0;
        for (; str[l] != '\0'; l++) {
            if(str[l] == ' ') {
                num++;
            }
        }
        int end = l + num * 2;
        # 先给修改后的字符串补充终止符'\0'
        str[end--] = '\0';
        for (int i = l-1; i >=0 ; i--) {
            if (str[i] == ' ') {
                str[end--] = '0';
                str[end--] = '2';
                str[end--] = '%';
            }else {
                str[end--]=str[i];
            }
        }
    }
};
```


### c++的考点之一：
- c++中的string和char之间的各种转换


## 从尾到头打印链表
>输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
### 采用栈来解决这一问题
- 从头开始遍历链表，把数据保存在栈里，之后再依次弹栈输出即可。
```
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        stack<int> tmp;
        while (head != NULL) {
            tmp.push(head->val);
            head = head->next;
        }
        vector<int> res;
        while (!tmp.empty()) {
            res.push_back(tmp.top());
            tmp.pop();
        }
        return res;
    }
};
```
### 采用指针把链表逆序
head, prev, cur, next
[指针法的链接](https://www.nowcoder.com/questionTerminal/d0267f7f55b3412ba93bd35cfa8e8035?answerType=1&f=discussion)

使用next来遍历
- next指向下一个节点
- 改变当前节点的指向：cur->next = prev
- prev = cur：先前节点指向当前节点
- cur = next：当前节点指向下一个节点