#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long transfer(vector <int> &n);
int main()
{
	long long n;
	int k;
	cin >> n >> k;
	vector <int> n1;
	vector <int> n2;
	int temp;
	int count = 0;
	long long x1,x2;
	int i;
	for(i = 0;i <= k;i++)
	{	n1.clear();
		n2.clear();
		while(n)
		{	temp = n % 10;
			n1.push_back(temp);
			n = n / 10;
		}
		n2 = n1;
		reverse(n1.begin(),n1.end());	
		if(n1 != n2)
		{	x1 = transfer(n1);
			x2 = transfer(n2);
			n = x1 + x2;
			count++;
		}
		else
			break;
	}
	if(count > k)
		count = k;
	n = transfer(n1);
	cout << n << endl;
	cout << count;
	return 0;
}
long long transfer(vector <int> &n)
{
	long long x = 0;
	int i;
	for(i = 0;i < n.size();i++)
		x = x * 10 + n[i];
	return x;
}