#include<string.h>
#include<stdlib.h>
#define no '@'
char mat[5][5];
int conv(char *s);
int checkmat(char);
char inc(char c);
int getrow(char c);
int getcol(char c);
void fillmat(char *k);
void playfare(char *st,int n);
void main(){
	int i,j;
	char key[10],text[20];
	printf("enter keyword :- ");
	scanf("%s",key);
	fillmat(key);
	for(i=0;i<5;i++){//print matrix
		for(j=0;j<5;j++)
			printf("%c ",mat[i][j]);
		printf("\n");
	}
	printf("\nenter text..\n");
	scanf("%s",text);
	playfare(text,20);
	printf("cypher text :- %s",text);
}

int conv(char *s){//process string & replace j with i
	int i;
	for(i=0;s[i]!=NULL;i++)
		if(s[i]=='j')
			s[i]='i';
	return i;
}

void fillmat(char *s){
	int i,j,k;
	char r='a';
	conv(s);//replace j with i
	{//fill the matrix with NULL
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				mat[i][j]=no;
	}
	{//enter key in matrix
		for(i=0,k=0;i<5&&s[k]!=NULL;i++)
			for(j=0;j<5&&s[k]!=NULL;j++){
				for(;s[k]!=NULL&&checkmat(s[k]);k++);
				if(s[k]!=NULL)
					mat[i][j]=s[k];
			}
	}
	{//fill rest of matrix
		r='a';
		for(i=0;i<5&&r<='z';i++)
			for(j=0;j<5&&r<='z';j++){
				if(mat[i][j]==no){
					for(;checkmat(r);r=inc(r));
					mat[i][j]=r;
				}
			}
	}	
}

int checkmat(char c){//return index if c exist in matrix otherwise return 0
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(mat[i][j]==c)
				return i*5+j+1;
	return 0;
}

char inc(char c){//increment c, if new value of c is j then again increment c, return null if c is not alpha
	c++;
	if(c=='j')
		c++;
	if(c>='a'&&c<='z')
		return c;
	return NULL;
}

void playfare(char *st,int n){//apply encryption on string st (in place)
	int i,c,r,c0,c1;
	conv(st);//replace j with i in text
	for(i=0;st[i]!=NULL;i+=2){
		if(getrow(st[i])==getrow(st[i+1])){//both elements in same row
			c0=st[i];
			c1=st[i+1];
			{
				c=getcol(c0);
				r=getrow(c0);
				st[i]=mat[r][(c+1)%5];
			}
			{
				c=getcol(c1);
				r=getrow(c1);
				st[i+1]=mat[r][(c+1)%5];
			}
		}
		else if(getcol(st[i])==getcol(st[i+1])){//both elements in same col
			c0=st[i];
			c1=st[i+1];
			{
				c=getcol(c0);
				r=getrow(c0);
				st[i]=mat[(r+1)%5][c];
			}
			{
				c=getcol(c1);
				r=getrow(c1);
				st[i+1]=mat[(r+1)%5][c];
			}
		}
		else{//both elements in different column & row
			c0=st[i];
			c1=st[i+1];
			{
				r=getrow(c0);
				c=getcol(c1);
				st[i]=mat[r][c];
			}
			{
				r=getrow(c1);
				c=getcol(c0);
				st[i+1]=mat[r][c];
			}
		}
	}
}

int getrow(char c){//return column of c in mat
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(c==mat[i][j])
				return i;
	return -1;
}

int getcol(char c){//return row of c in mat
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(c==mat[i][j])
				return j;
	return -1;
}
