s=(str(input('enter string..')))
l=(int(input('enter level..')))-1
lev=[""]*(l+1);i=0
for x in range(len(s)):
	lev[abs(l-x%(l*2))]+=s[x]
print("cypher text :- ",''.join(r for r in lev[::-1]))
