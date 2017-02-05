 ///
 /// @file    1121.cpp
 /// @author  zhangshu
 /// @date    2017-01-23 10:40:12
 ///
 #include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 using namespace std;


 //思路：主要是数据的查找操作，一开始并没有想用hash的方式存储，但是报了超时错误，于是改成这个版本了。
 int main()
 {
     int coupleNum;
     cin >> coupleNum;
     vector<int> couple(100000,-1);
     vector<int> visit(100000);
     int a, b;
     for (int i = 0; i < coupleNum; ++i)
     {
         cin >> a >> b;
         couple[a] = b;      //hash
         couple[b] = a;
     }
     int guestNum;
     cin >> guestNum;
     vector <int> g(guestNum);
     for (int i = 0; i < guestNum; ++i)
     {
         cin >> g[i];
         int coupleId = couple[g[i]];
         if (coupleId != -1)
         {
             ++visit[g[i]];
             ++visit[coupleId];
         }
     }
     vector<int> DamnDog;
     for (int i = 0; i < guestNum; ++i)
     {
         if (visit[g[i]] != 2)           //伴侣两人均出席
             DamnDog.push_back(g[i]);
     }
     int num = DamnDog.size();
     sort(DamnDog.begin(), DamnDog.end());
     cout << num << endl;
     if (num)
         printf("%05d",DamnDog[0]);
     for (int i = 1; i < num; ++i)
         printf(" %05d", DamnDog[i]);
     return 0;
 }
