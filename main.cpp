#include<list.h>
using namespace std;
using namespace my;
int main()
{
    Mylist<int> source;
    Mylist<int> auxiliary;
    Mylist<int> target;
    source.push_front(1);
    source.push_front(2);
    source.push_front(3);
    source.push_front(4);
    source.push_front(5);
    cout << source << endl;
    // cout << auxiliary << endl;
    // cout << target << endl;
    try
    {
        hanoi(source.getsize() ,source, target, auxiliary);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cout << source << endl;
    cout << auxiliary << endl;
    cout << target << endl;
    
    return 0;
}