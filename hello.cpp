#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main()
{

    cout << '===============' << endl;
}