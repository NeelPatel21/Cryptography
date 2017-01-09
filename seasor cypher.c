#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int l;
char func(char c,int k);
void main()
{
	char *c,i;
	int k;
	printf("length :- ");
	scanf("%d",&l);
	c=(char*)calloc(l+1,sizeof(char));
	printf("Text :- ");
	scanf("%^[\n]s\n",c);
	c[l]=NULL;
	printf("Enter key :- ");
	scanf("%d",&k);
	printf("Cypher text :- ");
	for(i=0;c[i]!=NULL;i++)
		printf("%c",func(c[i],k));
}
char func(char c,int k)
{
	if(!isalpha(c))
		return c;
	if(islower(c))
	{
		c=c-97;
		c=(c+k)%26;
		c+=97;
	}
	else
	{
		c=c-65;
		c=(c+k)%26;
		c+=65;
	}
	return c;
}
