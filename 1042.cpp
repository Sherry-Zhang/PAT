#include <iostream>
#include <cstring>
using namespace std;
char card[54][4] = {};
int order[54] = {};
char out[54][4] = {};
void init()
{
	int i;
	for(i = 1; i <= 13; i++)
		sprintf(card[i - 1],"S%d",i);
	for(i = 1; i <= 13; i++)
		sprintf(card[i + 12],"H%d",i);
	for(i = 1; i <= 13; i++)
		sprintf(card[i + 25],"C%d",i);
	for(i = 1; i <= 13; i++)
		sprintf(card[i + 38],"D%d",i);
	for(i = 1; i <= 2; i++)
		sprintf(card[i + 51],"J%d",i);
}

void shuffle()
{
	int i;
	for(i = 0;i < 54;i++)
		strcpy(out[order[i] - 1],card[i]);
	for(i = 0; i < 54; i++)
		strcpy(card[i],out[i]);
}
int main()
{
	init();
	int i,k;
	scanf("%d",&k);
	for(i = 0;i < 54;i++)
		scanf("%d",&order[i]);
	for(i = 0;i < k;i++)
		shuffle();
	printf("%s",out[0]);
	for(i = 1;i < 54; i++)
		printf(" %s",out[i]);
	return 0;
}