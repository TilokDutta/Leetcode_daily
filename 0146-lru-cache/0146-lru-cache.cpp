class LRUCache {
public:
    class node{
        public:
            int key;
        int val;
        node* prev;
        node* next;
        node(int _key, int _value){
            key = _key;
            val = _value;
            prev = next = nullptr;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deletenode(node* delnode){
        node* delprev = delnode -> prev;
        node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    void insertnode(node* innode){
        node* temp = head->next;
        temp->prev = innode;
        head->next = innode;
        innode->next = temp;
        innode->prev = head;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* res = mp[key];
            int ans = res->val;
            mp.erase(key);
            deletenode(res);
            insertnode(res);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* node = mp[key];
            deletenode(node);
            mp.erase(key);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        insertnode(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */