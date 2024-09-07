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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp=new ListNode();
        temp->next=head;
        ListNode* prev=temp;
        ListNode* curr=head;

        int n=nums.size();
        unordered_set<int> st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        while(curr!=NULL){
            if(st.contains(curr->val)){
                curr=curr->next;
                prev->next=curr;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }return temp->next;
    }
};