# Algorithm Study Note: Breadth-First Search (BFS)

## 1. Definition
**Breadth-First Search (BFS)** is a graph traversal algorithm that explores nodes layer by layer. It starts at a source node and visits all its immediate neighbors before moving to the next level neighbors.

* **Data Structure Used:** **Queue** (FIFO).
* **Key Characteristic:** Finds the **shortest path** in an unweighted graph.
* **Analogy:** Ripples in a pond spreading out from where a stone is dropped.



## 2. Algorithm Steps
1.  Push the starting node into the **Queue** and mark it as visited.
2.  While the queue is not empty:
    * **Dequeue** the front node.
    * **Process** the node (e.g., print it).
    * For every unvisited neighbor of this node:
        * Mark it as **visited**.
        * **Enqueue** it.

## 3. Complexity Analysis
* **$V$**: Number of Vertices (Nodes).
* **$E$**: Number of Edges.

| Type | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time** | $O(V + E)$ | Every vertex is enqueued once; every edge is checked once. |
| **Space** | $O(V)$ | In the worst case, the queue might store all vertices at the widest level. |

## 4. C++ Implementation Snippet
```cpp
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // Process node

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
