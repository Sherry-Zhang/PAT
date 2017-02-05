 ///
 /// @file    1120.cpp
 /// @author  zhangshu
 /// @date    2017-01-23 09:50:39
 ///
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> friendID(n);
    string tmp;
    for(int i=0; i<n; ++i)
    {    
        cin >> tmp;
        int len = tmp.size();
        for(int j=0; j<len; ++j)
            friendID[i] += tmp[j]-'0';
    }
    sort(friendID.begin(),friendID.end());
    vector<int> out;
    out.push_back(friendID[0]);
    for(int i=1;i<n;++i)
    {
        if(friendID[i] != friendID[i-1])
            out.push_back(friendID[i]);
    }
    int num = out.size();
    cout << num << endl;
    cout << out[0];
    for(int i=1;i<num;++i)
        cout << ' ' <<  out[i];
    return 0;
}


