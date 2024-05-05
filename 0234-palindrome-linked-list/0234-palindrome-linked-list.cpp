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
    ListNode* reverse(ListNode* head)
    {
          ListNode* prev=NULL;
         while(head!=NULL)
         {
             ListNode*store = head->next;
             head->next=prev;
             prev=head;
             head=store;
         }
         return prev;
    }
    bool isPalindrome(ListNode* head) {
          ListNode* fast=head;
          ListNode* slow=head;
          if(head==NULL || head->next==NULL)
          {
            return true;
          }
          while(fast!=NULL && fast->next != nullptr)
          {
              fast=fast->next->next;
              slow=slow->next;
          }
          ListNode* rev=reverse(slow);
          while(rev!=NULL)
          {
               if(head->val!=rev->val)
               {
                return false;
               }
               head=head->next;
               rev=rev->next;

          }
          return true;
        
    }
};