#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "BinaryTree.hpp"

namespace ariel{
//using namespace std::
template <typename T>

class BinaryTree{
    private:
        struct node{
            T value;
            node* left_sun;
            node* right_sun;

            node(){
                left_sun=nullptr;
                right_sun=nullptr;
                }
            
        };///close struct

        

    public:
    node* root;
    //map<T, * node> map_nodes;
        BinaryTree(){root= new node;}
        ~BinaryTree(){};
        BinaryTree<T> & add_root (const T & s){
            root->value=s;
            //map_nodes[s]=root;
            return *this;
        }

        BinaryTree<T> & add_left (const T& father, const T & sun){
           // if(map_nodes.contains(father)){
                    node * newnode= new node();
                    newnode->value=sun;
                   // map_nodes[father]->second->left_sun=newnode;
                   // return *this;
                //}
                return *this;
        
        }
        BinaryTree<T> & add_right (const T & father, const T & sun){
            return *this;
        }
        friend std::ostream& operator<<(ostream&o,const BinaryTree<T> &B){
            o<<"tree";
            return o;
        }
   


        class iterator{
            private:
            node* pointer_to_current_node;
            public:
            iterator(node* ptr=nullptr)
            :pointer_to_current_node(ptr){
            }
            const  T& operator*()const{
                return pointer_to_current_node->value;
            }
            const T* operator->()const{
                return &(pointer_to_current_node->value);
            }
            iterator& operator++(){
                return *this;
            }
            const iterator operator++(int){
                return *this;
            }
            bool operator==(const iterator& rhs)const{
                return 0;
            }
            bool operator!=(const iterator& rhs)const{
                return 0;
            }
            };// close class iterator


class postorder_iterator{
    private:
            node* pointer_to_current_node;
    public:
            postorder_iterator(node* ptr=nullptr)
            :pointer_to_current_node(ptr){
            }
            const T& operator*()const {
                return pointer_to_current_node->value;
            }
            const T* operator->()const {
                return &(pointer_to_current_node->value);
            }
            postorder_iterator& operator++(){
                return *this;
            }
            const postorder_iterator operator++(int){
                return *this;
            }
            bool operator==(const postorder_iterator& rhs)const{
                return 0;
            }
            bool operator!=(const postorder_iterator& rhs)const{
                return 0;
            }
};

class preorder_iterator{
    private:
            node* pointer_to_current_node;
            public:
            preorder_iterator(node* ptr=nullptr)
            :pointer_to_current_node(ptr){
            }
            const T& operator*()const {
                return pointer_to_current_node->value;
            }
            const T* operator->()const {
                return &(pointer_to_current_node->value);
            }
            preorder_iterator& operator++(){
                return *this;
            }
            const preorder_iterator operator++(int){
                return *this;
            }
            bool operator==(const preorder_iterator& rhs)const{
                return 0;
            }
            bool operator!=(const preorder_iterator& rhs)const{
                return 0;
            }
};

class inorder_iterator{
    private:
            node* pointer_to_current_node;
            public:
            inorder_iterator(node* ptr=nullptr)
            :pointer_to_current_node(ptr){
            }
            const T& operator*()const {
                return pointer_to_current_node->value;
            }
            const T* operator->()const {
                return &(pointer_to_current_node->value);
            }
            inorder_iterator& operator++(){
                return *this;
            }
            const inorder_iterator operator++(int){
                return *this;
            }
            bool operator==(const inorder_iterator& rhs)const{
                return 0;
            }
            bool operator!=(const inorder_iterator& rhs)const{
                return 0;
            }
};
        iterator begin(){
            return iterator{root};
        }
        iterator end(){
            return iterator{nullptr};
        }
      
        inorder_iterator begin_inorder()const{
            return inorder_iterator{root};
        }
        inorder_iterator end_inorder()const{
            return inorder_iterator{nullptr};
        }
        preorder_iterator begin_preorder()const{
            return preorder_iterator{root};
        }
        preorder_iterator end_preorder()const{
            return preorder_iterator{nullptr};
        }
        postorder_iterator begin_postorder()const{
            return postorder_iterator{root};
        }
        postorder_iterator end_postorder()const{
            return postorder_iterator{nullptr};
        }

};
}