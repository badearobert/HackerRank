#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

class Graph 
{
    public:
        class Node 
        {
            public:
            Node(int _data) : data(_data) { }
            void addEdge(int data) 
            { 
                connections.emplace_back(Node(data)); 
            }
            const vector<Node>& getConnections() { return connections; }
            int getData() const { return data; }
            //private:
            int data;
            vector<Node> connections;
        };

        Graph(int n)
        {
            mVecSize = n;
            for (int i = 0 ; i < mVecSize; ++i) 
            {
                mNodes.emplace_back( Node( i ) );
            }
        }
    
        void add_edge(int u, int v) 
        {
            mNodes[u].addEdge(v);
            mNodes[v].addEdge(u);
            addToCache(u, v);
            addToCache(v, u);
        }

        void addToCache(int start, int end, int distance = 6) 
        {
            string key = cacheData(start, end);
            distances[key] = distance;
        }

        bool isInCache(int start, int end) 
        {
            string key = cacheData(start, end);
            return ( distances.find(key) != distances.end() );
        }

        int getDistanceFromCache(int start, int end)
        {
            string key = cacheData(start, end);
            return distances[key];
        }
    
        vector<int> shortest_reach(int start)
        {
            vector< int > results;
            set<int> visitedNodes;
            for (int end = 0 ; end < mVecSize; ++end) 
            {
                int result = BFS(start, end, visitedNodes);
                results.push_back(result);
            }
            return results;
        }
    
    int BFS(int start, int end, set<int> &visitedNodes, int recursiveStep = 1) 
    {
        if (start == end) 
        {
            return -1;
        }
        if (isInCache(start, end)) 
        {
            return getDistanceFromCache(start,end);
        }

        // not found, need to calculate
        const vector<Node> & connections = mNodes[start].getConnections();
        for (int index = 0; index < connections.size(); index++) 
        {
            const Node& node = connections[index];
            int nodeData = node.getData();
            if (visitedNodes.find(nodeData) != visitedNodes.end())
            {
                visitedNodes.insert(nodeData);
                if (isInCache(nodeData, end)) 
                {
                    return getDistanceFromCache(nodeData, end);
                }
                int distance = BFS(nodeData, end, visitedNodes, recursiveStep + 1);
                addToCache(nodeData, end, distance * recursiveStep);
                return distance;
            }
        }
        addToCache(start, end, -1);
        return -1;
        
    }
    string cacheData(int start, int end) 
    {
        return to_string(start) + "-" + to_string(end);
    }

    private:
    int mVecSize;
    vector<Node> mNodes;
    unordered_map<string, int> distances;
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
