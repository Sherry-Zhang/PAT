#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int null = -1;
struct node{
    int left;      //左节点地址
    int right;     //右节点地址
};

bool IsCBT(vector<node> &t,int root, int& r)
{
    queue<int> q;
    q.push(root);
    int len = t.size();
    int count = 0;
    while (q.front() != null)
    {
        r = q.front();
        q.pop();
        ++count;
        q.push(t[r].left);
        q.push(t[r].right);
    }
    if (count != len)
        return false;
    else
        return true;
}
int main()
{
    int nodeNum;
    cin >> nodeNum;
    vector<node> t(nodeNum);
    vector<int> visit(nodeNum);
    string left, right;
    for (int i = 0; i < nodeNum; ++i)
    {
        cin >> left >> right;
        if (left != "-")
        {
            //int l = left[0] - '0';               //出错在这里，数字可能超过双数，因此需要写atoi的转换
            int l;
            sscanf(left.c_str(), "%d", &l);
            visit[l] = 1;
            t[i].left = l;
        }
        else
            t[i].left = null;
        if (right != "-")
        {
            //int r = right[0] - '0';
            int r;
            sscanf(right.c_str(), "%d", &r);
            visit[r] = 1;
            t[i].right = r;
        }
        else
            t[i].right = null;

    }
    int root;
    for (int i = 0; i < nodeNum; ++i)
    {
        if (visit[i] == 0)
        {
            root = i;
            break;
        }
    }
    //层序遍历
    int r = 0;  //最后的节点
    if (IsCBT(t,root,r))
        cout << "YES " << r << endl;
    else
        cout << "NO " << root << endl;
    return 0;
}
