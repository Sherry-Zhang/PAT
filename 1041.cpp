#include <iostream>
#include <vector>
using namespace std;

int visit[10010] = {};
void check(vector<int>& num,int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (visit[num[i]] == 1)
        {
            cout << num[i];
            return;
        }
    }
    cout << "None";
}
int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
        visit[num[i]]++;
    }
    check(num, n);
    return 0;
}
