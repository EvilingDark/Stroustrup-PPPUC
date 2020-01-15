#include <std_lib_facilities.h>

template <class T>
void sum_of_vectors(vector<T>& vt_sum, const vector<T>& vt_plus)
{
    int length;
    if (vt_sum.size() >= vt_plus.size())
        length = vt_plus.size();
    else
        length = vt_sum.size();

    for (int i = 0; i < length; ++i)
        vt_sum[i] += vt_plus[i];
}

template <class T>
void print_vector(const vector<T>& vt)
{
    for (auto p : vt)
        cout << p << " ";
    cout << endl;
}

int main()
{
    vector<int> vt0 { 5, 3, 6, 8, 6, 9, 2 };
    vector<int> vt1 { 7, 3, 4, 5, 1, 2, 6, 4, 7, 81, 95 };
    print_vector(vt0);
    print_vector(vt1);
    sum_of_vectors(vt0, vt1);
    print_vector(vt0);
    cout << "Hello World!" << endl;
    return 0;
}
