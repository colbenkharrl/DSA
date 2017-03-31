class MaxHeap {
private:
  int *A;
  int passed;

public:
  int heaplength;
  MaxHeap(int length);
  MaxHeap(int *I, int length);
  ~MaxHeap();
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

class MinHeap {
private:
  int *A;
  int passed;

public:
  int heaplength;
  MinHeap(int length);
  MinHeap(int *I, int length);
  ~MinHeap();
  void Heapify(int i);
  void BuildHeap();
  int Minimum();
  int ExtractMin();
  void Insert(int key);
  void DecreaseKey(int i, int key);
  int Parent(int i);
  int Left(int i);
  int Right(int i);
  void Print();
};