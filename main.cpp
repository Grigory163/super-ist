#include<list.h>
using namespace std;
using namespace my;
int main()
{
    Mylist<int> a;
    a.push_front(1);
    a.push_front(2);
    a.push_front(3);
    a.push_front(4);
    a.push_back(10);
    a.push_front(4);
    a.push_front(4);
    a.push_front(4);
    Mylist<int> b;
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);
    a.delete_node(3);
    cout << a;
    // a.destroy(3);
    // cout << a << endl;
    // Mylist<int> b;
    // b.push_back(5); 
    // b.push_back(5); 
    // b.push_back(5); 
    // b.push_back(5); 
    // b.push_back(5); 
    // b.pop_back(); 
    // cout << b;
    return 0;
}