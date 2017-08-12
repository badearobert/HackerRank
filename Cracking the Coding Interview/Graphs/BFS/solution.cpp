#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

const int EDGE_DISTANCE = 6;
const vector<int> EmptyVec;

class Graph 
{
    public:

        Graph(int n) 
        {
            mVecSize = n;
            for (int i = 0 ; i < mVecSize; ++i) 
            {
                mNodes[i] = EmptyVec;
            }
        }
    
        void add_edge(int u, int v) 
        {
            mNodes[u].push_back(v);
            mNodes[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) 
        {
            // create vec of distances with -1 at start
            vector<int> distances;
            for (int i = 0; i < mVecSize; ++i) 
            {
                distances.push_back(-1);
            }
            
            // distance to itself is always 0
            distances[start] = 0;
            
            // add the current element in queue
            queue<int> IterationQueue;    
            IterationQueue.push(start);
            
            while (false == IterationQueue.empty() ) 
            {
                // get next element
                const int& currentNode = IterationQueue.front();

                // iterate through neighbours and set their distance
                for (const int & closestNeighbor : mNodes[currentNode] )
                {
                    // if it wasn't visited...
                    if (distances[closestNeighbor] == -1) 
                    {
                        distances[closestNeighbor] = distances[currentNode] + EDGE_DISTANCE;
                        IterationQueue.push(closestNeighbor);
                    }
                }

                IterationQueue.pop();
            }
            
            return distances;
            
        }
    
    int mVecSize;
    map< int, vector<int> > mNodes;
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
