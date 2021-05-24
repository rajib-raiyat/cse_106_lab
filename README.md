# Project Report

### What is Graph?

A graph G = (V, E) consists of V, a nonempty set of vertices (or nodes) and E, a set of edges. Each edge has either one
or two vertices associated with it, called its endpoints. An edge is said to connect its end points.

### What is Degree?

The degree of a vertex in an undirected graph is the number of edges incident with it, except that a loop at a vertex
contributes twice to the degree of that vertex. The degree of the vertex v is denoted by deg(v).

### What are Edges?

When there is an edge of a graph associated to {u, v}, we can say that {u, v} is an edge of the graph.

### Time Complexity

```text
1. for i = 1 to n, n steps
2. for j =1 to n, n steps

So, f(n) = n(n+1)
=> n.2n
=> 2n^2

Let, f(n)   = c.g(n)
= 2n^2 <= 3n^3

Here,  C = 3, g(n) = n^3

Time complexity of function f(n) is 0(n^3)

f(x) = f(x^2+1)
f(x) = c.g(x)

x^2+1 => x^2 + x ^2
x^2x^2+1 => 2x^2
C = 2 & g(x) = x^2

Time complexity is 0(x^2).
```

Graph
