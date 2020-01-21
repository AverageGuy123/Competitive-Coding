#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct LinkNode{
    // remember this
    int key;
    LinkNode*prev;
    LinkNode*next;
    LinkNode(int x) : key(x), prev(NULL), next(NULL) {}
};


LinkNode* circular_delete(int n, LinkNode*head){
    LinkNode*curr_node=head, *next_node=NULL;
    // note that n==2 might fuck up, so break at n==2
    while(n>2){
        next_node=curr_node->next->next;
        curr_node->next->prev=NULL; curr_node->next->next=NULL;
        curr_node->next=next_node; next_node->prev=curr_node; 
        n--; curr_node=next_node;
    }
    curr_node->prev=NULL; curr_node->next=NULL;
    return curr_node;
}

int main(){
    int n, i, val;
    cin >> n;
    struct LinkNode*head=NULL, *curr_node=NULL, *prev_node=NULL;
    // create a circular linked list
    for(i=0; i<n; i++){
        cin >> val;
        curr_node=new LinkNode(val);
        curr_node->prev=prev_node; 
        if(prev_node!=NULL) prev_node->next=curr_node;
        else head=curr_node;
        prev_node=curr_node;
    }
    curr_node->next=head; head->prev=curr_node;
    // delete elements in circular order, total running time is O(nlgn)
    curr_node=circular_delete(n, head);
    cout << curr_node->key << endl;
    return 0;
}