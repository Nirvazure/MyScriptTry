void InitStack(SeqStack *s)
{
    s->top = -1;
}

int Push(SeqStack *s, StackElemType x)
{
    if (s->top == STACK_SIZE - 1)
    {
        return FALSE;
    }
    s->top++;
    s->Elem[s->top] = x;
    return TRUE;
}

int Pop(SeqStack *s, SeqElemType *x)
{
    if (s->top == -1)
    {
        return FALSE;
    }
    else
    {
        *x = s->Elem[s->top];
        s->top--;
        return TRUE;
    }
}

int GetTop(SeqStack *s, SeqElemType *x)
{
    if (s->top == -1)
    {
        return FALSE
    }
    else
    {
        *x = s->Elem[s->top];
        return TRUE;
    }
}