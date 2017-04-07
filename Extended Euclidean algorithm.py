def extEucl(a,b,s1=1,s2=0,t1=0,t2=1):
	if a<b:
		a,b=b,a
	if a%b==0:
		return b,s1-(a//b)*s2,t1-(a//b)*t2
	return extEucl(b,a%b,s2,s1-(a//b)*s2,t2,t1-(a//b)*t2)
a=int(input("enter 1st number :- "))
b=int(input("enter 2nd number :- "))
c=extEucl(a,b)
print ("GCD of {0} & {1}:- {2}".format(a,b,c[0]))
print ("si :-",c[1])
print ("ti :-",c[2])