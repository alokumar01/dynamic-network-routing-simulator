[![C++ Build](https://github.com/alokumar01/dynamic-network-routing-simulator/actions/workflows/c-cpp.yml/badge.svg?branch=main)](https://github.com/alokumar01/dynamic-network-routing-simulator/actions)
# 🌐 Dynamic Network Routing Simulator
### (Dijkstra-Based Optimization Engine)

A simulation-based C++ project that models dynamic routing behavior in computer networks using **Dijkstra’s Shortest Path Algorithm**.

This system simulates adaptive routing under changing network conditions such as congestion spikes and link failures.

---

## 🚀 Features

- Weighted undirected graph representation (Adjacency List)
- Dijkstra’s Algorithm using Min-Heap (Priority Queue)
- Dynamic latency updates
- Random congestion simulation
- Link failure modeling
- Route comparison engine
- ASCII-based network visualization
- Demo mode (auto-generated network)
- Custom user-defined network mode
- Colored terminal UI (Cyber-themed)

---

## 🧠 Core Concepts Used

- Graph Theory
- Greedy Algorithms
- Priority Queue (Min-Heap)
- Object-Oriented Programming (OOP)
- Dynamic Simulation Modeling

---

## ▶️ How to Run

Compile:
g++ main.cpp -std=c++17 -o network_simulator

Run:
./network_simulator

## ⚙️ Algorithm Details

**Dijkstra’s Algorithm**

Time Complexity: O((V + E) log V)

Space Complexity: O(V + E)


Works for non-negative weighted graphs.

---

## 🖥 Demo Mode

The system includes a predefined 8-server network topology with randomly generated latency values (10–99 ms) to simulate dynamic routing conditions.

---

## 📌 Example Output
Optimal Path: [0] --> [2] --> [6] --> [7]
Total Latency: 42 ms


---

## 🛠 Technologies Used

- C++
- STL (vector, priority_queue)
- ANSI Terminal Styling

---

## 📚 Academic Context

Developed as part of Data Structures and Algorithms coursework to demonstrate practical application of shortest path algorithms in network routing systems.

---

## 🔮 Future Enhancements

- GUI-based visualization
- Directed graph support
- A* Algorithm integration
- Multi-path routing simulation
- Network heatmap analysis

---

## 👨‍💻 Author

Alok Kumar  
Portfolio - https://whoisalok.tech
