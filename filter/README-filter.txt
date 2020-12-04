Implementation details:
I chose to have a filter superclass that defines an abstract Apply method and the REAL2byte method so that it's accessible by all the subclasses. I tried to factor out the convolution code into a helper class (like FileUtils) but since the bounds and error conditions and return types of the convolution that I was unable to. 

Known bugs: 
Up until I changed a few error checks, my program would sometimes unpredictably segfault. I wasn't sure what was causing it (the debugger in my QTcreator isn't working) but since I changed some things it hasn't segfaulted in the last 7-8 times I've run it (trying each filter multiple times with different settings). However, since I didn't really fix the bug, the program might segfault on certain values. 