Why do we sort on the basis of end points, not on start points.
​
suppose you have cases like : (1,8), (2,3), (3,4), (5,9)
if you sort in the basis of start points you will end up considering (1,8) and deleting rest which collide with (1,8).
For a greedy approach you will want the point with lower end point to be considered.
But, We can sort on the basis of start point also, just a little tweak in the algorithm will work out that way. In case of overlap, remove the interval having the farther end point.