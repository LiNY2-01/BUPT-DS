#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *next;
};
node *add(node *now, int val) {
    node *nxt = new node;
    nxt->next = NULL;
    now->next = nxt;
    nxt->val = val;
    return nxt;
}
 
int main() {
    int n, k;
    cin >> n >> k;
    node *head = new node;
    head->val = 1;
    head->next = head;
    node *now = head;
    for (int i = 2; i <= n; i++) {
        node *nxt = new node;
        nxt->next = NULL;
        now->next = nxt;
    nxt->val = i;
    now=nxt;
    }
    now->next = head;
    now = head;
    // cout<<now->val<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < k; j++) now = now->next;
        printf("%d ", now->val);
        node *temp = now->next;
        now->next = temp->next;
        now->val=temp->val;
        free(temp);
        //1now = now->next;
    }
}