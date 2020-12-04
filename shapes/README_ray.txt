Implementation details:
I chose to factor out some of my code into an implicitShape superclass. The main goal was so that I could use static instances of these objects but for some reason I was unable to assign them to a single variable to switch off which shape I was using. 

Known Bugs:
I have slightly jagged edges on most of my surfaces and I thought this might be a floating point problem but was unable to figure it out. 