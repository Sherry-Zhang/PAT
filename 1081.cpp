#include <iostream>
#include <string>
#include <vector>
using namespace std;
class rationalNum{
public:
    int numerator = 0; //分子
    int denominator = 0;    //分母
};
int gcd(int a, int b)     //a > b
{
    int tmp;
    while (b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
rationalNum add(rationalNum& a, rationalNum& b)
{
    rationalNum ans;
    ans.denominator = a.denominator * b.denominator;
    ans.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    int c;
    if (ans.denominator > ans.numerator)
        c = gcd(ans.denominator, ans.numerator);
    else
        c = gcd(ans.numerator, ans.denominator);
    ans.numerator /= c;
    ans.denominator /= c;
    return ans;
}
void print(rationalNum num)
{
    int integer = num.numerator / num.denominator;
    num.numerator %= num.denominator;
    if (integer && num.numerator)
        cout << integer << ' ' << num.numerator << '/' << num.denominator << endl;
    else if (integer)
        cout << integer << endl;
    else if (num.numerator)
        cout << num.numerator << '/' << num.denominator << endl;
    else
        cout << 0 << endl;
}
int main()
{
    int n;
    cin >> n;
    string input;
    vector<rationalNum> num;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        rationalNum tmp;
        bool fu = false;      //分子的符号
        if (input[0] == '-')
        {
            fu = true;
            input.erase(input.begin());
        }
        int len = input.size();
        int j;
        for (j = 0; input[j] != '/'; ++j)
            tmp.numerator = tmp.numerator * 10 + input[j] - '0';
        if (fu)
            tmp.numerator = 0 - tmp.numerator;
        ++j;
        while (j < len)
            tmp.denominator = tmp.denominator * 10 + input[j++] - '0';
        num.push_back(tmp);
    }
    rationalNum sum = add(num[0], num[1]);
    for (int i = 2; i < n; ++i)
        sum = add(sum, num[i]);
    print(sum);
    return 0;
}
