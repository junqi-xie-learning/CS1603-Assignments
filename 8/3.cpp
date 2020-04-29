struct Node
{
    int order, coeff;
    Node *nxt;
};

Node *adjoin_term(Node *head, Node *rest)
{
    if (head->coeff == 0)
        return rest;

    if (!rest)
        head->nxt = nullptr;
    else if (rest->coeff == 0)
    {
        delete rest; // Node{ 0, 0 }
        head->nxt = nullptr;
    }
    else
        head->nxt = adjoin_term(rest, rest->nxt);
    return head;
}

Node *add_poly(Node *a, Node *b)
{
    if (!a && !b)
        return new Node{ 0, 0 };
    else if (!a)
        return adjoin_term(b, b->nxt);
    else if (!b)
        return adjoin_term(a, a->nxt);

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