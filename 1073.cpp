#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s1[200001];
	char s2[200001];
	gets(s1);
	char d = s1[1];	//��������
	char *p;
	p = strchr(s1,'E');
	*p = '\0';
	char f[100001];	//С������
	strcpy(f,s1 + 3);
	int l;
	sscanf(p+2,"%d",&l);
	if(*(p+1) == '+')	//С��������
	{	s2[0] = d;
		int i,len = strlen(f);
		if(len <= l)
		{	strcpy(s2+1,f);		
			for(i = 0;i < l-len;i++)
				s2[len + 1 + i] = '0';
			s2[len + 1 + i] = '\0';
		}
		else
		{	for(i = 0;i < l;i++)
				s2[i + 1] = f[i];
			s2[i + 1] = '.';
			strcpy(s2 + i + 2,f + i);
		}
	}
	else				//С��������
	{	s2[0] = '0';
		s2[1] = '.';
		int i;
		for(i = 0;i < l - 1;i++)
			s2[i + 2] = '0';
		s2[i + 2] = d;
		strcpy(s2 + i + 3,f);
	}
	if(s1[0] == '-')
		printf("-");
	puts(s2);
	return 0;
}