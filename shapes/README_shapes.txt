Implementation details:
The larger design choices I made pertained to the structure of inheritance for my cone and cylinder shapes in particular. I chose to write a shared method that determines the vertex coordinates and normals given a "row" and "col" value. I thought about all the tessellations in the form of a flat grid of squares (each containing two triangles) that had corresponding row and col values. I also chose to precompute the sines and cosines for the cone and cylinder so as to not have to recompute them for every vertex. 
For the cube I tessellated one face manually and then used gl matrix manipulation to determine the vertices of the other faces. 

Known Bugs: 
None, really. 
I was trying to figure out how to handle parameter changes better in the settings changed function but I think a lack of understanding of how exactly the rendering pipeline is set up resulted in duplicate/odd drawings if I didn't just reassign the pointer every time settings changed. I think that while this is slightly inefficient (because the shape has to be destroyed and recreated every time) it's not that bad because the majority of the shape (the vertex data) would have to be reassigned anyway. 


