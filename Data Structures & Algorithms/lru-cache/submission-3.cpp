class LRUCache {
public:
class Node{
    public:
    int key ,val ;
    Node* prev;
    Node* next;
    Node(int k ,int v){
        key=k;
        val=v;
        prev=next=NULL;
    }

};
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;
    int limit;
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;   
    }
    void del(Node* delnode){
        Node* temp= delnode->next;
        Node* temp2 = delnode->prev;
        temp2->next=temp;
        temp->prev=temp2;
    }
    void add(Node* addnode){
        Node* temp=head->next;
        addnode->next=temp;
        temp->prev=addnode;
        addnode->prev=head;
        head->next=addnode;
    }
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* res = m[key];
        int ans = res->val;
        del(res);
        add(res);
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* ex = m[key];
            ex->val=value;
            del(ex);
            add(ex);
            return;
        }
        if(m.size()==limit){
            Node* lr = tail->prev;
            m.erase(lr->key);
            del(lr);
        }
        Node* newnode =new Node(key,value);
        m[key]=newnode;
        add(newnode);
        
    }
};
