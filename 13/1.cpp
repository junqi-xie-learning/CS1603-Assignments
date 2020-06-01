template <class T>
class mystack
{
private:
    T *stack;
    T *top;
    int size;

    bool isFull() const { return top == stack + size; }
public:
    mystack(int len = 100);
    ~mystack() { delete[] stack; }
    bool isEmpty() const { return top == stack; }
    void push(T t);
    T pop();
};

template <class T>
mystack<T>::mystack(int len)
    :size{ len }, stack{ new T[len] }
{
    top = stack;
}

template <class T>
void mystack<T>::push(T t)
{
    if (isFull())
    {
        T *new_stack = new T[2 * size];
        for (int i = 0; i < size; ++i)
            new_stack[i] = stack[i];

        delete[] stack;
        stack = new_stack;
        top = stack + size;
        size *= 2;
    }
    
    *top = t;
    ++top;
}

template <class T>
T mystack<T>::pop()
{
    if (isEmpty())
        return false;

    --top;
    return *top;
}