#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const int& a, const int& b)
{
    return a > b;
}
int main()
{
    int dayNum;
    cin >> dayNum;
    vector<int> mile(dayNum+1);
    int eNum = 0;
    //题目的坑：有E天超过E公里，而不是第E天超过E公里。因此需要先存储所有天数，然后从大到小排序后再判断
    for (int i = 1; i <= dayNum; ++i)
        cin >> mile[i];
    sort(mile.begin()+1, mile.end(),cmp);
    for (int i = 1; i <= dayNum; ++i)
    {
        if (mile[i] > i)
            eNum++;
        else
            break;
    }
    cout << eNum << endl;
    return 0;
}
