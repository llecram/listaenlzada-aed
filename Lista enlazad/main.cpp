#include "nodo.cpp"
int main() {
    lista<int> l1;
    l1.add(5);
    l1.add(7);
    l1.add(8);
    l1.add(9);
    l1.print();
    cout<<endl;
    l1.out(8);
    l1.print();
  return 0;
}
