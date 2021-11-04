#include <iostream>

/**
 * This is an implementation of a dynamic symbol table using binary search tree.
 * Insertion/Search timre complexity is O(log n) where n is the number of keys.
 * Deletion is based on Hibbard deletion and also has O(log n) time complexity.
 */

template <typename Key, typename Value>
class BST{
public:
    void put(Key key, Value val){
        root = this->put(root, key, val);
    }

    Value* get(Key key){
        auto p = this->root;
        while (p){
            if (key > p->key) p = p->right;
            else if (key < p->key) p = p->left;
            else return &(p->val);
        }
        
        return nullptr;
    }

    Key* floor(Key key){
        auto p = floor(root, key);
        if (p)
            return &(p->key);
        else
            return nullptr;
    }

    int size(){
        return size(root);
    }

    int rank(Key key){
        return rank(root, key);
    }

    Value* min(){
        auto p = min(root);
        if (!p)
            return &(p->val);
        else
            return nullptr;
    }

    void removeMin(){
        root = removeMin(root);
    }

    void remove(Key key){
        root = remove(root, key);
    }

private:
    struct Node{
        Node* left {nullptr};
        Node* right {nullptr};
        Key key {};
        Value val {};
        int count {1};
        // Constructor
        Node(Key key, Value val){
            this->key = key;
            this->val = val;
        }
        Node(){};
    };

    Node* root{nullptr};
    
    Node* put(Node* p, Key key, Value val){
        if (!p) 
            return new Node(key, val);
        if (key > p->key)
            p->right = put(p->right, key, val);
        else if (key < p->key)
            p->left = put(p->left, key, val);
        else
            p->val = val;
        
        // updating the count, number of nodes in the subtree
        p->count = 1 + size(p->right) + size(p->left);
        return p;
    }

    Node* floor(Node* p, Key key){
        if (!p)
            return nullptr;
        if (p->key == key)
            return p;
        if (key < p->key)
            return floor(p->left, key);
        
        auto t = floor(p->right, key);
        if (t)
            return t;
        else
            return p;
    }

    int size(Node* p){
        if (p)
            return p->count;
        else
            return 0;
    }

    int rank(Node* p, Key key){
        if (!p)
            return 0;
        if (key < p->key)
            return rank(p->left, key);
        else if (key > p->key)
            return 1 + size(p->left) + rank(p->right, key);
        else 
            return size(p->left);
        
    }

    Node* min(Node* p){
        if (!p)
            return nullptr;
        if (!p->left)
            return min(p->left);
        else
            return p;
    }

    Node* removeMin(Node* p){
        if (!p)
            return nullptr;
        if (!p->left){
            auto p_r = p->right;
            delete p;
            p = nullptr;
            return p_r;
        }
        p->left = removeMin(p->left);
        p->count = size(p->left) + size(p->right) + 1;
        return p;
    }

    Node* remove(Node* p, Key key){
        if (!p)
            return nullptr;
        if (key < p->key)
            p->left = remove(p->left, key);
        else if (key > p->key)
            p->right = remove(p->right, key);
        else{
            if (!p->right){
                auto p_l = p->left;
                delete p;
                p = nullptr;
                return p_l;
            }
            if (!p->left){
                auto p_r = p->right;
                delete p;
                p = nullptr;
                return p_r;
            }
            auto t = *min(p->right);
            t.right = removeMin(p->right);
            t.left = p->left;
            p = &t;
        }
        p->count = size(p->left) + size(p->right) + 1;
        return p;
    }

};

int main(){
    BST<int, int> bst;
    bst.put(1,1);
    bst.put(2,2);
    bst.put(0,0);
    bst.put(-1,-1);
    auto val = bst.get(3);
    auto key = bst.floor(-1);
    auto s = bst.size();
    auto r = bst.rank(1);
    bst.removeMin();
    bst.remove(0);
    return 0;
}