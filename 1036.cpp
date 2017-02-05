#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
	char name[11];
	char gender;
	char ID[11];
	int grade;
};

int main()
{
	int n;
	cin >> n;
	vector <Student> stu(n);
	int i;
	int max_f = -1,min_m = 101;
	int f = 0,m = 0;
	for(i = 0; i < n; i++)
	{	cin >> stu[i].name >> stu[i].gender >> stu[i].ID >> stu[i].grade;
		if(stu[i].gender == 'M')
		{	if(stu[i].grade < min_m)
			{	m = i;
				min_m = stu[i].grade;
			}
		}
		else
		{	if(stu[i].grade > max_f)
			{	f = i;
				max_f = stu[i].grade;
			}
		}
	}
	if(max_f != -1)
		cout << stu[f].name << ' ' << stu[f].ID << endl;
	else
		cout << "Absent" << endl;
	if(min_m != 101)
		cout << stu[m].name << ' ' << stu[m].ID << endl;
	else
		cout << "Absent" << endl;
	if(max_f != -1 && min_m != 101)
		cout << stu[f].grade - stu[m].grade << endl;
	else
		cout << "NA" << endl;
	return 0;
}
