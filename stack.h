template<class T>
class stack
{
    private:
    struct LNode
    {
        T data;
        LNode* ahead;
    };
    int length;
    LNode* t;
    public:
    stack()
    {
        length = 0;
        t = NULL;
    }
    int size()
    {
        return length;
    }
    bool empty()
    {
        return length == 0 ? true : false;
    }
    T top()
    {
        return t->data;
    }
    void pop()
    {
        LNode* p = t;
        t = t->ahead;
        length--;
        delete p;
    }
    void push(T val)
    {
        LNode* p = new LNode;
        p->ahead = t;
        p->data = val;
        t == NULL ? p->ahead = NULL : p->ahead = t;
        t = p;
        length++;
    }
};
