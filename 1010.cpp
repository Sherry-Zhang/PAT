//#include <iostream>
//#include <cstring>
//using namespace std;
//int Is_Equal(char N1[],char N2[],int radix);
//int main()
//{
//	char N1[10] = {};
//	char N2[10] = {};
//	int tag,radix;
//	scanf("%s%s%d%d",N1,N2,&tag,&radix);
//	int r;
//	if(tag == 1)
//		r = Is_Equal(N1,N2,radix);
//	else
//		r = Is_Equal(N2,N1,radix);
//	if(r)
//		printf("%d",r);
//	else
//		printf("Impossible");
//	return 0;
//}
//
//int Is_Equal(char N1[],char N2[],int radix)
//{	int r;
//	int i;
//	long long n1,n2;
//	n1 = n2 = 0;
//	for(i = 0;N1[i] != '\0';i++)
//	{	if(N1[i] >= '0' && N1[i] <= '9')
//			n1 = n1 * radix + N1[i] - '0';
//		else
//			n1 = n1 * radix + N1[i] - 'a' + 10;
//		if(n1 < 0)
//			return 0;
//	}
//	if(strlen(N2) == 1)
//	{	if(N2[0] >= '0' && N2[0] <= '9')
//			n2 = N2[0] - '0';
//		else
//			n2 = N2[0] - 'a' + 10;
//		if(n2 == n1)
//			return n2 + 1;
//		else
//			return 0;
//	}
//	for(r = 2;r <= 2000;r++)
//	{	for(i = 0;N2[i] != '\0';i++)
//		{	if(N2[i] >= '0' && N2[i] <= '9')
//				n2 = n2 * r + N2[i] - '0';
//			else
//				n2 = n2 * r + N2[i] - 'a' + 10;
//		}
//		if(n1 == n2)
//			break;
//		else
//			n2 = 0;
//	}
//	if(n1 != n2)
//		r = 0;
//	return r;
//}



#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define INF (long long)pow(36*1.0,10)
long long Is_Equal(char N1[],char N2[],int radix);
int main()
{
	char N1[10] = {};
	char N2[10] = {};
	int tag,radix;
	scanf("%s%s%d%d",N1,N2,&tag,&radix);
	long long r;
	if(tag == 1)
		r = Is_Equal(N1,N2,radix);
	else
		r = Is_Equal(N2,N1,radix);
	if(r)
		printf("%d",r);
	else
		printf("Impossible");
	return 0;
}

long long Is_Equal(char N1[],char N2[],int radix)
{	long long r;
	int i;
	long long n1,n2;
	n1 = n2 = 0;
	for(i = 0;N1[i] != '\0';i++)
	{	if(N1[i] >= '0' && N1[i] <= '9')
			n1 = n1 * radix + N1[i] - '0';
		else
			n1 = n1 * radix + N1[i] - 'a' + 10;
		if(n1 < 0)
			return 0;
	}
	if(strlen(N2) == 1)
	{	if(N2[0] >= '0' && N2[0] <= '9')
			n2 = N2[0] - '0';
		else
			n2 = N2[0] - 'a' + 10;
		if(n2 == n1)
			return n2 + 1;
		else
			return 0;
	}
	long long left = 2;
	long long right = INF - 1;
	r = (left + right) / 2;
	while(left < right)
	{	n2 = 0;
		for(i = 0;N2[i] != '\0';i++)
		{	if(N2[i] >= '0' && N2[i] <= '9')
				n2 = n2 * r + N2[i] - '0';
			else
				n2 = n2 * r + N2[i] - 'a' + 10;
			if(n2 < 0)
				n2 = INF;
		}
		if(n1 < n2)
		{	right = r - 1;
			r = (left + right) / 2;
		}
		else if(n1 > n2)
		{	left = r + 1;
			r = (left + right) / 2;
		}
		else
		{	int temp = 0;
			for(i = 0;N2[i] != '\0';i++)
			{	if(N2[i] >= '0' && N2[i] <= '9')
					temp = temp * (r - 1)+ N2[i] - '0';
				else
					temp = temp * (r - 1) + N2[i] - 'a' + 10;
			}
			if(temp < n1)
				break;	
			else
			{	right = r - 1;
				r = (left + right) / 2;
			}
		}
			
	}
	if(n1 != n2)
		r = 0;
	return r;
}