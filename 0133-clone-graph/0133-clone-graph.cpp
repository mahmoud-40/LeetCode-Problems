/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_map<Node*, Node*> copies;
        dfs(node, copies);
        return copies[node];
    }
    
private:
    void dfs(Node* node, unordered_map<Node*, Node*>& copies) {
        if (copies.count(node)) return;
        
        Node* copy = new Node(node->val);
        copies[node] = copy;
        
        for (Node* neighbor : node->neighbors) {
            dfs(neighbor, copies);
            copy->neighbors.push_back(copies[neighbor]);
        }
    }
};