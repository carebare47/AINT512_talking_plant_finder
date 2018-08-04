a = []
#database lookup name
a.append("one")
a.append("two")
a.append("three")
a.append("four")
a.append("five")
a.append("six")
a.append("seven")
a.append("eight")
a.append("nine")
a.append("ten")
a.append("eleven")
a.append("twelve")
a.append("thirteen")
a.append("fourteen")
a.append("fifteen")
a.append("sixteen")
a.append("seventeen")
a.append("eighteen")
a.append("nineteen")
a.append("twenty")

a.append(1)
a.append(2)
a.append(3)
a.append(4)
a.append(5)
a.append(6)
a.append(7)
a.append(8)
a.append(9)
a.append(10)
a.append(11)
a.append(12)
a.append(13)
a.append(14)
a.append(15)
a.append(16)
a.append(17)
a.append(18)
a.append(19)
a.append(20)




##############################################################################
##############################################################################
##############################################################################
databaseName = 0
intName = int(len(a)/3)
slotName = int(2*len(a)/3)
initialIntValue = 2

appgoto = "env2"
counter2 = int(2*len(a)/3)
twoThirds = int(2*len(a)/3)


x = 0
while (x < len(a)/2):
	print("int %s = %d;" % (a[x], initialIntValue))
	x = x + 1
	
print("")
print("")


databaseName = 0
intName = int(len(a)/3)
slotName = int(2*len(a)/3)
x = 0

while (x < len(a)/2):
	print("NLGetIntSlotValue(AppGetNLResult(app), \"%s_said\", &%s);" % (a[x], a[x]))
	print("if (%s == 1) {" % a[x])
	print("\tprintf(\"%%s\\n\", \"You said %s.\");" % a[x])
	print("\tnumberStringArray[numberCounter] = %d;" % a[x+int(len(a)/2)])
	print("\tnumberCounter = numberCounter + 1;")
	print("}")
	x+=1

x = 0
while (x < len(a)/2):
	print("%s_said" % (a[x]))
	x = x + 1
	
	