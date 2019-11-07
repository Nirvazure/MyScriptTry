时间复杂度需要遍历链表找到表尾，故而O(n)

LinkList merge(LinkList A, LinkList B)
{
    Node *p, *q;
    p = A;
    q = B;
    while (p->next != A)
    {
        p = p->next; //找到A表位，P指向该位置
    }
    q->next = A;
    p->next = B->next; //没看懂
    free(B);
    return (A);
}