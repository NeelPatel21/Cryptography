func=lambda a,b,x:chr((a*(ord(x)-97)+b)%26+65) if x.islower else chr((a*(ord(x)-65)+b)%26+65)
pt=str(input("enter text :- "))
ct="".join(func(3,12,i) for i in pt)
print ("cipher text :- ",ct)