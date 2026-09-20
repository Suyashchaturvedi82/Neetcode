#include <unordered_map>

class Node {
public:
int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    std::unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    // Remove a node from its current position in the linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert a node right before the right dummy node (Most Recently Used position)
    void insertNode(Node* node) {
        Node* prevNode = right->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        // Dummy nodes to avoid edge cases when adding/removing
        left = new Node(0, 0);  // Left represents LRU
        right = new Node(0, 0); // Right represents MRU
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            removeNode(node); // Remove from current spot
            insertNode(node); // Move to MRU spot
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // If key exists, remove the old node
        if (cache.find(key) != cache.end()) {
            removeNode(cache[key]);
        }
        
        // Create new node and add to map and MRU position
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insertNode(newNode);
        
        // Check capacity
        if (cache.size() > cap) {
            // Find the LRU node (node right after the left dummy node)
            Node* lru = left->next;
            removeNode(lru);          // Remove from list
            cache.erase(lru->key);    // Remove from map
            delete lru;               // Free memory
        }
    }
};
