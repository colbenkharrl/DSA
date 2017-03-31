class Stack
{
  private:
    int *A;
    int passed;

  public:
    int top;
    int size;
    Stack(int s);
    Stack(int *I, int t, int s);
    ~Stack();
    int StackEmpty();
    void Push(int x);
    int Pop();
    void Print();
};