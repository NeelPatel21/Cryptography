def add(f):
	global pt
	pt=pt+f;
pt=(str(input("enter text :- ")))
l=list(pt)
for i in range(len(l)):
	if(l[i]==' '):
		l[i]='x'
key=(str(input("enter key :- ")))
l=l+(['x']*(len(key)-len(pt)%len(key)))
for x in range(1,len(key)+1):
	if str(x) not in key :
		print ('invalid key!!!')
		break
else :
	col=['']*len(key)
	for i in range(len(l)):
		col[i%len(key)]= col[i%len(key)]+l[i]
	ct=''
	for i in key:
		ct=ct+col[int(i)-1]
	print('cypher text :- ',ct)		