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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        vector<ListNode*> ans(k);

        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int size=n/k;
        int rem_nodes=n%k;
        temp=head;
        for(int i=0;i<k;i++){
            ListNode newpart(0);
            ListNode* tail= &newpart;

            int currsize=size;
            if(rem_nodes>0){
                rem_nodes--;
                currsize++;
            }
            for(int j=0;j<currsize;j++){
                tail->next= new ListNode(temp->val);
                tail=tail->next;
                temp=temp->next;
            }
            ans[i]=newpart.next;
        }return ans;
    }
};