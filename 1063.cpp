#include <iostream>
#include <set>
using namespace std;
int main()
{
    int setNum, num;
    cin >> setNum;
    set<int> sets[50];
    for (int i = 0; i < setNum; ++i)    //输入全部的set
    {
        cin >> num;
        int tmp;
        for (int j = 0; j < num; ++j)
        {
            cin >> tmp;
            sets[i].insert(tmp);    //重复元素会被自动忽略
        }
    }
    int qNum;
    cin >> qNum;
    int p1, p2;
    for (int i = 0; i < qNum; ++i)
    {
        cin >> p1 >> p2;
        --p1;
        --p2;
        int ncNum = 0;
        int ntNum = sets[p2].size();
        for (set<int>::iterator it = sets[p1].begin(); it != sets[p1].end(); ++it)
        {
            if (sets[p2].find(*it) != sets[p2].end())   //在另一个集合中找到相同的元素，交集元素数加1
               ++ncNum;
            else                            //否则并集元素数加1
               ++ntNum;
        }
        double similarity = ncNum *1.0 / ntNum;
        printf("%.1f%%\n", similarity * 100);
    }
    return 0;
}
