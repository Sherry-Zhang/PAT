#include <iostream>
#include <vector>
using namespace std;
struct User
{
	char name[11];
	char password[11];
};
int main()
{
	int n;
	cin >> n;
	vector <User> u(n);
	vector <int> out;
	int i;
	int p;
	int count = 0;
	bool modify = false;
	for(i = 0; i < n; i++)
	{	cin >> u[i].name >> u[i].password;
		modify = false;
		for(p = 0;u[i].password[p] != '\0';p++)
		{	
			if(u[i].password[p] == '1')
			{	u[i].password[p] = '@';
				modify = true;
			}
			else if(u[i].password[p] == 'l')
			{	u[i].password[p] = 'L';
				modify = true;
			}
			else if(u[i].password[p] == '0')
			{	u[i].password[p] = '%';
				modify = true;
			}
			else if(u[i].password[p] == 'O')
			{	u[i].password[p] = 'o';
				modify = true;
			}
		}
		if(modify == true)
			out.push_back(i);
	}
	if(!out.size())
	{	if(n > 1)
			printf("There are %d accounts and no account is modified",n);
		else
			printf("There is 1 account and no account is modified",n);
	}
	else
	{	cout << out.size() << endl;
		for(i = 0;i < out.size();i++)
			cout << u[out[i]].name << ' ' << u[out[i]].password << endl;
	}
	return 0;
}