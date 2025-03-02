//
// Created by radamir on 02.03.25.
//

#include "tree.h"
#include <functional>

Tree::Tree() {
    root = nullptr;
}
Tree::Node::Node(int _data) {
    left = nullptr;
    right = nullptr;
    data = _data;
}
int Tree::Node::getData() {
    return data;
}
void Tree::Node::setData(int _data) {
     data = _data;
}
Tree::Node* Tree::Node::getLeft() {
    return left;
}
Tree::Node* Tree::Node::getRight() {
    return right;
}
void Tree::Node::setLeft(Node *_left) {
    left = _left;
}
void Tree::Node::setRight(Node *_right) {
    right = _right;
}

void Tree::deleteTree(Node* vertex) {
    if (vertex == nullptr) {
        return;
    }
    deleteTree(vertex->getLeft());
    deleteTree(vertex->getRight());
    delete vertex;
}
void Tree::insert(int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }
    Node* vertex = root;
    Node* parent = nullptr;
    while(vertex != nullptr) {
        parent = vertex;
        if (data > vertex->getData()) {
            vertex = (vertex->getRight());
        } else {
            vertex = (vertex->getLeft());
        }
    };
    vertex = new Node(data);
    if (parent->getData() < data) {
        parent->setRight(vertex);
    } else {
        parent->setLeft(vertex);
    }

}
Tree::Node *Tree::findMinmumGreater(Node *vertex) {


    Node* currentVertex = vertex;
    Node* startVertex = vertex;
    while (true) {
        if (startVertex == currentVertex) {
            if (startVertex->getRight() == nullptr) {
                return startVertex;
            }
            currentVertex= currentVertex->getRight();
        } else {
            if (currentVertex->getLeft() == nullptr) {
                return currentVertex;
            }
            currentVertex= currentVertex->getRight();
        }
    }
}

void Tree::erase(int data) {
    Node* vertex = root;
    while (vertex != nullptr) {
        if (data == vertex->getData()) {
            if (vertex->getLeft() == nullptr && vertex->getRight() == nullptr) {
                delete vertex;
                return ;
            }
            if (vertex->getLeft() == nullptr) {
                Node* old = vertex->getRight();
                vertex->setData(vertex->getRight()->getData());
                vertex->setLeft(vertex->getRight()->getLeft());
                vertex->setRight(vertex->getRight()->getRight()) ;
                delete old;
                return;
            }
            if (vertex->getRight() == nullptr) {
                Node* old = vertex->getLeft();
                vertex->setData(vertex->getLeft()->getData())  ;
                vertex->setLeft(vertex->getLeft()->getLeft()) ;
                vertex->setRight(vertex->getLeft()->getRight()) ;
                delete old;
                return;
            }
            Node* toSwap = findMinmumGreater(vertex);
            Node* old = vertex;
            vertex = toSwap;
            delete old;
        }

        if (data > vertex->getData()) {
            vertex = (vertex->getRight());
        } else {
            vertex = (vertex->getLeft());
        }
    }
}


bool Tree::search(int data) {
    Node* current = root;
    while (current != nullptr) {
        if (data == current->getData()) {
            return true;
        }
        if (data > current->getData()) {
            current = current->getRight();
        } else {
            current = current->getLeft();
        }
    }
    return false;
}
Tree::~Tree() {
    deleteTree(root);
}

