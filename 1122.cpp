#include <iostream>
#include <vector>
using namespace std;
void check(vector<vector <int> > g, vector<int> c)
{
    if (c.back() != c.front())
    {
        cout << "NO" << endl;
        return;
    }
    int v = c.front();
    int visit[202] = {};
    for (auto it = c.begin()+1; it != c.end(); ++it)
    {
        if (visit[*it])               //检查是否是简单路径
        {
            cout << "NO" << endl;
            return;
        }
        visit[*it] = 1;
        bool isHami = false;
        for (auto i = g[v].begin(); i != g[v].end(); ++i)
        {
            if (*it == *i)
            {
                isHami = true;
                break;
            }
        }
        if (isHami == false)          //这里是检查是否存在路径
        {
            cout << "NO" << endl;
            return;
        }
        else
            v = *it;
    }
    cout << "YES" << endl;
}
int main()
{
    int vNum, eNum;
    cin >> vNum >> eNum;
    vector<vector<int> > graph(vNum+1);
    int v1, v2;
    for (int i = 0; i < eNum; ++i)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);    //无向图
        graph[v2].push_back(v1);
    }
    int qNum, cNum;   //查询的总数, 查询中输入的环的节点数
    cin >> qNum;
    for (int i = 0; i < qNum; ++i)
    {
        cin >> cNum;
        vector<int> circle(cNum);
        for (int i = 0; i < cNum; ++i)
            cin >> circle[i];
        if (cNum != vNum + 1)
            cout << "NO" << endl;
        else
            check(graph, circle);
    }
    return 0;
}
