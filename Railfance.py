s=(str(input('enter string..')))
l=(int(input('enter level..')))-1
lev=[""]*(l+1);i=0
for x in s:
	lev[abs(l-s.index(x)%(l*2))]+=x
print("cypher text :- ",''.join(r for r in lev))