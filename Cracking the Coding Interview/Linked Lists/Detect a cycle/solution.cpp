/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <unordered_set>

bool has_cycle(Node* head) 
{
    unordered_set<Node*> visited;
    while (head != nullptr) 
    {
        if (visited.find(head) == visited.end() ) 
        {
            visited.insert(head);
            head = head->next;
        }
        else 
        {
            return true;
        }
    }
    return false;
}
