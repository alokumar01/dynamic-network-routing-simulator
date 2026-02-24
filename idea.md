🌐 Network Latency Optimization System
Using Dijkstra’s Algorithm

1️⃣ Introduction

This project focuses on designing a Dynamic Network Routing Optimization System that computes the shortest (minimum latency) path between servers using Dijkstra’s Algorithm.

The system models computer networks as weighted graphs and dynamically adapts to changing network conditions such as congestion or link failure.

2️⃣ Rationale for Model Refinement
Why the Traffic Model Was Academically Weak

The initial approach modeled traffic optimization. However, this model presented several academic limitations:

Traffic data tends to be artificial or simulated.

Real-time traffic modeling requires complex real-world validation.

Real city scenarios introduce unnecessary realism constraints.

Traffic is unpredictable and difficult to formalize mathematically.

Algorithmically, traffic simply represents changing weights in a graph.

Therefore, the traffic model was:

Story-driven

Scenario-heavy

Algorithm-light

This reduced the mathematical depth of the project.

3️⃣ Why the Network Latency Model is Stronger

The refined model represents:

Nodes → Servers

Edges → Network links

Weights → Latency (milliseconds)

Objective

Minimize total transmission delay between two servers.

This formulation results in a pure graph optimization problem without narrative complexity.

It directly aligns with classical computer science principles.

4️⃣ Real-World Relevance

This model accurately reflects real internet routing systems:

Routers act as nodes

Physical or virtual links act as edges

Transmission delay represents edge weight

Modern routing protocols compute shortest paths.

For example:

OSPF (Open Shortest Path First) uses Dijkstra’s algorithm internally.

Thus, the system simulates how routing protocols determine optimal data transmission paths in computer networks.

5️⃣ Mathematical Model

We represent the network as a:

Weighted Undirected Graph
𝐺
=
(
𝑉
,
𝐸
)
G=(V,E)

Where:

V = Set of servers (vertices)

E = Set of network links (edges)

W(u, v) = Latency weight between nodes

Optimization Objective

Minimize:

∑
𝑊
(
𝑢
,
𝑣
)
∑W(u,v)

Along the path from a source node to a destination node.

This is the Single Source Shortest Path Problem.

6️⃣ Algorithm Selection: Why Dijkstra?

Dijkstra’s algorithm is appropriate because:

Latency values are always non-negative.

Network delays cannot be negative.

The graph may be sparse.

Efficient routing is required for large systems.

Time Complexity
𝑂
(
(
𝑉
+
𝐸
)
log
⁡
𝑉
)
O((V+E)logV)

This makes it scalable for large-scale networks.

7️⃣ Dynamic Behavior in the System

The term dynamic refers to simulated changes in the network, such as:

Cable congestion

Link failure

Bandwidth throttling

Hardware degradation

When such changes occur:

Edge weights increase.

Dijkstra’s algorithm is re-executed.

A new optimal path is computed.

This mirrors real-world dynamic routing mechanisms.

8️⃣ Problem Definition

The system solves:

Dynamic Single Source Shortest Path Problem with Weight Updates

This is a strong and well-defined Data Structures and Algorithms (DSA) concept.

9️⃣ Academic Justification for Refinement

When presenting the project refinement:

“Initially, the system was modeled as traffic optimization. However, traffic modeling introduces unpredictable real-world complexity and reduces algorithmic clarity. The model was refined to simulate network routing, which directly represents shortest path computation used in routing protocols such as OSPF. This makes the system more mathematically grounded and algorithm-focused.”

This demonstrates academic maturity and technical reasoning.

10️⃣ Model Comparison
Traffic Model	Network Model
Scenario-driven	Algorithm-driven
Real-world unpredictable	Mathematically structured
Hard to validate	Industry standard
Narrative-heavy	Computation-focused

The network model is cleaner and academically stronger.

11️⃣ Final Project Title

Dynamic Network Routing Optimization System using Dijkstra’s Algorithm

12️⃣ System Features

Construct a network graph

Compute shortest latency path between servers

Simulate dynamic link weight changes

Recalculate optimal routes

Compare previous vs updated latency

13️⃣ Example Demonstration
Initial Network
0 --10-- 1
|        |
5        2
|        |
2 --3--- 3
Step 1: Compute Shortest Path

Source: 0
Destination: 3

Output:

0 → 2 → 3
Total Latency: 8 ms
Step 2: Simulate Network Change

Update link (2,3) latency from 3 ms to 20 ms.

Step 3: Recompute Shortest Path

New Output:

0 → 1 → 3
Total Latency: 12 ms

The system dynamically adapts to changing network conditions.

14️⃣ Conclusion

This project builds a:

Graph-based network model

Dynamic weight update simulation

Dijkstra-based routing computation system

It represents a clean, mathematically grounded, and industry-relevant implementation of shortest path optimization in computer networks.