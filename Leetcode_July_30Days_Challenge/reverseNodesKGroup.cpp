//O(n)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr= head, *prevFirst= NULL;
        bool firstPass = true;
        int total =0;
        for(ListNode *sum= head;sum!=NULL;sum=sum->next)
            total++;
        while(curr!=NULL){
            ListNode *first = curr, *prev= NULL;
            int count=0;
            if(total/k > 0){
                while(curr!=NULL && count<k){
                    ListNode *temp= curr->next;
                    curr->next= prev;
                    prev= curr;
                    curr= temp;
                    count++;
                    total--;
                }
                if(firstPass){
                    head = prev;
                    firstPass = false;
                }
                else{
                    prevFirst->next = prev;
                }
                prevFirst = first;
            }
            else
            {
                if(!firstPass)
                {
                    prevFirst -> next = first;
                }
                break;
            }
        }
        return head;
    }
};