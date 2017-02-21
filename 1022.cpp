#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int n;      //the number of books
    cin >> n;
    map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPublisher, mpPublishYear;
    int id;
    string title, author, keys, publisher, publishYear;
    for (int i = 0; i < n; ++i)
    {
        cin >> id;
        getchar();  //读掉换行符
        getline(cin, title);
        mpTitle[title].insert(id);
        getline(cin, author);
        mpAuthor[author].insert(id);
        getline(cin, keys); //需要做一下字符串切割
        //c++对string的切割
        stringstream s;
        s << keys;
        string key;
        while (s >> key)
            mpKey[key].insert(id);
        //end
        getline(cin, publisher);
        mpPublisher[publisher].insert(id);
        getline(cin, publishYear);
        mpPublishYear[publishYear].insert(id);
    }
    int queryNum;
    cin >> queryNum;
    getchar();
    int typeId;
    string queryKey;
    set<int> ans;
    for (int i = 0; i < queryNum; ++i)
    {
        getline(cin, queryKey);
        typeId = queryKey[0]-'0';
        queryKey = queryKey.substr(3);
        switch (typeId)
        {
        case 1:
            ans = mpTitle[queryKey];
            break;
        case 2:
            ans = mpAuthor[queryKey];
            break;
        case 3:
            ans = mpKey[queryKey];
            break;
        case 4:
            ans = mpPublisher[queryKey];
            break;
        case 5:
            ans = mpPublishYear[queryKey];
            break;
        default:
            break;
        }
        cout << typeId << ": " << queryKey << endl;
        if (ans.size() == 0)
            cout << "Not Found" << endl;
        else{
            //sort(ans.begin(), ans.end());   //set内部自动排序，因此自己不用排了
            for (auto it = ans.begin(); it != ans.end(); ++it)
                printf("%07d\n", *it);
        }
    }
    return 0;
}
