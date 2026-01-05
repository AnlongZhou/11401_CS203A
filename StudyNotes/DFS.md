# Algorithm Study Note: Depth-First Search (DFS)

## 1. Definition
**Depth-First Search (DFS)** is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It goes "deep" into the graph structure.

* **Data Structure Used:** **Stack** (LIFO) or **Recursion** (Call Stack).
* **Key Characteristic:** Good for topological sorting, detecting cycles, and solving maze puzzles.
* **Analogy:** Solving a maze by following one wall until you hit a dead end, then backtracking.



## 2. Algorithm Steps (Recursive)
1.  Mark the current node as **visited**.
2.  **Process** the node (e.g., print it).
3.  For every unvisited neighbor of the current node:
    * Recursively call DFS on that neighbor.

## 3. Complexity Analysis
* **$V$**: Number of Vertices (Nodes).
* **$E$**: Number of Edges.

| Type | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time** | $O(V + E)$ | Every vertex is visited once; every edge is traversed once. |
| **Space** | $O(V)$ | Worst case is $O(V)$ for the recursion stack (e.g., a long linked list graph). |

## 4. C++ Implementation Snippet
```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " "; // Process node

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
