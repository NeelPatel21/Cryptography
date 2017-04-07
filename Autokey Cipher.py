func=lambda b,x:chr((ord(x)-97+ord(b)-97)%26+65) if x.islower else chr((ord(x)-65+ord(b)-97)%26+65)
def keyStream(key,text):
	for i in key.lower():
		yield i
	for i in text.lower():
		yield i
pt=str(input("enter text :- "))
keyS=keyStream(str(input("enter key :- ")),pt)
ct="".join(func(next(keyS),i) for i in pt)
print ("cipher text :- ",ct)