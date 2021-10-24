#this will print a in binary

def decToByn(a:int):
  bnr = bin(a).replace('0b','')
  x = bnr[::-1] #this reverses an array
  while len(x) < 8:
    x += '0'
    
  bnr = x[::-1]
  res='B'+bnr
  return res

def openBraces()->str:
  return "{"

def closeBraces()->str:
  return "}"


  

  
i:int=0
f = open("decToBin.h", "w")



print("byte decToBin(int num){")
f.write("byte decToBin(int num){")

print("int var=num;")
f.write("int var=num;")
 


  

print(f"switch (var) {openBraces()}")
f.write(f"switch (var) {openBraces()}")
while(i<256):
  text:str=f"""
  
  case {i}:
    //do something when var equals {i}
    return {decToByn(i)} ;
  """
  f.write(text)
  print(text)
  i=i+1

f.write(f"{closeBraces()}")
print(f"{closeBraces()}")

f.write(f"{closeBraces()}")
print(f"{closeBraces()}")





f.close()