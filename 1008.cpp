#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i,next,now,time;
	now = 0;
	time = 0;
	for(i = 0; i < n; i++)
	{	cin >> next;
		if(next > now)
			time += (next - now) * 6;
		else
			time += (now - next) * 4;
		now = next;
		time += 5;
	}
	cout << time;
	return 0;
}