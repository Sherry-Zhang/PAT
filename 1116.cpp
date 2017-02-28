#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int cNum;
    cin >> cNum;
    map<int, string> ranklist;
    int id;
    for (int i = 1; i <= cNum; ++i)
    {
        cin >> id;
        if (i == 1)
            ranklist[id] = "Mystery Award";
        else if (isPrime(i))
            ranklist[id] = "Minion";
        else
            ranklist[id] = "Chocolate";
    }
    int qNum, qId;
    cin >> qNum;
    int visit[10010] = {};
    for (int i = 0; i < qNum; ++i)
    {
        cin >> qId;
        if (ranklist.find(qId) != ranklist.end())
        {
            if (visit[qId])
                printf("%04d: Checked\n", qId);
            else
            {
                visit[qId] = 1;
                printf("%04d: %s\n", qId, ranklist[qId].c_str());
            }
        }
        else
            printf("%04d: Are you kidding?\n", qId);

    }
    return 0;
}
