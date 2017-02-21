#include <iostream>
#include <map>
using namespace std;
int main()
{
    int m, n;
    //cin >> m >> n;
    scanf("%d%d", &m, &n);
    map<int, int> count;
    int color;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            //cin >> color;
            scanf("%d", &color);
            auto it = count.find(color);
            if (it != count.end())
                (it->second)++;
            else
                count.insert({ color, 1 });
        }
    }
    map<int, int>::iterator mit = count.begin();
    for (auto it = count.begin(); it != count.end(); ++it)
    {
        if (it->second > mit->second)
            mit = it;
    }
    printf("%d", mit->first);
    //cout << mit->first;
    return 0;
}
