#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void Build_U(int n);
int x,y;
int main()
{
	char s[81];
	gets(s);
	int n = strlen(s);
	Build_U(n);
	vector <vector <char> > u(x,vector<char>(y));
	int i,p;
	for(i = 0;i < x;i++)
	{	for(p = 0;p < y;p++)
			u[i][p] = ' ';
	}
	i = 0;
	for(p = 0;p < x;p++)
		u[p][0] = s[i++];
	for(p = 1;p < y;p++)
		u[x - 1][p] = s[i++];
	for(p = x - 2;p >= 0;p--)
		u[p][y - 1] = s[i++];
	for(i = 0;i < x;i++)
	{	for(p = 0; p < y - 1; p++)	
			printf("%c",u[i][p]);
		printf("%c\n",u[i][p]);
	}
	return 0;
}
void Build_U(int n)
{
	int size = n + 2;
	x = size / 3;
	y = size - x - x;
}