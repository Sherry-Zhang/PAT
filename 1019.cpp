#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> in;
vector <int> out;
int main()
{
	int n,b;
	cin >> n >> b;
	if(!n)
	{	printf("Yes\n0");
		return 0;
	}
	bool flag = false;
	int temp;
	while(n)
	{	temp = n % b;
		in.push_back(temp);
		n = n / b;
	}
	out = in;
	reverse(out.begin(),out.end());
	if(out == in)
		printf("Yes\n");
	else
		printf("No\n");

	printf("%d",out[0]);
	for(int i = 1;i < out.size();i++)
		printf(" %d",out[i]);
	return 0;
}
