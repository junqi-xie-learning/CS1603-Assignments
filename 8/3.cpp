struct Node
{
    int order, coeff; // 次数 和 系数
    Node *nxt;        // 指向后一项的指针
};

Node *adjoin_term(Node *head, Node *rest)
{
    if (head->coeff == 0)
        return rest;

    head->nxt = nullptr;
    if (rest->coeff == 0)
        delete rest;
    else
        head->nxt = rest;
    return head;
}

Node *add_poly(Node *a, Node *b)
{
    if (!a && !b)
        return new Node{ 0, 0 };
    else if (!a)
        return b;
    else if (!b)
        return a;

    if (a->order == b->order)
    {
        a->coeff += b->coeff;
        return adjoin_term(a, add_poly(a->nxt, b->nxt));
    }
    else
    {
        if (a->order < b->order)
        {
            Node *temp = a;
            a = b;
            b = temp;
        }
        return adjoin_term(a, add_poly(a->nxt, b));
    }
}