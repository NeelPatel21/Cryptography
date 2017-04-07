def eucl(a,b):
	if a<b:
		a,b=b,a
	while a%b!=0:
		a,b=b,a%b
	return b
a=int(input("enter 1st number :- "))
b=int(input("enter 2nd number :- "))
print ("GCD of {0} & {1} :- {2}".format(a,b,eucl(a,b)))