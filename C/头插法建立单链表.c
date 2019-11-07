//头插法建立单链表

void create_from_head(LinkList L)
{
    Node *S;
    char c;
    int flag = 1;

    //flag初值为1，当输入$时，flag=0建表结束
    while (flag)
    {
        c = getchar();
        if (c != '$')
        {
            S = (Node *)malloc(sizeof(Node));
            S->data = c;
            S->next = L->next;
            L->next = S;
        }
        else
        {
            flag = 0;
        }
    }
}

//尾插法建立单链表
void create_from_tail(LinkList L)
{
    Node *r, *s; //r为尾元地址，s为新节点地址
    int flag = 1;
    r = L; //指针动态指向表尾，以便作为尾插插入，初始值指向头节点
    while (flag)
    {
        c = getchar();
        if (c != '$')
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        }
        else
        {
            flag = 0;
            r->next = NULL;
        }
    }
}

//在单链表中查找第i个节点,时间复杂度O(n)
Node *Get(LinkList L, int i)
{
    int j = 0;
    Node *P;
    if (i <= 0)
    {
        return NULL;
    }
    else
    {
        P = L;
        while ((P->next != NULL) && (j < i))
        {
            P = P->next;
            j++;
        }
        if (i == j)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
}

//单链表插入操作
void InsList(LinkList L, int i, ElemType e)
{
    Node *pre, *s;
    int k;
    if (i <= 0)
    {
        return ERROR;
    }
    else
    {
        pre = L;
        k = 0; //从头开始,找到插入位置
        while (pre != NULL && k < i - 1)
        {
            pre = pre->next;
            k++;
        }
        if (!pre)
        {
            return ERROR; //插入位置不合理
        }
        else
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = e;
            s->next = pre->next;
            pre->next = s;
            return OK;
        }
    }
}

//单链表删除操作
int DelList(LinkList L, int i, ElemType *e)
{
    Node *pre, *r;
    int k;
    pre = L;
    k = 0;
    while ((pre->next != NULL) && (k < i - 1))
    {
        pre = pre->next;
        k++;
    }
    if (!(pre->next))
    {
        return ERROR; //删除位置不合法
    }
    r = pre->next;
    pre->next = r->next;
    *e = r->data; //e将删除的值带出
    free(r);
    return OK;
}

//求单链表的长度
int ListLength(LinkList L){
    int j=0;
    Node *p;
    p=L->next;
    while(p!=NULL){
        p=pre->next;
        j++;
    }
    return j;
}

//单链表L中查找值为key的结点，时间复杂度O(n)
Node *Locate(LinkList L,ElemType key){
    Node *p;
    p=L->next;
    while(p!=NULL){
        if(p->data!=key){
            p=pre->next;
        }else{
            break;
        }
    }
    return p;
}