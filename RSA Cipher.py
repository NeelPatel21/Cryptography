from math import *
def isprime(x):
	for i in range(2,int(x**0.5)+1):
		if(x%i==0):
			return False
	return True
iscopri=lambda x,y:gcd(x,y)==1
def getd(e,fn):
	i=1
	while True:
		if ((i*e)%fn==1):
			return i
		i+=1
a=int(input("enter first number :- "))
if not isprime(a):
	print("invalid number!!!")
	exit(0)
b=int(input("enter secound number :- "))
if not isprime(b):
	print("invalid number!!!")
	exit(0)
n=a*b
fn=(a-1)*(b-1)
e=[i for i in range(2,fn) if iscopri(i,fn)]
key=list(zip(e,[getd(i,fn) for i in e]))
print("keys :-",key)
k=key[1]
pt=int(input("enter nuber :- "))
ct=pt**k[0]%n
print ("cipher text :-",ct)
print ("public key :-",(k[0],n))
print ("private key :-",(k[1],n))