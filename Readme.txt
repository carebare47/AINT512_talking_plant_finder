
How to compile APP1.C
-----------------------

- double click on app1.dsw 
- This will start your latest version of visual studio
	- accept the "upgrade"

- edit properties, accessible e.g. by right clicking on the app1 icon below the "solution icon" in the "Solution Explorer" pane.
	- in C/C++, additional include directory, add "C:\nuance85\v8.5.0\include"* (do not select "inherit from parent....")
	- linker, additional linker libraries, add  "C:\nuance85\v8.5.0\lib\win32"*

- if you use Visual Studio 2013 (also called Version 12)
	in linker, advanced, say NO to "Image has safe exception handling"


- click on build.
 
To run the application
---------------------

- click on  startapp.bat (this will make sure that the command line parameters are given and the nuance environment variables are set)


Note:
- just clicking on app1.exe will cause errors. 
- The same errors will occur if running in debug mode. In this case, you need to make sure that all the command lines parameters are passed to the debug version) 


*or whatever folder where nuance is installed