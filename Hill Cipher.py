ltn=lambda x:(ord(x)-65)%26 if(x.isupper()) else (ord(x)-97)%26
ntl=lambda x:chr(x%26+65)
def matmult(a,b):
    zip_b = zip(*b)
    return [[sum(ele_a*ele_b for ele_a, ele_b in zip(row_a, col_b)) 
             for col_b in zip_b] for row_a in a]
pt=str(input("enter text:- "))
if(len(pt)%2!=0):
	pt+='x'
key=str(input("enter key of four letters:- "))
key=[[ltn(key[0]),ltn(key[1])],[ltn(key[2]),ltn(key[3])]]
ct=""
for i in range(0,len(pt),2):
	ct+="".join([ntl(i) for i in matmult(key,[[ltn(pt[i]),ltn(pt[i+1])]])[0]])
print ("cipher text :-",ct)