s=(str(input('enter string..')))
l=(int(input('enter level..')))-1
lev=list();
for j in range(l+1):
	lev.append("")
m=(l)*2
i=0
for x in s:
	lev[abs(l-i%m)]+=x
	i+=1
ct=""
for r in lev:
	ct+=r
print("cypher text :- ",ct)