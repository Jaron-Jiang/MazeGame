template<class T>
class queue
{
    private:
    struct LNode
    {
        T data;
        LNode* next;
    };
    int length;
    LNode* f;
    LNode* r;
    public:
    queue()
    {
        length = 0;
        f = r = NULL;
    }
    T front()
    {
        return f->data;
    }
    T back()
    {
        return r->data;
    }
    void push(T val)
    {
        LNode* p = new LNode;
        p->data = val;
        p->next = NULL;
        length == 0 ? f = p : r->next = p;
        r = p;
        length++;
    }
    void pop()
    {
        LNode* p = f;
        f = f->next;
        delete p;
        --length;
    }
    bool empty()
    {
        return length == 0;
    }
    int size()
    {
        return length;
    }
};