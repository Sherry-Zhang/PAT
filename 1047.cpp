#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
//string会导致超时
//cin、cout会超时
bool cmp(const char* a, const char* b)
{
    if (strcmp(a, b) < 0)
        return true;
    else
        return false;
}
int main()
{
    int stuNum, courseNum;
    scanf("%d%d", &stuNum, &courseNum);
    vector<vector<char*>> match(courseNum);
    char *pstu;
    int selectNum, courseId;
    for (int i = 0; i < stuNum; ++i)
    {
        pstu = new char[5];
        scanf("%s%d", pstu, &selectNum);
        for (int j = 0; j < selectNum; ++j)
        {
            scanf("%d", &courseId);
            match[courseId - 1].push_back(pstu);
        }
    }
    for (int i = 0; i < courseNum; ++i)
    {
        int len = match[i].size();
        printf("%d %d\n", i + 1, len);
        sort(match[i].begin(), match[i].end(),cmp);
        for (int j = 0; j < len; ++j)
            printf("%s\n", match[i][j]);
    }
    return 0;
}
