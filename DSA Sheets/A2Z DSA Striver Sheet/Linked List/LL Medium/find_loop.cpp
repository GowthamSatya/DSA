#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(ListNode *head, ListNode *tail, int position)
{
    if (position == 0)
        return;

    ListNode *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // indiactes there is a cycle

                slow = head; // to find the exact position
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        ListNode *head, *tail;
        cin >> num;
        head = tail = new ListNode(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new ListNode(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution *ob;
        ListNode *ans = ob->detectCycle(head);

        if (ans == NULL)
            cout << "NULL" << endl;
        else
            cout << ans->data << endl;
    }
    return 0;
}