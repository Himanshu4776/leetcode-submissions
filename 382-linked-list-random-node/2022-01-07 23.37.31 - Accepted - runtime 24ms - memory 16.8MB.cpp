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
    int len = 0;
    ListNode* node;
    vector<int>arr;
public:
    Solution(ListNode* head) {
        node = head;
        ListNode* temp = node;
        while(temp)
        {
            len++;
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int random_index_generated = rand()%len;
        // now get this value by looping temp.
        // ListNode* temp = node;
        // for(int i=0;i<random_index_generated;i++)
        // {
        //     temp = temp->next;
        // }
        // return temp->val;
        return arr[random_index_generated];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */