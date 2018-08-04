a = []
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

appgoto = "env2"
counter2 = int(2*len(a)/3)

x = 1
while(x < 2*len(a)/3):
	print("(%s) %*s  \t {<%s 1>}" % (a[x-1], 7, "", a[x]))
	x = x + 2

print("")
print("")
print("")

x = 1
while(x < 2*len(a)/3):
	print("%s" % a[x])
	x = x + 2

#If you don't want to change the strings, then you could simply do

####const char *a[8];
#a[0] = "blah";
#a[1] = "hmm";


#plantlocations:
