/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         ListNode* rm = node;
//         queue<ListNode*> q;
//         node = node->next;
//         while(node){
//             q.push(node);
//             node = node->next;
//         }
//         while(!q.empty()){
//             rm->val = q.front()->val;
//             q.pop();
//             if(!q.empty())
//             rm = rm->next;
//         }
//         rm->next = NULL;

//     }
// };

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
