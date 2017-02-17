class Heap
{
  private:
    int *A;
    int passed;

  public:
    int heapSize;
    Heap(int size);
    Heap(int *I, int size);
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