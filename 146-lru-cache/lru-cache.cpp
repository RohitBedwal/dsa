class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node* next ;
        Node* prev ;


    Node(int val_,int key_){
        val = val_;
        key = key_;
        
    }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap ;
    unordered_map <int, Node*> m;



    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    void deleteNodeAtEnd( Node* node){
        Node* nodeNext = node->next;
        Node* nodePrev = node->prev;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;



    }
    void insertAtHead( Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;

    }

    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            int res = node->val;
            m.erase(key);
            deleteNodeAtEnd(node);
            insertAtHead(node);
            m[key] = head->next;
            return res;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            m.erase(key);
            deleteNodeAtEnd(node);

        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNodeAtEnd(tail->prev);

        }
        Node* newNode = new Node(value, key);
        insertAtHead(newNode);
        m[key] = head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */