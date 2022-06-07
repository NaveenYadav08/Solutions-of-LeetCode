https://codeforces.com/contest/25/problem/D





Codeforces graph theory problem solving series:

What will you learn from this video editorial?: 

1. How to use DSU data structure to solve graph problems involving multiple connected components of a graph.

2. Why prevention is better than cure in DSU data structure

Problem Link: https://codeforces.com/contest/25/pro...

Solution Link: https://codeforces.com/contest/25/sub...

Solution Sketch: 
 1) Add an edge between nodes from different connected components so that all connected components get merged into a single connected component 
 – this can be done easily using DSU.

2) Remove redundant edges – edges connecting nodes already in the same connecting component.

3) Instead of removing the redundant edges manually just check if the 2 endpoints of the edges are already in the same connected component 
(if they are then don’t add the edge otherwise add the edge).
