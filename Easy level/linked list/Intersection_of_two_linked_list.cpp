// #include <bits/stdc++.h>
// using namespace std;

// Node *getIntersectionNode(Node *headA, Node *headB)
// {
//     if (headA == NULL || headB == NULL)
//         return NULL;
//     stack<Node *> s1, s2;
//     while (headA)
//     {
//         s1.push(headA);
//         headA = headA->next;
//     }
//     while (headB)
//     {
//         s2.push(headB);
//         headB = headB->next;
//     }
//     Node *p = NULL;
//     while (!s1.empty() && !s2.empty() && s1.top() == s2.top())
//     {
//         p = s1.top();
//         s2.pop();
//         s1.pop();
//     }
//     return p;
// }
