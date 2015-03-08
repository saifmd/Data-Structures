#include <iostream>
#include "SLList.cpp"
using namespace std;

int main()
{
    SLList<int> q;
    const int x=10, y=20, z=50;
    q.Add(x).Add(y).Add(z);
    cout<<q<<endl;
    int a = q.Remove();
    cout<<q<<endl;
    SLList<int> st;
    st.Push(x).Push(y).Push(z);
    cout<<st<<endl;;
    int b = st.Pop();
    cout<<st<<endl;
    return 0;
}
