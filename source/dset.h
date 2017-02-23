class DisjointSet
{
	private:
		int *A;
		int passed;

	public:
		int ulength;
		DisjointSet(int length);
		~DisjointSet();
		void MakeSet(int x);
		void Link(int x, int y);
		int FindSet(int x);
		void Union(int x, int y);
		void PrintSet();
};