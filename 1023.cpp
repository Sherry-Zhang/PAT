#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	vector <char> in;
	vector <char> doubled;
	char c;
	while(scanf("%c",&c) != EOF)
		in.push_back(c);
	in.pop_back();
	int i,temp;
	int h = 0,l = 0;
	int j = 0;
	for(i = in.size() - 1;i >= 0;i--)
	{	temp = in[i] - '0';
		temp = temp * 2 + h;
		h = temp / 10;
		l = temp % 10;
		doubled.push_back(l + '0');
	}
	if(h)
		doubled.push_back(h + '0');
	vector <char> out;
	out = doubled;
	sort(out.begin(),out.end());
	sort(in.begin(),in.end());
	if(out == in)
		printf("Yes\n");
	else
		printf("No\n");
	for(i = doubled.size()-1;i >= 0;i--)
		printf("%c",doubled[i]);
	return 0;
}