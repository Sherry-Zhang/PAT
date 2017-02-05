#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct student
{	string ID;
	int c,m,e;
	double a;
};
bool cmp1(const student &a,const student &b)
{	return a.a > b.a;
}
bool cmp2(const student &a,const student &b)
{	return a.c > b.c;
}
bool cmp3(const student &a,const student &b)
{	return a.m > b.m;
}
bool cmp4(const student &a,const student &b)
{	return a.e> b.e;
}
struct Rank
{	int i;
	char r;
};
bool cmp_rank(const Rank &a,const Rank &b)
{	return a.i < b.i;
}
int main()
{
	int n,m;
	cin >> n >> m;
	vector <student> stu;
	vector <student> sort_by_c;
	vector <student> sort_by_m;
	vector <student> sort_by_e;
	vector <student> sort_by_a;
	vector <Rank> r;
	student in;
	Rank out;
	int i,j,k;
	for(i = 0;i < n;i++)
	{	cin >> in.ID >> in.c >> in.m >> in.e;
		in.a = (in.c + in.m + in.e) * 1.0/ 3;
		stu.push_back(in);
	}
	sort_by_a = sort_by_c = sort_by_m = sort_by_e = stu;
	sort(sort_by_a.begin(),sort_by_a.end(),cmp1);
	sort(sort_by_c.begin(),sort_by_c.end(),cmp2);
	sort(sort_by_m.begin(),sort_by_m.end(),cmp3);
	sort(sort_by_e.begin(),sort_by_e.end(),cmp4);
	string id;
	bool _find;
	for(i = 0;i < m;i++)
	{	cin >> id;
		_find = false;
		for(j = 0;j < n; j++)
		{	if(stu[j].ID == id)
			{	_find = true;
				for(k = 0; k < n; k++)
				{	if(sort_by_a[k].a == stu[j].a)
					{	out.i = k+1;
						out.r = 'A';
						r.push_back(out);
						break;
					}
				}	
				for(k = 0; k < n; k++)
				{	if(sort_by_c[k].c == stu[j].c)
					{	out.i = k+1;
						out.r = 'C';
						r.push_back(out);
						break;
					}
				}
				for(k = 0; k < n; k++)
				{	if(sort_by_m[k].m == stu[j].m)
					{	out.i = k+1;
						out.r = 'M';
						r.push_back(out);
						break;
					}
				}
				for(k = 0; k < n; k++)
				{	if(sort_by_e[k].e == stu[j].e)
					{	out.i = k+1;
						out.r = 'E';
						r.push_back(out);
						break;
					}
				}
				sort(r.begin(),r.end(),cmp_rank);
				printf("%d %c\n",r[0].i,r[0].r);
				r.clear();
				break;
			}
		}
		if(_find == false)
			printf("N/A\n");
	}
	return 0;
}
