#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct polynomial
{
	int ex;
	double co;
};
bool cmp(const polynomial &a,const polynomial &b)
{	
	return a.ex > b.ex;
}
int main()
{
	int num1,num2;
	cin >> num1;
	vector <polynomial> a(num1);
	int i;
	for(i = 0;i < num1;i++)
		cin >> a[i].ex >> a[i].co;
	cin >> num2;
	vector <polynomial> b(num2);
	for(i = 0;i < num2;i++)
		cin >> b[i].ex >> b[i].co;
	int j;
	vector <polynomial> out;
	polynomial c;
	for(i = 0; i < num1;i++)
	{	for(j = 0;j < num2;j++)
		{	c.ex = a[i].ex + b[j].ex;
			c.co = a[i].co * b[j].co;
			out.push_back(c);
		}
	}
	sort(out.begin(),out.end(),cmp);
	for(i = 0;i + 1 < out.size();)
	{	if(out[i].ex == out[i + 1].ex)
		{	out[i].co += out[i + 1].co;
			out.erase(out.begin() + i + 1);
			if(out[i].co == 0)
				out.erase(out.begin() + i);
		}
		else
			i++;
	}
	printf("%d",out.size());
	for(i = 0;i < out.size();i++)
		printf(" %d %.1f",out[i].ex,out[i].co);
	return 0;
}