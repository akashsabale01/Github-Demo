#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};

class Bst
{
private:
    Node *root;

public:
    Bst(){ root = NULL; }
    Node* getRoot() { return root; }

    void InsertNodeIterative(int key);
    Node* InsertNodeRecursive(Node* p, int key);

    Node* SearchIterative(int key);
    Node* SearchRecursive(Node *p, int key);
    bool SearchBool(Node *p, int key);

    void Inorder(Node* p);

};

void Bst::InsertNodeIterative(int key)
{
    // p pointer points to root
    // q is tail pointer, q follows to p, q acts as previous node of p
    // t is pointer for creating new node

    Node *p = root, *q = NULL, *t;

    if(p == NULL)
    {
        t = new Node(key);
        root = t;
        return;
    }

    // Search if key is Present or Not
    while(p != NULL)
    {
        q = p; // q follows p
        if(key == p->data)
            return;
        else if(key < p->data)
            p = p->lchild ;
        else
            p = p->rchild;
    }

    // After loop p will became NULL and q will points to location where we have to insert
    t = new Node(key);

    if(key < q->data)
        q->lchild = t;
    else
        q->rchild = t;
}

Node* Bst::InsertNodeRecursive(Node* p, int key)
{
    Node *t;
    if(p == NULL)
    {
        t = new Node(key);
        return t;
    }

    if(key < p->data)
        p->lchild = InsertNodeRecursive(p->lchild, key);
    else if(key > p->data)
        p->rchild = InsertNodeRecursive(p->rchild, key);

    return p;
}

Node* Bst::SearchIterative(int key)
{
    Node *p = root;

    // root is NULL
    if(p == NULL)
        return NULL;

    while(p != NULL)
    {
        if(key == p->data)
            return p;
        else if(key < p->data)
            p = p->lchild ;
        else
            p = p->rchild;
    }

     return NULL;  // Not found
}

Node* Bst::SearchRecursive(Node *p, int key)
{
    if(p == NULL)
        return NULL;

    if(key == p->data)
        return p;
    else if(key < p->data)
        return SearchRecursive(p->lchild, key);
    else
        return SearchRecursive(p->rchild, key);
}

bool Bst::SearchBool(Node *p, int key)
{
    if(p == NULL)
        return false;

    if(key == p->data)
        return true;

    else if(key < p->data)
        return SearchBool(p->lchild, key);

    else
        return SearchBool(p->rchild, key);
}

// In-order traversal print keys in sorted order
void Bst::Inorder(Node *p)
{
    if(p == NULL)
        return;

    Inorder(p->lchild);
    cout<<p->data<<" ";
    Inorder(p->rchild);
}


int main()
{
    Bst bst;

    // Iterative insert
    int arr[] = {10,5,20,8,30};
    for(int x: arr)
        bst.InsertNodeIterative(x);

    cout<<"Inorder Tree Traversal of BST :";
    bst.Inorder(bst.getRoot());
    cout<<endl;

    // Iterative search
    int k = 10;
    Node *temp = bst.SearchIterative(k);
    if(temp!=NULL)
        cout<<"Key "<<temp->data<<" Found"<<endl;
    else
        cout<<"Key "<<k<<" Not Found"<<endl;

    Node *rt = bst.getRoot();

    // Recursive search
    k = 1;
    temp = bst.SearchRecursive(rt,1);
    if(temp!=NULL)
        cout<<"Key "<<temp->data<<" Found"<<endl;
    else
        cout<<"Key "<<k<<" Not Found"<<endl;

    // Search with bool result
    k = 56;
    bool isPresent = bst.SearchBool(rt,56);
    if(isPresent)
        cout<<"Key Found"<<endl;
    else
        cout<<"Key "<<k<<" Not Found"<<endl;

    // Recursive insert
    bst.InsertNodeRecursive(rt, 50);
    bst.InsertNodeRecursive(rt, 29);
    bst.InsertNodeRecursive(rt, 29); // repeated
    bst.InsertNodeRecursive(rt, 70);
    bst.InsertNodeRecursive(rt, 1);
    bst.InsertNodeRecursive(rt, 64);

    cout<<"Inorder Tree Traversal of BST :";
    bst.Inorder(bst.getRoot());
    cout<<endl;


    return 0;
}
