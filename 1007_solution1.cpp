#include <iostream>
#include <vector>
using namespace std;
//思路：
//1.暴力做法，找到所有的子列，求和，时间复杂度为 O[1*k+2*(k-1)+3*(k-2)+..+k*1]
//2.dp求所有的子列和，时间复杂度为o(n^2),现在实现思路2
/*
状态转移方程:dp[i][j] = dp[i - 1][j] + seq[j + i],
但是每次计算的都是前一个的，因此可以降为一维数组存储dp[i]
*/
int main()
{
    int k;
    cin >> k;
    vector<int> seq(k);
    int max = 0;
    int mstart = 0, mlen = 0;    //分别表示子列起始位置和子列长度
    bool isNegative = true;
    for (int i = 0; i < k; ++i)
    {
        cin >> seq[i];
        if (seq[i] >= max)
        {
            max = seq[i];
            mstart = i;
            mlen = 1;
            isNegative = false;
        }
    }
    if (isNegative)     //如果是全负的情况
    {
        cout << max << " " << seq[0] << " " << seq[k - 1];
        return 0;
    }
    //find maxinum subsequence sum
    vector<int> dp(k);
    dp = seq;    //第一行是元素为1的子列，子列和情况和序列本身一致。
    for (int i = 1; i < k; ++i)      //元素数为i+1的子列
    {
        for (int j = 0; j < k - i; ++j)
        {
            dp[j] += seq[i + j];       //起始位置为j,长度为i+1的子列的子列和
            if (max < dp[j] || max == dp[j] && j < mstart)
            {
                mstart = j;
                mlen = i + 1;
                max = dp[j];
            }
        }
    }
    cout << max << " " << seq[mstart] << " " << seq[mstart + mlen];
    return 0;
}
