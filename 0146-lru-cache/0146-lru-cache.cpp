class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        if (mp.size() == cap) {

            Node* lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);

        insert(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */