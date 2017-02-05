#include <iostream>
#include <cstring>
using namespace std;
void Transfer(int q[]);
char read[10][5] ={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char digit[3][5] = {"Qian","Bai","Shi"};
bool Y = false,W = false,Q = false;
bool print = false;
int main()
{
	char s[11];
	gets(s);
	int len = strlen(s);
	if(len == 1 && s[0] == '0')
	{	printf("ling");
		return 0;
	}
	int i,p,start = 0;
	int w[4] = {};
	int q[4] = {};
	p = len - 1;	
	for(i = 3;i >= 0 && p >= 0 && s[p] != '-';i--)
	{	q[i] = s[p--] - '0';
		if(q[i] && Q == false)
			Q = true;
	}
	for(i = 3;i >= 0 && p >= 0 && s[p] != '-';i--)
	{	w[i] = s[p--] - '0';
		if(w[i] && W == false)
			W = true;
	}
	if(s[0] == '-')
	{	printf("Fu ");
		len--;
		start++;
	}
	if(len > 8)
	{	printf("%s Yi",read[s[start] - '0']);
		Y = true;
		if(W)
		{	printf(" ");
			if(w[0] == 0)
				printf("ling ");
			Transfer(w);
			printf(" Wan");
			if(Q)
			{	printf(" ");
				if(q[0] == 0)
					printf("ling ");
				Transfer(q);
			}
		}
		else if(Q)
		{	printf(" ");
			if(q[0] == 0)
				printf("ling ");
			Transfer(q);
		}
	}
	else if(len > 4)
	{	Transfer(w);
		printf(" Wan");
		if(Q)
		{	printf(" ");
			if(q[0] == 0)
				printf("ling ");
			Transfer(q);
		}
	}
	else
		Transfer(q);
	return 0;
}
void Transfer(int q[])
{
	int i,start = -1,end;
	for(i = 0;i < 3;i++)
	{	if(q[i])
		{	start = i;
			printf("%s %s",read[q[i]],digit[i]);
			break;
		}
	}
	if(start == -1 && q[3])
	{	printf("%s",read[q[3]]);
		return;
	}
	if(start == -1)
	{	printf("ling");
		return;
	}
	for(i = 3;i >= 0;i--)
	{	if(q[i])
		{	end = i;
			break;
		}
	}
	bool zero = false;
	for(i = start + 1;i < end;i++)
	{	if(q[i])
		{	printf(" %s %s",read[q[i]],digit[i]);
			zero = false;
		}
		else if(zero  == false)
		{	printf(" ling");
			zero = true;
		}
	}
	if(end > start)
	{	if(end == 3)
			printf(" %s",read[q[i]]);
		else
			printf(" %s %s",read[q[i]],digit[i]);
	}
}
