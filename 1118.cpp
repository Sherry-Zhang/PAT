#include <iostream>
#include <vector>
#include <set>
using namespace std;
int pre[10001] = {};     //并查集
int set_find(int x)
{
    int a = x;
    while (x != pre[x])
        x = pre[x];
    while (a != pre[a])
    {
        int tmp = a;
        a = pre[a];
        pre[tmp] = x;
    }
    return x;
}
void set_union(int a, int b)
{
    int ra = set_find(a);
    int rb = set_find(b);
    if (ra != rb)
        pre[ra] = rb;
}

int main()
{
    int picNum;
    cin >> picNum;
    vector<int> s(picNum);
    int count = 0;
    int visit[10001] = {};
    for (int i = 0; i < picNum; ++i)
    {
        int birdNum, ba, bb;
        cin >> birdNum >> ba;
        s[i] = ba;
        if (!visit[ba])
        {
            ++count;
            visit[ba] = 1;
            pre[ba] = ba;
        }
        for (int i = 1; i < birdNum; ++i)
        {
            cin >> bb;
            if (!visit[bb])
            {
                ++count;
                visit[bb] = 1;
                pre[bb] = bb;
            }
            set_union(ba, bb);
            ba = bb;
        }
    }
    set<int> pic;
    for (int i = 0; i < picNum; ++i)
    {
        pic.insert(set_find(s[i]));
    }
    cout << pic.size() << ' ' << count << endl;
    int qNum, qa, qb;
    cin >> qNum;
    for (int i = 0; i < qNum; ++i)
    {
        cin >> qa >> qb;
        if (set_find(qa) != set_find(qb))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}
