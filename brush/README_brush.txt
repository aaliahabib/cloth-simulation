Implementation details:
I chose to have my smudge brush inherit from the quadratic brush so that the mask defaulted to the quadratic mask. I implemented the brush dragged function in the brush superclass because it was the same for all subclasses except smudge brush (in which case I overrode it).
For temporary management of the buffer for smudge I used a vector of RGBAs as a member variable of the smudgebrush class and overwrote its contents in pick up paint. 

Known bugs: 
None that I know of!
