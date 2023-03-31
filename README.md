Project 04: Path Finding - Lakelon Bailey - 03/31/2023
========================
# Results:
| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 0.0011s       | 84514          |
| 20            | 0.0014s       | 90544          |
| 50            | 0.0035s       | 122954         |
| 100           | 0.0113s       | 229824         |
| 200           | 0.0439s       | 638564         |
| 500           | 0.2855s       | 3439120        |
| 1000          | 1.2253s       | 13297156       |
|---------------|---------------|----------------|

- The above results can be replicated by running "python run_test.py", as this is a program I wrote and included that develops this table.

# Additional Questions:
1. How did you represent the map as a graph?
    - I represented the map as a 2D grid, with each cell being a vertex in the graph. The connections between the cells (up, down, left, and right) were treated as the edges. The weights of the edges came from the cost of moving from one cell to another, which depended on the tile costs given in the input.

2. Can you explain the graph representation you used and how you figured out the relationships between vertices, edges, and their weights?
    - I didn't use an adjacency matrix since it would require a lot of space (O(N^4)) for large maps. Instead, I implicitly used an adjacency list by checking the valid movement directions and making sure the new position is within the map's boundaries. To find the edge weights, I looked up the cost of the tile at the current position in the tileCosts dictionary.

3. What's the complexity of your Dijkstra's Algorithm implementation?
    - The time complexity is O(V^2), where V is the number of vertices (V = N^2 for an N x N grid). This is because I used a priority queue to find the node with the minimum distance in O(log V) time, and I did this for each vertex. Additionally, I iterated through all the edges, taking O(V) time. So, the overall time complexity is O(V^2).

4. How well does your implementation handle larger maps?
    - My implementation can handle larger maps reasonably well. As the map size (N) increases, the execution time and memory usage grow, but not as fast as N^2. The benchmark results show that the algorithm can work with maps up to 1000 x 1000 in size without too many issues.

# Individual Contributions:
 - I worked alone on this project, so I am responsible for all contributions