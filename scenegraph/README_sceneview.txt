Implementation details:
I chose to flatten the tree into a list of "MyPrimitive" structs. This struct contains information about the primitive type, the primitive itself, the material and the cumulative matrix. I develop the cumulative matrix while passing by passing an identity matrix through all of the transformations and then multiplying that by the matrix that was developed at the last iteration of the recursive dfs.


Known bugs:
None!