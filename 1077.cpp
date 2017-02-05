#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char s[100][257] = {};
	int i,j,len;
	getchar();
	int minlen = 257;
	for(i = 0;i < n;i++)
	{	gets(s[i]);
		len = strlen(s[i]);
		reverse(s[i],s[i]+len);
		if(len < minlen)
			minlen = len;
	}
	bool k = false;
	for(j = 0; j < minlen;j++)
	{	for(i = 1;i < n;i++)
		{	if(s[i][j] != s[0][j])
			{	k = true;
				break;
			}
		}
		if(k == true)
		{	s[0][j] = '\0';
			break;
		}
	}
	if(j == 0)
		cout << "nai";
	else
	{	reverse(s[0],s[0] + j);
		puts(s[0]);
	}
	return 0;
}