#include <iostream>
#include <unordered_map>
using namespace std;

class dll {
public:
    int key, val;
    dll *left, *right;

    dll(int k, int v) {
        key = k;
        val = v;
        left = right = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, dll*> mp;
    dll *leftDummy, *rightDummy;

    // Remove a node from its position
    void remove(dll* node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }

    // Insert node just before rightDummy (as MRU)
    void insert_before_right(dll* node) {
        node->left = rightDummy->left;
        node->right = rightDummy;
        rightDummy->left->right = node;
        rightDummy->left = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        // Created Dummy Node because  it reduces edge cases
        // and simplifies the logic for insertion and deletion.
        leftDummy = new dll(-1, -1);
        rightDummy = new dll(-1, -1);
        leftDummy->right = rightDummy;
        rightDummy->left = leftDummy;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        dll* node = mp[key];
        remove(node);
        insert_before_right(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dll* node = mp[key];
            node->val = value;
            remove(node);
            insert_before_right(node);
        } else {
            if ((int)mp.size() == cap) {
                dll* lru = leftDummy->right;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            dll* newNode = new dll(key, value);
            insert_before_right(newNode);
            mp[key] = newNode;
        }
    }

    ~LRUCache() {
        dll* cur = leftDummy;
        while (cur) {
            dll* next = cur->right;
            delete cur;
            cur = next;
        }
    }
};
int main() {
    LRUCache cache(2);
    cache.put(1, 1); // cache is {1=1}
    cache.put(2, 2); // cache is {1=1, 2=2}
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3); // evicts key 2, cache is {1=1, 3=3}
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4); // evicts key 1, cache is {3=3, 4=4}
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}