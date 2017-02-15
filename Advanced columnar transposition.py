pt=(str(input("enter text :- ")))
nk=(int(input("enter number of keys :- ")))
keys=[""]*nk
for i in range(nk):
	keys[i]=keys[i]+(str(input("enter key :- ")))
for key in keys:
	l=list(pt)
	for i in range(len(l)):
		if(l[i]==' '):
			l[i]='x'
	l=l+(['x']*((len(key)-len(pt)%len(key))%len(key)))
	for x in range(1,len(key)+1):
		if str(x) not in key :
			print ('invalid key!!!')
			exit;
	else :
		col=['']*len(key)
		for i in range(len(l)):
			col[i%len(key)]= col[i%len(key)]+l[i]
		ct=''
		for i in key:
			ct=ct+col[int(i)-1]
	pt=ct;
else :
	print('cypher text :- ',ct)
