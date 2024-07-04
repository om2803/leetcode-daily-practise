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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* sum_node=temp;
        
        while(temp!=NULL){
            int sum=0;
            while(sum_node->val!=0){
                sum+=sum_node->val;
                sum_node=sum_node->next;

            }
            temp->val=sum;
            sum_node=sum_node->next;
            temp->next=sum_node;
            temp=temp->next;
        }return head->next;

    }
};