#include <iostream>
#include <vector>
using namespace std;
void Transfer(int n);
int main()
{
	int red,green,blue;
	cin >> red >> green >> blue;
	cout << "#";
	Transfer(red);
	Transfer(green);
	Transfer(blue);
	return 0;
}
void Transfer(int n)
{
	int temp;
	vector <char> s;
	while(n)
	{	temp = n % 13;
		if(temp < 10)
			s.push_back(temp + '0');			
		else
			s.push_back(temp - 10 + 'A');	
		n = n / 13;
	}
	while(s.size() < 2)
	{	s.push_back('0');
	}
	for(int i = 1;i >= 0;i--)
		cout << s[i];
}