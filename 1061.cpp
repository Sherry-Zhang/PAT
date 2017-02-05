#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s1[61],s2[61],s3[61],s4[61];
	char week[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	gets(s1);
	gets(s2);
	gets(s3);
	gets(s4);
	int i;
	for(i = 0; s1[i] != '\0' && s1[i] != '\0';i++)
	{	if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G' )
		{	printf("%s ",week[s1[i] - 'A']);
			i++;
			break;
		}
	}
	int hour,minute;
	while(s1[i] != '\0' && s2[i] != '\0')
	{	if(s1[i] == s2[i])
		{	if(s1[i] >= '0' && s1[i] <= '9')
			{	hour = s1[i] - '0';
				break;
			}
			else if(s1[i] >= 'A' && s1[i] <= 'N')
			{	hour = s1[i] - 'A' + 10;
				break;
			}
		}
		i++;
	}
	for(i = 0; s3[i] != '\0' && s4[i] != '\0';i++)
	{	if(s3[i] == s4[i] && ((s3[i] >= 'A' && s3[i] <= 'Z') ||( s3[i] >= 'a' && s3[i] <= 'z')))
		{	minute = i;
			break;
		}
	}
	printf("%02d:%02d",hour,minute);
	return 0;
}
