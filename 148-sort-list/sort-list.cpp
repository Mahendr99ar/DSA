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
    ListNode* sortList(ListNode* head) {
        vector<int> nigga;
        ListNode* temp = head;
        while(temp!=nullptr){
            nigga.push_back(temp->val);
            temp = temp->next;
        }
        sort(nigga.begin(),nigga.end());
        temp=head;
        for(int i=0;i<nigga.size();i++){
            temp->val = nigga[i];
            temp=temp->next;
        }
        return head;
    }
};