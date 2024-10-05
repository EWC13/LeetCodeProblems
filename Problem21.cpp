/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList;
        int nodesIterated = 0;
        int bytesMoved;
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        while(list1->next != nullptr)
        {
            list1 = list1->next;
            nodesIterated++;
        }
        bytesMoved = nodesIterated * 2;       
        list1->next = list2;
        list1 = list1-bytesMoved;

        bubbleSort(list1);
        return list1;
    }

    ListNode* bubbleSort(ListNode* list)
    {
        int tempVal = 0;
        bool NeedSort = false;
        int sizeOfLL = 1;
        ListNode* head;
        head = list;
        while(list->next != nullptr)
        {
            cout << list->next->val << list->val << endl;
            if(list->next->val < list->val)
            {
                tempVal = list->val;
                list->val = list->next->val;
                list->next->val = tempVal;
                NeedSort = true;
            }
            cout << list->val << endl;
            list = list->next;
            sizeOfLL++;
        }
        if(NeedSort == true)
        {
            list = head;
            cout << list->next->val;
            cout << "Recursive OOOO";
            return bubbleSort(list);
        }
        else
        {
            return list;
        }
    }
};
