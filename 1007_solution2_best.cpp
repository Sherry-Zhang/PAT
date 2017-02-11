#include <iostream>
#include <vector>
using namespace std;
/*
一个新思路的动态规划：
dp[i]表示以第i个元素结尾的最大子列和
时间复杂度可以降为O(N)
*/
int main()
{
    int k;
    cin >> k;
    vector<int> seq(k);
    bool isNegative = true;
    for (int i = 0; i < k; ++i)
    {
        cin >> seq[i];
        if (seq[i] >= 0)
            isNegative = false;
    }
    if (isNegative)     //如果是全负的情况
    {
        cout << 0 << " " << seq[0] << " " << seq[k - 1];
        return 0;
    }
    //find maxinum subsequence sum
    vector <int> dp(k);     //表示以第k个元素结尾的最大子列和
    vector <int> start(k);  //表示以第k个元素结尾的最大子列的起始下标
    dp[0] = seq[0];     //起始情况
    for (int i = 1; i < k; ++i)
    {
        if (dp[i - 1] + seq[i] > seq[i])
        {
            dp[i] = dp[i - 1] + seq[i];
            start[i] = start[i - 1];
        }
        else
        {
            dp[i] = seq[i];
            start[i] = i;
        }
    }
    int mi = 0;
    for (int i = 1; i < k; ++i)
    {
        if (dp[mi] < dp[i])
            mi = i;
    }
    cout << dp[mi] << ' ' << seq[start[mi]] << ' ' << seq[mi];
    return 0;
}
