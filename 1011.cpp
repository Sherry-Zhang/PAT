#include <iostream>
#include <vector>
using namespace std;
int main()
{
	double w,t,l;
	char _max;
	double profit = 1;
	double odd;
	vector <char> out;
	while(scanf("%lf%lf%lf",&w,&t,&l) != EOF)
	{	if(w > l && w > t)
		{	_max = 'W';
			odd = w;
		}
		else if(l > w && l > t)
		{	_max = 'L';
			odd = l;
		}
		else
		{	_max = 'T';
			odd = t;
		}
		profit *= odd;
		out.push_back(_max);
	}
	for(int i = 0;i < out.size();i++)
		printf("%c ",out[i]);
	profit = (profit * 0.65 - 1) * 2;
	printf("%.2f",profit);
	return 0;
}