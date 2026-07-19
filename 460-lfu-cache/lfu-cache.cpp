struct Node{
    int val, key, cnt;
    Node* next;
    Node* prev;
    Node(int key_, int val_){
        key = key_;
        cnt = 1;
        val = val_;
        prev = next = NULL;
    }

};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;

    }
    void insertFront (Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }

    void removeNode(Node* node){
        Node * prevNode = node->prev;
        Node * nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;

    }

};

class LFUCache {
    private:
        unordered_map<int, Node*> keyNode;
        unordered_map<int, List*> freqListMap;

        int maxSizeCache;
        int currSize;
        int minFreq;



public:
    LFUCache(int capacity) {
       
        maxSizeCache = capacity;
        currSize = 0;
        minFreq = 0;

        
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(minFreq == node->cnt && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt+=1;
        nextHigherFreqList->insertFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;

    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);

        }
        else{
             if(currSize == maxSizeCache){

                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
             }
             currSize++;
             minFreq = 1;
             List* freqList = new List();
             if(freqListMap.find(minFreq) != freqListMap.end()){
                freqList = freqListMap[minFreq];
             }
             Node* node = new Node(key, value);
             freqList->insertFront(node);
             keyNode[key] = node;
             freqListMap[minFreq] = freqList;
             
            }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */