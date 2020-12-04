Implementation Details:
Recursion depth can be specified by changing the variable DEPTH defined in Canvas2D.cpp.
My ray implementation builds on the code I wrote for intersect. I factored some of it out into helper functions so that 
I could write the recursive rayTrace function more easily. I implemented the lighting equation referenced in the handout. 

Known Bugs:
I don't think I have any major bugs but my raytracer does run pretty slowly. 
I think this is a carried over problem from my intersect because even when I 
toggle all the functionality associated with ray off (texture mapping, reflection
etc.) the ray tracer takes about 2-4 minutes for complex scenes like recursiveCones
and chess. I made sure to pass vectors by const reference and tried to avoid recomputing 
values but I'm not sure what is making it so slow. 
