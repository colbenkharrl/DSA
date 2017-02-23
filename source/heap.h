class Heap
{
  private:
    int *A;
    int passed;

  public:
    int heaplength;
    Heap(int length);
    Heap(int *I, int length);
    ~Heap();
    void Heapify(int i);
    void BuildHeap();
    int Maximum();
    int ExtractMax();
    void Insert(int key);
    void IncreaseKey(int i, int key);
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void Print();
};