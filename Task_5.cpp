#include <iostream>
using namespace std;
void swap1(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void swap2(int **pp1, int **pp2) {
    int temp = **pp1;
    **pp1 = **pp2;
    **pp2 = temp;
}
int main() {
    int a = 5, b = 10;
    int *pa = &a;
    int *pb = &b;
    int **ppa = &pa;
    int **ppb = &pb;
    cout << "Original values: a = " << a << ", b = " << b << endl;
    //Swap using single pointers (passing addresses)
    swap1(&a, &b);
    cout << "After swap With Single Pointer: a = " << a << ", b = " << b << endl;
    //Swap using double pointers (passing ppa and ppb)
    swap2(ppa, ppb);
    cout << "After swap With Double Pointer:  a = " << a << ", b = " << b << endl;
    return 0;
}