#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"


class NetworkSystem {
private:
    int n;
    vector<vector<pair<int,int>>> adj;

    // For route comparison
    vector<int> lastDistance;
    vector<int> lastParent;
    int lastSource = -1;

public:
    NetworkSystem(int nodes) {
        n = nodes;
        adj.resize(n);
        srand(time(0));
    }

    void addLink(int u, int v, int latency) {
        adj[u].push_back({v, latency});
        adj[v].push_back({u, latency});
    }

    // ================= ASCII NETWORK =================
    void displayAsciiNetwork() {
        cout << "\n" << BOLD << CYAN;
        cout << "=========== NETWORK TOPOLOGY ===========\n";
        cout << RESET << endl;

        for(int u = 0; u < n; u++) {
            for(auto &edge : adj[u]) {
                int v = edge.first;
                int latency = edge.second;

                if(u < v) {
                    cout << BLUE << "[" << u << "] "
                        << "==== "
                        << latency
                        << " ms ==== "
                        << "[" << v << "]"
                        << RESET << "\n";
                }
            }
        }

        cout << "\n---------------------------------------------\n";
    }


    // ================= DIJKSTRA =================
    pair<vector<int>, vector<int>> dijkstra(int source) {
        vector<int> distance(n, INT_MAX);
        vector<int> parent(n, -1);

        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        distance[source] = 0;
        pq.push({0, source});

        while(!pq.empty()) {
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(currDist > distance[u]) continue;

            for(auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if(distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }

        return {distance, parent};
    }

    void printPathFormatted(int dest, vector<int> &parent) {
        vector<int> path;

        while(dest != -1) {
            path.push_back(dest);
            dest = parent[dest];
        }

        reverse(path.begin(), path.end());

        for(size_t i = 0; i < path.size(); i++) {
            cout << "[" << path[i] << "]";
            if(i != path.size() - 1)
                cout << " --> ";
        }
    }


    // ================= UPDATE LATENCY =================
    void updateLatency(int u, int v, int newLatency) {
        bool found = false;

        for(auto &edge : adj[u]) {
            if(edge.first == v) {
                edge.second = newLatency;
                found = true;
                break;
            }
        }

        for(auto &edge : adj[v]) {
            if(edge.first == u) {
                edge.second = newLatency;
                break;
            }
        }

        if(found)
            cout << "Link latency updated successfully.\n";
        else
            cout << "Link not found.\n";
    }

    // ================= RANDOM CONGESTION =================
    void simulateRandomCongestion() {
        cout << MAGENTA << BOLD;
        cout << "\n>> NETWORK DISTURBANCE SIMULATION INITIATED...\n";
        cout << RESET;


        int changes = rand() % n + 1;

        for(int i = 0; i < changes; i++) {
            int u = rand() % n;

            if(adj[u].empty()) continue;

            int idx = rand() % adj[u].size();
            int v = adj[u][idx].first;

            int increase = rand() % 20 + 5;

            adj[u][idx].second += increase;

            for(auto &edge : adj[v]) {
                if(edge.first == u) {
                    edge.second += increase;
                    break;
                }
            }

            

            cout << MAGENTA
                << "Latency spike between "
                << u << " and " << v
                << " (+" << increase << " ms)\n"
                << RESET;

        }

        cout << "Congestion simulation complete.\n";
    }

    // ================= ROUTE FINDER =================
    void findRoute() {
        int source, destination;

        cout << "Enter source server: ";
        cin >> source;
        cout << "Enter destination server: ";
        cin >> destination;

        if(source < 0 || source >= n || destination < 0 || destination >= n) {
            cout << "Invalid server index!\n";
            return;
        }

        auto result = dijkstra(source);
        vector<int> distance = result.first;
        vector<int> parent = result.second;

        if(distance[destination] == INT_MAX) {
            cout << "No route exists.\n";
            return;
        }

        cout << "\n" << BOLD << YELLOW;
        cout << "---------------------------------------------\n";
        cout << "              ROUTE ANALYSIS\n";
        cout << "---------------------------------------------\n";
        cout << RESET;

        cout << "Source Server      : " << source << "\n";
        cout << "Destination Server : " << destination << "\n\n";

        cout << GREEN << "Optimal Path       : " << RESET;
        printPathFormatted(destination, parent);
        cout << "\n";

        if(distance[destination] < 50)
            cout << GREEN;
        else
            cout << RED;

        cout << "Total Latency      : "
            << distance[destination] << " ms\n";

        cout << RESET;
        cout << "---------------------------------------------\n";


        // Compare with last result
        if(lastSource == source && !lastDistance.empty()) {
            int oldLatency = lastDistance[destination];

            if(oldLatency != INT_MAX) {
                cout << "\nPrevious Latency: " << oldLatency << " ms\n";
                cout << "Latency Change: "
                     << (distance[destination] - oldLatency)
                     << " ms\n";
            }
        }

        lastDistance = distance;
        lastParent = parent;
        lastSource = source;
    }

    // ================= MENU =================
    void menu() {
        while(true) {
            cout << "\n===== NETWORK ROUTING OPTIMIZATION MENU =====\n";
            cout << "1. Find Fastest Data Route\n";
            cout << "2. Update Link Latency\n";
            cout << "3. Simulate Link Failure\n";
            cout << "4. Simulate Random Congestion\n";
            cout << "5. Display ASCII Network\n";
            cout << "6. Exit\n";
            cout << "Choose option: ";

            int choice;
            cin >> choice;

            switch(choice) {
                case 1:
                    findRoute();
                    break;

                case 2: {
                    int u, v, newLatency;
                    cout << "Enter link (u v) and new latency (ms): ";
                    cin >> u >> v >> newLatency;

                    if(u < 0 || u >= n || v < 0 || v >= n || newLatency < 0) {
                        cout << "Invalid input!\n";
                        break;
                    }

                    updateLatency(u, v, newLatency);
                    break;
                }

                case 3: {
                    int u, v;
                    cout << "Enter link (u v) to simulate failure: ";
                    cin >> u >> v;

                    if(u < 0 || u >= n || v < 0 || v >= n) {
                        cout << "Invalid input!\n";
                        break;
                    }

                    updateLatency(u, v, INT_MAX/2);
                    cout << RED << BOLD;
                    cout << "!!! CRITICAL ALERT: LINK FAILURE DETECTED !!!\n";
                    cout << RESET;
                    break;
                }

                case 4:
                    simulateRandomCongestion();
                    break;

                case 5:
                    displayAsciiNetwork();
                    break;

                case 6:
                    cout << "Exiting Network System...\n";
                    return;

                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
};

void loadDemoNetwork(NetworkSystem &network) {
    cout << GREEN << BOLD;
    cout << "\n>> Generating Dynamic Latency Profile...\n";
    cout << RESET;

    vector<pair<int,int>> demoLinks = {
        {0,1},
        {0,2},
        {1,3},
        {2,3},
        {3,4},
        {4,5},
        {1,4},
    };

    for(auto &link : demoLinks) {
        int latency = rand() % 10 + 5; // 10–99 ms
        network.addLink(link.first, link.second, latency);
    }

    cout << GREEN << "Demo Network Loaded Successfully.\n" << RESET;
}

int main() {
    srand(time(0));

    cout << BOLD << CYAN;
    cout << "=====================================================\n";
    cout << "        NETWORK CONTROL CENTER v1.0\n";
    cout << "      Dynamic Routing Simulation Engine\n";
    cout << "=====================================================\n";
    cout << RESET << endl;

    cout << BOLD << YELLOW;
    cout << "Select Network Mode:\n";
    cout << RESET;
    cout << "1. Load Demo Network (8 Servers, Random Latency)\n";
    cout << "2. Create Custom Network\n";
    cout << "Choose option: ";

    int mode;
    cin >> mode;

    NetworkSystem network( (mode == 1) ? 6 : 0 );

    if(mode == 1) {
        network = NetworkSystem(8);
        loadDemoNetwork(network);
        network.displayAsciiNetwork();
    }
    else if(mode == 2) {
        int n, m;

        cout << "Enter number of servers: ";
        cin >> n;

        cout << "Enter number of network links: ";
        cin >> m;

        if(n <= 0 || m < 0) {
            cout << RED << "Invalid input.\n" << RESET;
            return 1;
        }

        network = NetworkSystem(n);

        cout << "Enter links (u v latency_in_ms):\n";
        for(int i = 0; i < m; i++) {
            int u, v, latency;
            cin >> u >> v >> latency;

            if(u < 0 || u >= n || v < 0 || v >= n || latency < 0) {
                cout << RED << "Invalid link.\n" << RESET;
                return 1;
            }

            network.addLink(u, v, latency);
        }
    }
    else {
        cout << RED << "Invalid selection.\n" << RESET;
        return 1;
    }

    network.menu();

    return 0;
}
