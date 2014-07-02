#define ARRAY_MAX 100
using namespace std;

class bTreeClass {
  
 public:
  // constructors and destructor
  bTreeClass();
  ~bTreeClass();
  
  bool insert(int element, bool& success);
  bool deleteNode(int& n);
  void displayLevel(int lvl);
  bool isEmpty() const;
  void inorder();
  void preorder();
  void postorder();
  int HeightOfTree() const;
  int NumberOfElements() const;
  
 private:
  int arr[100];
  int height;
  int numElements;
  void inorder(int x);
  void preorder(int x);
  void postorder(int x);
};

