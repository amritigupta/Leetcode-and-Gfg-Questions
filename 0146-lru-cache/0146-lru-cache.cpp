class LRUCache {
public:

    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int x, int y){
            key = x;
            val = y;
            next = NULL;
            prev = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap=capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* node){
        Node* nxtnode= node->next;
        Node* prevnode= node->prev;

        prevnode->next = nxtnode;
        nxtnode->prev = prevnode;
    }

    void insert(Node* node){
        Node* nextofhead= head->next;
        head->next = node;
        node->prev = head;
        node->next = nextofhead;
        nextofhead->prev = node;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            deletenode(node);
            insert(node);
            int val = node->val;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            deletenode(node);
            node->val = value;
            insert(node);
            return;
        }


        if(mpp.size()==cap){
            Node * delnode = tail->prev;
            int k = delnode->key;
            mpp.erase(k);
            deletenode(delnode);
            delete delnode;
        }

        Node* newnode = new Node(key, value);
        mpp[key]=newnode;
        insert(newnode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */