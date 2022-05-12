// Przykład 1
void push_front(List* L, T w)
{
    Node* p = malloc(sizeof(Node));
    p->value = w;
    p->next = NULL;
    p->prev = NULL;
    if (L->first == NULL)
        L->first = L-.last = p;
    else
    {
        p->next = L->first;
        L->first = p;
    }
}

// Przykład 2
void push_back(List* L, T w)
{
    Node* p = malloc(sizeof(Node));
    p->value = w;
    p->next = NULL;
    p->prev = NULL;

    if (L->first == NULL)
        L->first = L->last = p;
    else
    {
        L->last->next = p;
        p->prev = L-last;
        L->last = p;
    }
}

// Przykład 3
void pop_1(List* L, T w)
{
    if (w == L->first->value)
        L->first = L->first->next;
    else
    {
        Node* y = L->first;
        while (y->next->value != w)
            y = y->next;
        y->next = y->next->next;
        y->next->prev = y;
    }
}

// Przykład 4
void pop_back2(List* L)
{
    if (L->first == L->last)
    {
        free(L->first);
        L->first = L->last = NULL;
    }
    else
    {
        Node* p = L->last;
        L->last = p->prev;
        L->last->next = NULL;
        free(p);
    }
}