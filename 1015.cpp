#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int> prime;
bool Is_Prime(int n);
int main()
{
	int n,d;
	while(1)
	{	cin >> n;
		if(n < 0)
			break;
		cin >> d;
		if(Is_Prime(n) == false)
		{	printf("No\n");
			continue;
		}		
		vector <int> s;
		int temp;
		while(n)
		{	temp = n % d;
			s.push_back(temp);
			n = n / d;
		}
		int i,rev = 0;
		for(i = 0; i < s.size(); i++)
			rev = rev * d + s[i];
//		s.clear();
		if(Is_Prime(rev))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
bool Is_Prime(int n)
{
	int i;
	if(n == 2)
		return true;
	if(n == 1)
		return false;
	if(n % 2 == 0)
		return false;
	for(i = 3; i <= sqrt(n * 1.0); i += 2)
	{	if(n % i == 0)
			return false;
	}
	return true;
}