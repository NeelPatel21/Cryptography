/*
	--Playfair encryption method-- 
	developed by neel patel
*/
#include<string.h>
#include<stdlib.h>
#define no '@'
char mat[5][5];			//matrix used in encryption
int conv(char *s);		//process string s
int checkmat(char);		//find character in matrix
char inc(char c);		//increment character c
int getrow(char c);		
int getcol(char c);		
void fillmat(char *k);	//fill the matrix
char * playfare(char *st,int n);//apply encryption on string st

void main(){
	int i,j,n;
	char key[27],*text,*ct;
	printf("enter keyword :- ");
	scanf("%s",key);
	fillmat(key);
	printf("\nmatrix :- \n");
	for(i=0;i<5;i++){//print matrix
		for(j=0;j<5;j++)
			printf("%c ",mat[i][j]);
		printf("\n");
	}
	printf("\nenter length of text..\n");
	scanf("%d",&n);
	text=(char *)calloc(n+1,sizeof(char));
	printf("\nenter text..\n");
	scanf("%s",text);
	text[n]=NULL;
	ct=playfare(text,n);
	printf("cypher text :- %s",ct);
}

int conv(char *s){//convert string to lower case & replace j with i, return length of string
	int i;
	for(i=0;s[i]!=NULL;i++){
		if(s[i]=='j')
			s[i]='i';
		s[i]=tolower(s[i]);
	}
	return i;
}

void fillmat(char *s){//fill the matrix with keyword then rest of space will be filled by remaining characters
	int i,j,k;
	char r='a';
	conv(s);
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

char * playfare(char *s,int n){//apply encryption on string s using matrix mat, return cypher text 
	int i,c,r,c0,c1,f,j;
	char *st;
	st=(char *)calloc(n*2,sizeof(char));
	conv(s);
	for(i=0,j=0;s[j]!=NULL&&j<n;i+=2){
		if(s[j+1]==NULL||s[j]==s[j+1]){//if two letters are same or single element then add 'x'.
			c0=s[j];
			c1='x';
			j++;
		}
		else{
			c0=s[j];
			c1=s[j+1];
			j+=2;
		}
		if(getrow(c0)==getrow(c1)){//both elements in same row
			c=getcol(c0);
			r=getrow(c0);
			st[i]=mat[r][(c+1)%5];
			
			c=getcol(c1);
			r=getrow(c1);
			st[i+1]=mat[r][(c+1)%5];	
		}
		else if(getcol(c0)==getcol(c1)){//both elements in same column
			c=getcol(c0);
			r=getrow(c0);
			st[i]=mat[(r+1)%5][c];
				
			c=getcol(c1);
			r=getrow(c1);
			st[i+1]=mat[(r+1)%5][c];
		}
		else{//both elements in different column & row
			r=getrow(c0);
			c=getcol(c1);
			st[i]=mat[r][c];
			
			r=getrow(c1);
			c=getcol(c0);
			st[i+1]=mat[r][c];
		}
	}
	return st;
}

int getrow(char c){//return row of c in mat
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(c==mat[i][j])
				return i;
	return -1;
}

int getcol(char c){//return column of c in mat
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(c==mat[i][j])
				return j;
	return -1;
}
