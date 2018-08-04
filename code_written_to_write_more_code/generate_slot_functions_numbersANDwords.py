a = []
#database lookup name
a.append("canopy")
a.append("canopy_said")
a.append("common name")
a.append("common_name_said")
a.append("cultivar")
a.append("cultivar_said")
a.append("cultivated beds")
a.append("cultivatedbeds_said")
a.append("dappled shade")
a.append("dappledshade_said")
a.append("deep shade")
a.append("deepshade_said")
a.append("east wall")
a.append("eastwall_said")
a.append("ground cover")
a.append("groundcover_said")
a.append("habit")
a.append("habit_said")
a.append("habitat")
a.append("habitat_said")
a.append("hardiness")
a.append("hardyness_said")
a.append("hedge")
a.append("hedge_said")
a.append("hedgerow")
a.append("hedgerow_said")
a.append("height")
a.append("height_said")
a.append("latin name")
a.append("latin_name_said")
a.append("lawn")
a.append("lawn_said")
a.append("meadow")
a.append("meadow_said")
a.append("north wall")
a.append("northwall_said")
a.append("other habitats")
a.append("otherhabitats_said")
a.append("pond")
a.append("pond_said")
a.append("secondary")
a.append("secondary_said")
a.append("shade")
a.append("shade_said")
a.append("shady edge")
a.append("shadyedge_said")
a.append("south wall")
a.append("southwall_said")
a.append("sunny edge")
a.append("sunnyedge_said")
a.append("walls")
a.append("walls_said")
a.append("west wall")
a.append("westwall_said")
a.append("width")
a.append("width_said")
a.append("woodland garden")
a.append("woodlandgarden_said")

a.append("Canopy")
a.append("Common name")
a.append("Cultivar")
a.append("CultivatedBeds")
a.append("DappledShade")
a.append("DeepShade")
a.append("EastWall")
a.append("GroundCover")
a.append("Habit")
a.append("Habitat")
a.append("Hardyness")
a.append("Hedge")
a.append("Hedgerow")
a.append("Height")
a.append("Latin name")
a.append("Lawn")
a.append("Meadow")
a.append("NorthWall")
a.append("OtherHabitats")
a.append("Pond")
a.append("Secondary")
a.append("Shade")
a.append("ShadyEdge")
a.append("SouthWall")
a.append("SunnyEdge")
a.append("Walls")
a.append("WestWall")
a.append("Width")
a.append("WoodlandGarden")



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
	print("NLGetIntSlotValue(AppGetNLResult(app), \"%s\", &%s);" % (a[x], a[x]))
	print("if (%s == 1) {" % a[x])
	print("\tprintf(\"%%s\\n\", \"You said %s.\");" % a[x])
	print("\tnumberStringArray[numberCounter] = %s;" % a[x+int(len(a)/2)])
	print("\tnumberCounter = numberCounter + 1;")
	print("}")
	x+=1
	
#	NLGetIntSlotValue(AppGetNLResult(app), "canopy_said", &twenty);
#	if (canopy = 1) {
#		printf("%s\n", "You said canopy.");
#		errorEnvStringArray[errorEnvStringCounter] = "canopy";
#		errorEnvStringCounter = errorEnvStringCounter + 1;
#	}




	
	