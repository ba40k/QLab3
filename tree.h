//
// Created by radamir on 02.03.25.
//

#ifndef Tree_H
#define Tree_H
#include <iostream>
#include <functional>
#include <QVector>

template<typename dataType>
class Tree {
private:

      class Node {

        Node *left;
        Node *right;
          Node* parent;
        dataType data;
      public:
          Node(dataType _data);
          Node* getParent();
          void setParent(Node* _parent);
        Node* getLeft();
        Node* getRight();
        int getData();
        void setData(dataType _data);
        void setLeft(Node *_left);
        void setRight(Node *_right);

      };
      void recursiveDelete(dataType data, Node* vertex);
      Node *root;
  void deleteTree(Node* vertex);
  Node* findMinmumGreater(Node* vertex);
public:
  Tree();
  ~Tree();
  Node* getRoot();
  void insert(dataType data);
  bool search(dataType data);
  void erase(dataType data);
    void forwardTraversal(Node* vertex, QVector<dataType> &res);
    void backwardTraversal(Node* vertex, QVector<dataType> &res);
    void inOrderTraversal(Node* vertex, QVector<dataType> &res);


};
template<typename dataType>
Tree<dataType>::Tree() {
    root = nullptr;
}

template<typename dataType>
Tree<dataType>::Node* Tree<dataType>::getRoot() {
    return root;
}

template<typename dataType>
void Tree<dataType>::recursiveDelete(dataType data, Node* vertex) {
     if (data == vertex->getData()) {

            if (vertex->getParent() == nullptr) { //  удаление корня
                Node* toSwap = findMinmumGreater(vertex);
                Node* toDelete = vertex;
                vertex = toSwap;
                delete toDelete;
                return ;
            }

            if (vertex->getLeft() == nullptr && vertex->getRight() == nullptr) {  // удаление листа
                if (vertex->getData() > vertex->getParent()->getData()) { // перед удалением затираем адрес в родителе
                    vertex->getParent()->setRight(nullptr);
                } else {
                    vertex->getParent()->setLeft(nullptr);
                }
                delete vertex;
                return ;
            }

            if (vertex->getRight() == nullptr) { //  случай когда я не могу пойти направо и влево
                Node* toSwap = vertex->getLeft();
                Node* toDelete = vertex;

                vertex = toSwap;
                delete toDelete;
                return ;
            }

            Node* toSwap = findMinmumGreater(vertex); // мы пошли от этого узла вправо и потом до упора в лево
            // теперь, поскольку мы собираемся закинуть его на место текущего узла нужно удалить адрес toSwap из родителя
            Node* toSwapParent = toSwap->getParent();
            if (toSwapParent->getData() < toSwap->getData()) {
                toSwapParent->setRight(nullptr);
            } else {
                toSwapParent->setLeft(nullptr);
            }
            // Теперь мы отсоединили его от родителя
            //  Вставим его на место текущей вершины, а именно поставим ему соответствующего родителя
            toSwap->setParent(vertex->getParent());
            // Теперь остается у нового родителя изменить адрес ребенка
            if (toSwap->getParent()->getData() < vertex->getData()) {
                toSwap->getParent()->setRight(toSwap);
            } else {
                toSwap->getParent()->setLeft(toSwap);
            }

            toSwap->setLeft(vertex->getLeft());
            toSwap->setRight(vertex->getRight());

            delete vertex;
            return ;
        }

        if (data > vertex->getData()) {
            recursiveDelete(data,vertex->getRight());
        } else {
             recursiveDelete(data,vertex->getLeft());
        }
}
template<typename dataType>
Tree<dataType>::Node::Node(dataType _data) {
    left = nullptr;
    right = nullptr;
    data = _data;
}
template<typename dataType>
int Tree<dataType>::Node::getData() {
    return data;
}
template<typename dataType>
void Tree<dataType>::Node::setData(dataType _data) {
     data = _data;
}
template<typename dataType>
Tree<dataType>::Node* Tree<dataType>::Node::getLeft() {
    return left;
}
template<typename dataType>
Tree<dataType>::Node* Tree<dataType>::Node::getRight() {
    return right;
}
template<typename dataType>
Tree<dataType>::Node* Tree<dataType>::Node::getParent() {
    return parent;
}
template<typename dataType>
void Tree<dataType>::Node::setLeft(Node *_left) {
    left = _left;
}
template<typename dataType>
void Tree<dataType>::Node::setRight(Node *_right) {
    right = _right;
}
template<typename dataType>
void Tree<dataType>::Node::setParent(Node *_parent) {
    parent = _parent;
}
template<typename dataType>
void Tree<dataType>::deleteTree(Node* vertex) {
    std::cout<<vertex->getData()<<'\n';
    if (vertex == nullptr) {
        return;
    }
    deleteTree(vertex->getLeft());
    deleteTree(vertex->getRight());
    delete vertex;
}
template<typename dataType>
void Tree<dataType>::insert(dataType data) {
    if (search(data)) {
        return;
    }
    if (root == nullptr) {
        root = new Node(data);
        root->setParent(nullptr);
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
    vertex->setParent(parent);

}
template<typename dataType>
Tree<dataType>::Node *Tree<dataType>::findMinmumGreater(Node *vertex) {


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
template<typename dataType>
void Tree<dataType>::erase(dataType data) {
    recursiveDelete(data,root);
}

template<typename dataType>
bool Tree<dataType>::search(dataType data) {
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

template<typename dataType>
void Tree<dataType>::forwardTraversal(Node *vertex,QVector<dataType> &res) {
    if (vertex == nullptr) {
        return ;
    }
    res.push_back(vertex->getData());
    forwardTraversal(vertex->getLeft(),res);
    forwardTraversal(vertex->getRight(),res);
}

template<typename dataType>
void Tree<dataType>::backwardTraversal(Node *vertex,QVector<dataType> &res) {
    if (vertex == nullptr) {
        return ;
    }
    backwardTraversal(vertex->getLeft(),res);
    backwardTraversal(vertex->getRight(),res);
    res.push_back(vertex->getData());
}

template<typename dataType>
void Tree<dataType>::inOrderTraversal(Node *vertex,QVector<dataType> &res) {
    if (vertex == nullptr) {
        return ;
    }
    inOrderTraversal(vertex->getLeft(),res);
    res.push_back(vertex->getData());
    inOrderTraversal(vertex->getRight(),res);
}

template<typename dataType>
std::ostream& operator<<(std::ostream&out, Tree<dataType> &tree) {
    QVector<dataType> path;
    tree.inOrderTraversal(tree.getRoot(),path);
    for (int i =0; i < path.size(); i++) {
        if (i == path.size() - 1) {
            out<<path[i];
            return out;
        }
        out << path[i] << " ";
    }
    return out;
}

template<typename dataType>
Tree<dataType>::~Tree() {
    deleteTree(root);
}



#endif //Tree_H
