class Queue {
private:
  int *A;
  int passed;

public:
  int head;
  int tail;
  int size;
  int empty;
  Queue(int s);
  Queue(int *I, int t, int h, int s);
  ~Queue();
  void Enqueue(int x);
  int Dequeue();
  void Print();
};