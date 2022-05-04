#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    void Insert(Node **head, Node **tail, int x)
    {
        Node *p = NULL;
        p = new Node;
        p->data = x;
        p->next = NULL;
        if (*head == NULL)
            *head = *tail = p;
        else
        {
            (*tail)->next = p;
            *tail = p;
        }
    }
    void display(Node *head)
    {
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
};
int getDecimalValue(Node *head)
{
    int c = 0;
    Node *t = head;
    while (t)
    {
        c++;
        t = t->next;
    }
    c--;
    int ans = 0;
    while (head)
    {
        ans += head->data * pow(2, c--);
        head = head->next;
    }
    return ans;
}
int main()
{
    Node *head = NULL, *tail = NULL;
    Node list;
    int x;
    do
    {
        cout << "Enter Value: ";
        cin >> x;
        list.Insert(&head, &tail, x);
        cout << "Want to insert more?\n1: yes\n2: no\n";
        cin >> x;
    } while (x == 1);
    list.display(head);
    int ans = getDecimalValue(head);
    cout<<"\n"<<ans<<endl;
    return 0;
}