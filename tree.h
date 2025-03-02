//
// Created by radamir on 02.03.25.
//

#ifndef Tree_H
#define Tree_H



class Tree {
private:
      class Node {

        Node *left;
        Node *right;
        int data;
        public:
         Node(int _data);
        Node* getLeft();
        Node* getRight();
        int getData();
        void setData(int _data);
        void setLeft(Node *_left);
        void setRight(Node *_right);
      };
      Node *root;
  void deleteTree(Node* vertex);
  Node* findMinmumGreater(Node* vertex);
public:
  Tree();
  ~Tree();
  Node* getRoot();
  void insert(int data);
  bool search(int data);
  void erase(int data);
};



#endif //Tree_H
