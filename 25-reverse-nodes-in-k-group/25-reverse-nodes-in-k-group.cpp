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
    ListNode* reverse(ListNode* head, int k,int remcount) {
        if(k > remcount){
            return head;
        }
        ListNode* temp = head;
        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;
        
        int count = 0;
        while(currptr != NULL && count < k){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
            remcount--;
            cout<<remcount<<" ";
        }
        if(nextptr!=NULL){
            head->next = reverse(nextptr,k,remcount);
        }
        
        return prevptr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int remcount = 0;
        ListNode* currptr = head;
        while(currptr != NULL ){
            remcount++;
            currptr = currptr->next;
        }
        
        return reverse(head,k,remcount);
    }
};