//Fuyuan Geng
//heap.h
using namespace std;

class heap
{
 private:
  
  int x;
  int capacity;
  //int* arr;
  int size;
  int value;
  int curSize;
  
  void swap(int& x, int &y);
  void percolateDown(int hole);
  void resize();
  int* arr;
  
  
 public:
  explicit heap(int size);//con
  heap(const heap &other);//copy
  ~heap();//delete
  heap& operator=(const heap &rhs);//operator
  
  void insert(int val);
  int remove();
  //void remove();
  void flush(int value);
  
  //void display();
  bool isEmpty() ;
  int getSize();
  
};
