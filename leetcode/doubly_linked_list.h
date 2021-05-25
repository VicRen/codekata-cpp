#ifndef CODEKATA_CPP_DOUBLY_LINKED_LIST_H
#define CODEKATA_CPP_DOUBLY_LINKED_LIST_H

struct Node {
    int value;
    Node *pnx;

    explicit Node(int data, Node *ptr = nullptr) : value(data), pnx(ptr) {
    }
};

Node *XOR(Node *node1, Node *node2) {
    return (Node *) ((long) node1 ^ (long) node2);
}

void insert(Node **headRef, int data) {
    Node *newHead = new Node(data);

    newHead->pnx = XOR(nullptr, *headRef);

    if (*headRef) {
        (*headRef)->pnx = XOR(newHead, XOR(nullptr, (*headRef)->pnx));
    }
    (*headRef) = newHead;
}

#endif //CODEKATA_CPP_DOUBLY_LINKED_LIST_H
