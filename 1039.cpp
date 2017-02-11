#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
//本题对时间复杂度的要求太高，故而只能用c的字符串表示方式和输入输出方式来写,以及使用了字符串hash
using namespace std;
int getID(char* name)
{
    int id = 0;
    for (int i = 0; i < 3; ++i)
        id = id * 26 + name[i] - 'A';
    id = id * 10 + name[3] - '0';
    return id;
}
int main()
{
    int stuNum, courseNum;
    scanf("%d%d", &stuNum, &courseNum);
    map<int, vector<int> > stuCourse;
    int courseId;
    int couStuNum;
    char stuName[4];
    for (int i = 0; i < courseNum; ++i)
    {
        scanf("%d%d", &courseId, &couStuNum);
        for (int j = 0; j < couStuNum; ++j)
        {
            scanf("%s", stuName);
            int id = getID(stuName);
            auto iter = stuCourse.find(id);
            if (iter == stuCourse.end())
            {
                vector<int> tmp;
                tmp.push_back(courseId);
                stuCourse.insert({ id, tmp });
            }
            else
                iter->second.push_back(courseId);
        }
    }
    for (int i = 0; i < stuNum; ++i)
    {
        scanf("%s", stuName);
        printf("%s ", stuName);
        int id = getID(stuName);
        auto iter = stuCourse.find(id);
        if (iter == stuCourse.end())
            printf("0\n");
        else
        {
            int len = iter->second.size();
            printf("%d", len);
            sort(iter->second.begin(), iter->second.end());
            for (int j = 0; j < len; ++j)
                printf(" %d", iter->second[j]);
            printf("\n");
        }
    }
    return 0;
}
