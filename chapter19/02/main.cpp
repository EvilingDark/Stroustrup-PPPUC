#include <iostream>
#include <vector>

using namespace std;

template <class T, class U>
T sum(const vector<T>& vt_sum, const vector<U>& vu)
{
    T sum = NULL;
    int length;
    if (vt_sum.size() >= vu.size())
        length = vu.size();
    else
        length = vt_sum.size();
    for (int i = 0; i < length; ++i)
        sum += vt_sum[i] * vu[i];
    return sum;
}

int main()
{
    vector<int> vt0 { 5, 3, 6, 8, 6, 9, 2 };
    vector<double> vt1 { 7, 3, 4, 5, 1, 2, 6, 4, 7, 81, 95 };
    cout << sum(vt0, vt1);
    return 0;
}
