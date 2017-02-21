#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
思路：实现一个将数字转换为科学技术法的转换函数。
要点：
    1.去除前导0
    2.纯小数和大于1的小数分开讨论
    3.有效数字较大时注意补0
*/
string trans(string str,int digitNum)
{
    int len = 0;    //10^len
    while (str != "" && str[0] == '0')          //去除前导0
        str.erase(str.begin());
    if (str != "" && str[0] == '.')    //纯小数
    {
        str.erase(str.begin());
        while (str != "" && str[0] == '0')          //去除前导0
        {
            str.erase(str.begin());
            --len;
        }
        if (str.empty())
            len = 0;
    }
    else if (str != "")   //整数+小数
    {
        auto index = str.find('.'); //index可以表示整数长度
        if (index == string::npos)     //纯整数
            len = str.size();
        else
        {
            len = index;
            str.erase(str.begin() + index);     //删掉小数点
        }
    }
    string out;
    int slen = str.size();   //当前的有效数字长度
    //判断是否需要补0
    if (slen < digitNum)
    {
        string zero(digitNum - slen, '0');
        out = "0." + str + zero;
    }
    else if (slen > digitNum)
    {
        out = "0." + str.substr(0, digitNum);
    }
    else
        out = "0." + str;
    stringstream sstr;
    sstr << out << "*10^" << len;
    sstr >> out;
    return out;
}
int main()
{
    int digitNum;     //有效数字位数
    string a, b;      //待转换和比较的两个数字
    cin >> digitNum >> a >> b;
    string atr = trans(a,digitNum);
    string btr = trans(b,digitNum);
    if (atr == btr)
        cout << "YES " << atr;
    else
        cout << "NO " << atr << ' ' << btr;
    return 0;
}
