#include<stdlib.h>
#include<ctype.h>
struct tab{
	char c;
	int r;
}*t;
int func(char *s,int);
void main()
{
	int n,i,l;
	char *s;
	printf("enter number of characters...");
	scanf("%d",&n);
	s=(char*)calloc(n,sizeof(char));
	for(;s[0]==NULL;gets(s));
	l=func(s,n);
	for(i=0;i<l;i++)
		printf("%c :- %d\n",t[i].c,t[i].r);
}
int func(char *s,int n)
{
	int i,j,l=0,f;
	t=(struct tab*)calloc(n,sizeof(struct tab*));
	for(i=0;s[i]!=NULL;i++){
		if(!isalpha(s[i]))
			continue;
		f=0;
		for(j=0;j<l;j++)
			if(t[j].c==s[i]){
				t[j].r++;
				f++;
			}
		if(j==l && !f){
			t[l++].c=s[i];
			t[l-1].r++;
		}
	}
	return l;
}
