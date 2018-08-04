# AINT_nuance

Here lies the final workspace for the talking plant finder (developed for the AINT512 module). Written using visual studio in C.
The program connects to a SQL database of plants (hosted locally). The database is available from https://pfaf.org.
Using an old version of the Nuance speech interface API and the MySQL C API, the program is able to engage a user in a dialogue with the objective of helping them find a plant for their garden. There are over 3000 plants currently linked into the conversational agent.

Code in the master branch allows users to search via growing conditions. Code in other branches also allows search via medicinal use or as food replacements. 




### What does it do?
Example conversation:

System: 
>“How can I help?”

The user can begin entering search criteria, or can ask for help.

User:
>“Do you have any suggestions?”

System:
>“Why not try searching for where the plant will grow, such as **East Wall**, or **Cultivated Beds**. Or you could try searching by type of plant, like **Bulb**, **Bamboo** or **Biennial**. You can also specify how hardy you want the plant to be.” 

(Words in bold are randomly pulled from the database each time the user asks for suggestions)

User:
>“Okay, can you help me find an extremely hardy tree to grow against a shady edge?”

The program will then extract the key words from the users speech and construct an SQL query. Here is the query the system generates if the above conversation is followed:

```SQL
SELECT `Common name`,`Latin name` FROM `plantlocations` WHERE `Habit`='Tree' AND `ShadyEdge`=1 AND `Hardyness` BETWEEN 9 AND 10
```

Error checking and other validation are performed here (see error handling / catching section of the report for more information). Once error checking has been completed:

>“Okay, here are your results. Common name and then Latin name:

>Puahou    -    Pseudopanax arboreus “

>“Would you like more information on this plant?”

If the user says yes, the program will retrieve more information on the chosen plant from the database and present this to the user.



Here's a conversational flowchart describing the programs current capabilities:
![alt text](https://github.com/carebare47/AINT512_talking_plant_finder/blob/master/Conversational%20Flowchart.png)
