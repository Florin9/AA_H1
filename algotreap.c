#include <stdio.h>
#include <stdlib.h>


int ERROR = -2147483648;

typedef struct Node {
    int priority;
    int elem;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
}Node;

typedef Node T;
#include "algo.h"

typedef struct Treap {
    Node* root;
} Treap;

Node* RightRotate(Node* y) {
    Node *x = y->left;
    Node *xrc = x->right;

    x->right = y;
    y->left = xrc;

    return x;

}

Node* LeftRotate(Node* x) {
    Node *y = x->right;
    Node *yrc = y->left;

    y->left = x;
    x->right = yrc;

    return y;
}

void* insert(void* root1, int elem) {
//Pseudocod lab SD
	Node* root = (Node*) root1;
    if(root == NULL) {
        Node* node = calloc(1,sizeof(Node));
        node->elem = elem;
        node->priority = rand()%1000;
        return node;
    }

    if(elem < root->elem) {
        root->left = insert(root->left,elem);
        if(root->left->priority > root->priority) {
            root = RightRotate(root);
        }
    }
    else {
        root->right = insert(root->right,elem);
        if(root->right->priority > root->priority) {
            root = LeftRotate(root);
        }

    }

    return root;

}

int getMax(void* root1) {
	Node* root = (Node*) root1;    
	if(root == NULL) {
        return ERROR;
    }
    Node* node = root;
    if(node == NULL) {
        return ERROR;
    }
    while(node->right != NULL) {
        node = node->right;
    }
    return node->elem;
}
void* deleteMax(void* root1) {
	Node* root = (Node*) root1;
    if(root == NULL) {
        return NULL;
    }
    Node* node = root;
    Node* parent = NULL;
    if(node == NULL) {
        return NULL;
    }
    while(node->right != NULL) {
        parent = node;
        node = node->right;
    }
    if(root == node) {
        Node* temp = node->left;
        free(node);
		node = NULL;
        root = temp;
        return root;
    }

    parent->right = node->left;
    free(node);
	node = NULL;
    return root;
}

void freetreapHelper(Node* x) {
    if(x != NULL) {
    freetreapHelper(x->left);
    freetreapHelper(x->right);
    free(x);
    }
}

void freetreap(Treap* t) {
    if(t == NULL) {
        return;
    }
    if(t->root == NULL) {
        free(t);
        return;
    }
    freetreapHelper(t->root->left);
    freetreapHelper(t->root->right);
    free(t);

}

void* initialize(int nr) {
    return NULL;
}
