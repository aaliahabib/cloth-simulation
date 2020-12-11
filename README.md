# Cloth Simulation

For our CS123 Final Project, we made a simulation of a cloth falling. Our simulation supports collision with a sphere, a hole, and the ground. It also supports wind. 

Our GUI has parameters to modify: 
* tessellation
* constraint (number of particles a particle is acted upon by).
* texture image
* wind
* clipping (clip one or two of the cloth's corners in place)
* sphere, hole, or neither

Every time a parameter is modified, the simulation automatically restarts. 

![6](https://github.com/ahabib3/graphics-fp/blob/main/README/6.png)
![5](https://github.com/ahabib3/graphics-fp/blob/main/README/5.png)
![7](https://github.com/ahabib3/graphics-fp/blob/main/README/7.png)
![1](https://github.com/ahabib3/graphics-fp/blob/main/README/1.png)
![2](https://github.com/ahabib3/graphics-fp/blob/main/README/2.png)
![3](https://github.com/ahabib3/graphics-fp/blob/main/README/3.png)
![4](https://github.com/ahabib3/graphics-fp/blob/main/README/4.png)

Implementation: 
We followed the Mosegaard's tutorial on cloth simulation to parameterize the mass and spring model for the cloth. We set constraints for each particle by binding it to a number of it's neighbors (how many is determined by the second parameter in the GUI). We satisfy the constraints by storing the rest distance between two bound particles and moving them closer to each other by a factor (1-rest_distance/current_distance). 
At every timestep we compute the constraint satisfaction multiple times - the number of times that code is executed correlates to how rigid the cloth appears. 

Known bugs:
We have a few visual bugs that we have been unable to debug. 
The first one is that highly tessellated cloth stretches significantly when clipped at the corners. Particles near the clipped particles appear to move much farther away but within the satisfyConstraints function their distance doesn't appear to be too large. 
Our second bug is that when the cloth lands on the floor, it always unravels itself to be completely flat. This is because the complete rest state of the cloth (where it would no longer change the positions of the particles) is when the cloth is completely flat. We attempted to counter this by setting the particles to be unmovable when they intersected the floor but this affected the way it folded as it was falling and didn't look very good. 
Our last bug is that, when the radius of the hole is small, the cloth does not fall through. We attempted to address this by adding the notion of mass to the particles and came up with a way to exert an extra downward force on the cloth but it didn't end up looking very good so we just let it be. 


Resources:
We primarily referenced the Mosegaard's tutorial: https://viscomp.alexandra.dk/?p=147 and also looked at the Baraff and Witkin papers: https://www.cs.cmu.edu/~baraff/sigcourse/

