#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//如果是insert排序，返回true;否则返回false
bool insert_sort(vector<int>& list, vector<int>& cmp)
{
    int len = list.size();
    bool flag = false;
    for (int p = 1; p < len; ++p)
    {
        int tmp = list[p];
        //插入到有序的数组中
        int i;
        for (i = p - 1; i >= 0 && list[i] > tmp; --i)
            list[i + 1] = list[i];
        list[i + 1] = tmp;
        //一趟排序结束
        if (flag)              //多排序一次，然后返回
            return true;
        if (list == cmp )
            flag = true;
    }
    return false;
}
void heap_sort(vector<int>& list, vector<int>& cmp)
{
    bool flag = false;
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        auto it = list.begin() + (len - i);
        make_heap(list.begin(), it);
        if (flag)
            return;
        if (list == cmp)
            flag = true;
        swap(list[0], list[len - i - 1]);  //一次堆排结束
    }
}
int main()
{
    int num;
    cin >> num;
    vector <int> before(num);
    vector <int> after(num);
    for (int i = 0; i < num; ++i)
        cin >> before[i];
    for (int i = 0; i < num; ++i)
        cin >> after[i];
    vector<int> tmp = before;
    bool isInsert = insert_sort(before,after);
    if (isInsert == true)
    {
        cout << "Insertion Sort" << endl << before.front();
        for (auto it = before.begin() + 1; it != before.end(); ++it)
            cout << ' ' << *it;
    }
    else
    {
        heap_sort(tmp, after);
        cout << "Heap Sort" << endl << tmp.front();
        for (auto it = tmp.begin() + 1; it != tmp.end(); ++it)
            cout << ' ' << *it;
    }
    return 0;
}
