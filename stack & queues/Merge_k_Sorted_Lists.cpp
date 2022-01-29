class Solution {
public:
    
    struct compare{
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }   
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , compare> pq;
        ListNode* res = new ListNode(-1);
        for(auto l:lists){
            if(l) pq.push(l);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            itr->next = temp;   
            if(temp!=NULL && temp->next!=NULL)
                pq.push(temp->next);
            itr = itr->next;
            
        }
        return dummy->next;
    }
};
