import os  
import sys

os.path.exists('./text.txt')

fileHander = open("text.txt","r") 

if  len(sys.argv) > 1:
	pathfile =str(sys.argv[1])
	print pathfile 
myList = []

for line in  fileHander:
    myList.append(line)
print(myList)


for idx, item in enumerate(myList):
    myList[idx] = "123\n"	

str1 = ''.join(myList)

print(str1)
fileHander.close() 
 
 
fo = open("text.txt", "wb")
fo.write( str1);

# Close opend file
fo.close()