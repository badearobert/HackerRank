#include <map>
#include <iostream>

using namespace std;

constexpr int NUMBER_OF_CHARACTERS = 26;

struct Node {
    int mSize = 0;
    map<char, Node*> mSet;
    
    Node* getNode(char c) { return mSet[c]; }
    void setNode(char c, Node* node) { mSet[c] = node; }
    
    
    void addElement(string id, int index) 
    { 
        mSize++;
        if (id.size() == index) return;
        
        char currentChar = id[index];
        Node* currentNode = getNode(currentChar);
        if (currentNode == nullptr) {
            currentNode = new Node;
            setNode(currentChar, currentNode);
        }
        currentNode->addElement(id, index + 1);   
    } 
    
    int findPartial(string id, int index) 
    {
        if (id.size() == index) return mSize;
        
        Node* currentNode = getNode( id[index] );
        if (currentNode == nullptr) return 0;

        return currentNode->findPartial(id, index + 1);
    }
    
};

struct Trie {
    
    Node mNode;
    
    void addElement(string id) 
    {
        mNode.addElement(id, 0);
    }
 
    void findPartial(string id) 
    {
        int count = mNode.findPartial(id, 0);
        cout << count << endl;
    }

    void executeAction(string action, string id) {
        if (action == "add") {
            addElement(id);
        } else if (action == "find") {
            findPartial(id);
        }
    }
};


int main(){
    Trie t;
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        t.executeAction(op,contact);
    }
    
    return 0;
}
