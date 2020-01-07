#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>* vec = new vector<int>;
    //for(int i=0;i<9;++i)
    //{
    //    vec->at(i) = i;
    //}
    int res = vec.length;
    cout << res << endl;
    delete vec;
    return 0;
}    
