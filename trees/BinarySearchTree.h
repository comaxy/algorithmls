//
//  BinarySearchTree.h
//  algorithm
//
//  Created by Theresa on 16/8/28.
//  Copyright © 2016年 Comaxy. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <iostream>

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}
    {
    }
    
    BinarySearchTree(const BinarySearchTree& rhs) : root{nullptr}
    {
        root = clone(rhs.root);
    }
    
    BinarySearchTree(BinarySearchTree&& rhs) : root{nullptr}
    {
        root = clone(rhs.root);
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree()
    {
        makeEmpty();
    }
    
    const Comparable& findMin() const
    {
        return findMin(root);
    }
    
    const Comparable& findMax() const
    {
        return findMax(root);
    }
    
    /**
     * Returns true if x is found in the tree.
     */
    bool contains(const Comparable& x) const
    {
        return contains(x, root);
    }
    
    bool isEmpty() const
    {
        return root == nullptr;
    }
    
    void printTree(std::ostream& out = std::cout) const;
    
    void makeEmpty()
    {
        makeEmpty(root);
    }
    
    /**
     * Insert x into the tree; duplicate are ignored.
     */
    void insert(const Comparable& x)
    {
        insert(x, root);
    }
    
    void insert(Comparable&& x);
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(const Comparable& x)
    {
        remove(x, root);
    }
    
    BinarySearchTree& operator = (const BinarySearchTree& rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
    }
    
    BinarySearchTree& operator = (BinarySearchTree&& rhs)
    {
        std::swap(root, rhs.root);
    }
    
private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode* left;
        BinaryNode* right;
        
        BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{theElement}, left{lt}, right{rt} {}
        
        BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{std::move(theElement)}, left{lt}, right{rt} {}
    };
                
    BinaryNode *root;
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(const Comparable& x, BinaryNode*& t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(x, t->left);
        }
        else if (t->element < x)
        {
            insert(x, t->right);
        }
        else
        {
            ;  // Duplicate; do nothing
        }
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert by moving.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(Comparable&& x, BinaryNode*& t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{std::move(x), nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(x, t->left);
        }
        else if (t->element < x)
        {
            insert(x, t->right);
        }
        else
        {
            ;  // Duplicate; do nothing
        }
    }
    
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove(const Comparable& x, BinaryNode*& t)
    {
        if (t == nullptr)
        {
            return;  // Item not found; do nothing
        }
        else if (x < t->element)
        {
            remove(t->left);
        }
        else if (t->element < x)
        {
            remove(t->right);
        }
        else if (t->left != nullptr && t->right != nullptr)  // Two children
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode* oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }
    
    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode* findMin(BinaryNode* t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        else if (t->left == nullptr)
        {
            return t;
        }
        else
        {
            return findMin(t->left);
        }
    }
    
    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode* findMax(BinaryNode* t) const
    {
        if (t != nullptr)
        {
            while (t->right != nullptr)
            {
                t = t->right;
            }
        }
        return t;
    }
    
    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains(const Comparable& x, BinaryNode* t) const
    {
        if (t == nullptr)
        {
            return false;
        }
        else if (x < t->element)
        {
            return contains(x, t->left);
        }
        else if (t->element < x)
        {
            return contains(x, t->right);
        }
        else
        {
            return true;  // Math
        }
    }
    
    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty(BinaryNode* t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
    
    void printTree(BinaryNode* t, std::ostream& out) const;
    
    /**
     * Internal method to clone subtree.
     */
    BinaryNode* clone(BinaryNode *t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        else
        {
            return new BinaryNode{t->element, clone(t->left), clone(t->right)};
        }
    }
};

#endif /* BinarySearchTree_h */
