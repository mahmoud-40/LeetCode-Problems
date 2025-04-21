class LRUCache {
private:
    // Head (Dummy) ↔ Node1 ↔ Node2 ↔ ... ↔ Tail (Dummy)
    struct Node{
        int key, value;
        Node *next, *prev;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node){ // add to head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) 
            return -1;
        
        Node* node = cache[key];
        removeNode(node);
        addNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addNode(node);
        } else {
            if (cache.size() >= capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */