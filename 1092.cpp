#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s_shop;
    string s_eva;
    int map[128] = {};  //hash;
    cin >> s_shop;
    cin >> s_eva;
    int len_eva = s_eva.size();
    int len_shop = s_shop.size();
    for (int i = 0; i < len_shop; ++i)
        map[s_shop[i]]++;      //标记哪些玻璃珠是店家有的，有几个
    int count = 0;             //表示缺的数量
    for (int i = 0; i < len_eva; ++i)
    {
        map[s_eva[i]]--;       //买走一个,个数减一
        if (map[s_eva[i]] < 0)
            count++;
    }
    if (count)
        cout << "No " << count;
    else
        cout << "Yes " << len_shop - len_eva;
    return 0;
}
