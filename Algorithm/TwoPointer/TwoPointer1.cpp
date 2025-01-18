#include <iostream>
#include <fstream>

using namespace std;

int n, m, k = 0;
int N[101], M[101];
int re[201];

void input()
{
    fstream f("TwoPointer11.inp");
    f >> n >> m;
    // for (int &i : N) // nếu mảng kích thước của mảng fit với số phần tử thì có thể dùng cái này
    for (int i = 0; i < n; i++)
    {
        f >>  N[i];
    }
    for (int i = 0; i < m; i++)
    {
        f >>  M[i];
    }
}

void output()
{
    cout << n << " " << m << endl;
    for(int i = 0; i < n; ++i) {
        cout << N[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < m; ++i) {
        cout << M[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < k; ++i) {
        cout << re[i] << " ";
    }
}

void mergeArray()
{
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(N[i] <= M[j]) {
            re[k++] = N[i++];
        }
        else re[k++] = M[j++];
    }
    if(i == n) 
        for(;j < m; ++j) 
            re[k++] = M[j];
    else
        for(;i < n; ++i)
            re[k++] = N[i];
    
}
int main()
{
    input();
    mergeArray();
    output();
    return 0;
}