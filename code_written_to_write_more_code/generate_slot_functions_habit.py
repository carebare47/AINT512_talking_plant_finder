a = []
#database lookup name
a.append("Shrub")
a.append("Annual")
a.append("Perennial")
a.append("Tree")
a.append("Perennial Climber")
a.append("Annual_slash_Perennial")
a.append("Climber")
a.append("Fern")
a.append("Bulb")
a.append("Biennial")
a.append("Annual_slash_Biennial")
a.append("Biennial_slash_Perennial")
a.append("Bamboo")
a.append("Corm")
a.append("Lichen")
a.append("Annual Climber")

#int name
a.append("shrub")
a.append("annual")
a.append("perennial")
a.append("tree")
a.append("perennial_climber")
a.append("annual_slash_perennial")
a.append("climber")
a.append("fern")
a.append("bulb")
a.append("biennial")
a.append("annual_slash_biennial")
a.append("biennial_slash_perennial")
a.append("bamboo")
a.append("corm")
a.append("lichen")
a.append("annual_climber")

#slot name
a.append("shrub_said")
a.append("annual_said")
a.append("perennial_said")
a.append("tree_said")
a.append("perennial_climber_said")
a.append("annual_slash_perennial_said")
a.append("climber_said")
a.append("fern_said")
a.append("bulb_said")
a.append("biennial_said")
a.append("annual_slash_biennial_said")
a.append("biennial_slash_perennial_said")
a.append("bamboo_said")
a.append("corm_said")
a.append("lichen_said")
a.append("annual_climber_said")




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


x = intName
while (x < slotName):
	print("int %s = %d;" % (a[x], initialIntValue))
	x = x + 1
	
print("")
print("")


databaseName = 0
intName = int(len(a)/3)
slotName = int(2*len(a)/3)
x = 0

while (x < len(a)/3):
	print("NLGetIntSlotValue(AppGetNLResult(app), \"%s\", &%s);" % (a[slotName], a[intName]))
	print("if (%s == 1) {" % a[intName])
	print("\tprintf(\"%%s\\n\", \"You said %s.\");" % a[databaseName])
	#print("\tplantHabitStringArray[habitCounter] = \"%s\";" % a[databaseName])
	print("\tstrcpy(plantHabitStringArray[habitCounter], \"%s\");" % a[databaseName])
	print("\thabitCounter = habitCounter + 1;")
	print("}")
	databaseName+=1
	intName+=1
	slotName+=1
	x+=1
	

	
	
	
	
	
	
	