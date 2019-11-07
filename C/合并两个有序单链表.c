LinkList merge(LinkList A, LinkList B)
{
    Node *p, *q;
    LinkList C;
    p = A->next;
    q = B->next;
    C = A;          //在A的基础上加上B
    C->next = NULL; //置C为空表
    r = C;          //C的工作指针
    while (A != NULL && B != NULL)
    {
        if (A->data < B->data)
        {
            r->next = A;
            r = A;
            A = A->next;
        }
        else
        {
            r->next = B;
            r = B;
            B = B->next;
        }
    }
    if (A)
    {
        r->next = A; //如果没弄完
    }
    else
    {
        r->next = B;
    }
    free(B);
    return (C); //感觉这里A也需要return
}