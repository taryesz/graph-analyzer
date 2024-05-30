# Graph Analyzer

This project helps its users to investigate different properties of a desirable graph.

## Examplementary Usage

First of all, decide on how many graphs you are going to analyze. Right after you think of a number, type it in.

Secondly, give the program some information about a graph, i.e. how many vertices it's going to have.

Then, it's time to provide vertices: each line that you are going to fill with data is tied to a specific vertex [ *meaning that the n-th line is the n-th vertex's parameteres* ]. Start the line with a number of connections [ *adjacency* ] this vertex has and then type all the vertices' indices that this vertex is connected to.

Repeat the process as many times as there are graphs and their vertices.

### First Example

Let's say you have this graph in mind:

It is represented the following way:

> 1

> 6

> 4 2 3 4 5

> 2 1 5

> 1 1

> 1 1

> 2 1 2

> 0 `This vertex doesn't have any neighbors`

`Note:` after each step you have to press `Enter`

_**First input:**_ `How many graphs?`

> 1

_**Second input:**_ `How many vertices in the graph?`

> 6

_**Third input:**_ `Type in current vertex's properties`

> 4 2 3 4 5

`4` is a number of connections this vertex has
The following _4_ numbers `2 3 4 5` are the indices of vertices this vertex is connected to.

_**Repeat until finished with all 6 vertices**_

_**Output:**_

> 4 2 2 1 1 0 `Degree sequence`

> 2 `Connectivity number`

> F `Is bipartite`

> 1 2 2 2 3 1 `Coloring [ greedy ]`

> 1 2 2 2 3 1 `Coloring [ largest first ]`

> 10 `Number of edges needed to complete the graph`

The program always check all these 6 properties for you and always prints the results in this order.

## Running Tests

This repository contains a folder called "tests" where you can find 4 different `.in` files with various inputs, as well as conrresponding `.out` files with the correct outputs.