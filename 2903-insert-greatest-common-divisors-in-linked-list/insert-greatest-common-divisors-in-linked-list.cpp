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
    int GCD(int a, int b){
        if(b==0)
        return a;
        else{
            return GCD(b, a%b);
        }
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        ListNode* temp1=head;
        ListNode* temp2=head->next;

        while(temp2!=NULL){
            int gcd_val=GCD(temp1->val, temp2->val);
            ListNode* gcd_node=new ListNode(gcd_val);

            gcd_node->next=temp2;
            temp1->next=gcd_node;

            temp1=temp2;
            temp2=temp2->next;
        }return head;
    }
};