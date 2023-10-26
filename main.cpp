#include<list.h>
using namespace std;
using namespace my;
int main()
{
    Mylist<int> a;
    a.push_front(4);
    a.push_front(4);
    a.push_front(4);
    a.push_front(4);
    a.push_back(10);
    a.pop_front();
    cout << a;
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