/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 16:03:23
 */
#ifndef CP5_ex13_28_h
#define CP5_ex13_28_h
#include <string>
class TreeNode
{
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode &operator=(const TreeNode &rhs)
    {
        ++*rhs.count;
        if (--*count == 0)
        {
            delete left;
            delete right;
            delete count;
        }
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }

    ~TreeNode()
    {
        if (--*count == 0)
        {
            delete left;
            delete right;
            delete count;
        }
    }
};

class BinStrTree
{
private:
    TreeNode *root;

public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &rst) : root(new TreeNode(*rst.root)) {}
    BinStrTree &operator=(const BinStrTree &rhs)
    {
        TreeNode *new_root = new TreeNode(*rhs.root);
        delete root;
        root = new_root;
        return *this;
    }
    ~BinStrTree()
    {
        delete root;
    }
};

#endif