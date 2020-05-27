class mystack
{
private:
    int *stack;
    int *top;
    int size;
public:
    mystack(int len = 100);
    ~mystack() { delete[] stack; }
    bool isempty() const { return top == stack; }
    bool isfull() const { return top == stack + size; }
    bool push(int i);
    bool pop(int &i);
};

mystack::mystack(int len)
    :size{ len }, stack{ new int[len] }
{
    top = stack;
}

bool mystack::push(int i)
{
    if (isfull())
        return false;
    
    *top = i;
    ++top;
    return true;
}

bool mystack::pop(int &i)
{
    if (isempty())
        return false;

    --top;
    i = *top;
    return true;
}