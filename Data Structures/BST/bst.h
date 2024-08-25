

#ifndef BST_H
#define BST_H

#include <type_traits>
#include "../Stack/stack.h"
#include "../Queue/queue.h"

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
class BST{

    private:

    struct TreeNode {

        TreeNode* left;
        TreeNode* right;
        T data;

        TreeNode(T val): data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;  

    public:

        BST():root(nullptr){}

        bool isEmpty(){
            return root == nullptr;
        }

        int getHeight(){
            if(root != nullptr){
                return getHeightrec(root);
            }else{
                std::cout << "Tree Is Empty\n";
                return 0;
            }
        }
        
        int getNumberOfNodes(){
            if(root != nullptr){
                return getNumberOfNodesrec(root);
            }else{
                std::cout << "Tree Is Empty\n";
                return 0;
            }
        }

        T getRootData(){
            if(root != nullptr){
                return root->data;
            }else{
                throw std::runtime_error("Empty BST");
            }
        }

        void setRootData(T data){
            if(root == nullptr){
                root = new TreeNode(data);
            }else{
                add(data);
            }
        }

        bool add(T data){

            if(root == nullptr){

                root = new TreeNode(data);
                return true;

            }else{

                TreeNode* current = root;
                TreeNode* new_node = new TreeNode(data);

                while(true){

                if(new_node->data < current->data){

                    if(current->left == nullptr){
                        current->left = new_node;
                        return true;
                    }else{
                        current = current->left;
                    }

                }else if(new_node->data > current->data){

                    if(current->right == nullptr){

                        current->right = new_node;
                        return true;

                    }else{
                        current = current->right;
                    }

                }else{
                    delete new_node;
                    return false;

                }

                }
            }
        }

        bool add_r(T data){
            return __add_r(root, data);
        }

        void clear(){
            clearrec(root);
            root = nullptr;
        }

        TreeNode* getEntry(T data){
            return getEntry_r(root, data);
        }

        bool contains(T data){
            return (getEntry_r(root, data) == nullptr)?false:true;
        }

        void inorderTraverse(){
            inorderTraverse_r(root);
        }

        void inorderTraverse_i(){
            __inorderTraverse_i(root);
        }
        
        void preorderTraverse_r(){
            __preorderTraverse_r(root);
        }

        void preorderTraverse_i(){
            __preorderTraverse_i(root);
        }

        void postorderTraverse_r(){
            __postorderTraverse_r(root);
        }

        void postorderTraverse_i(){
            __postorderTraverse_i(root);
        }

        void rev_inorderTraverse_r(){
            __rev_inorderTraverse_r(root);
        }

        void rev_inorderTraverse_i(){
            __rev_inorderTraverse_i(root);
        }

        void levelorder_r(){
            __levelorder_r(root);
        }

        void levelorder_i(){
            __levelorder_i(root);
        }

        void remove(T key){
            __remove(root, key);
        }

        ~BST(){
            clear();
        }

        

        private:

        TreeNode* __remove(TreeNode* current, T key) {
        if (current == nullptr) {
            return current;
        }
        if (current->data > key) {
            current->left = __remove(current->left, key);
        } else if (current->data < key) {
            current->right = __remove(current->right, key);
        } else {
            if (current->left == nullptr) {
                TreeNode* tmp = current;
                current = current->right;
                delete tmp;
            } else if (current->right == nullptr) {
                TreeNode* tmp = current;
                current = current->left;
                delete tmp;
            } else{
                TreeNode* node = findMin(current->right);
                current->data = node->data;
                current->right = __remove(current->right, node->data);
            }
        }
        return current;
    }

        void __levelorder_i(TreeNode* root){
            if(root == nullptr){
                return;
            }

            TreeNode* current = root;
            Queue<TreeNode*> qu;
            qu.enqueue(current);

            while(!qu.isempty()){
                std::cout << qu.peek()->data << " ";

                if(qu.peek()->left) qu.enqueue(qu.peek()->left);
                if(qu.peek()->right) qu.enqueue(qu.peek()->right);
                qu.dequeue();
            }
        }

        void __rev_inorderTraverse_i(TreeNode* root){

            if(root == nullptr){
                return;
            }

            TreeNode* current = root;
            Stack<TreeNode*> st;

            while(current || !st.isempty()){
                while(current){
                    st.push(current);
                    current = current->right;
                }

                current = st.top();
                st.pop();
                std::cout << current->data << " ";
                current = current->left;
            }
        }

        void __postorderTraverse_i(TreeNode* root){
            if(root == nullptr){
                return;
            }

            TreeNode* current = root;
            Stack<TreeNode*> st, out;

            st.push(current);

            while(!st.isempty()){
                current = st.top();
                st.pop();
                out.push(current);

                if(current->left) st.push(current->left);
                if(current->right) st.push(current->right);
                
            }

            while(!out.isempty()){
                std::cout << out.top()->data << " ";
                out.pop();
            }
        }


        void __preorderTraverse_i(TreeNode* root){
            if(root == nullptr){
                return;
            }

            Stack<TreeNode*> st;
            TreeNode* current = root;

            while(current || !st.isempty()){
                
                while(current){
                    st.push(current);
                    std::cout << current->data << " ";
                    current = current->left;
                }
            

            current = st.top();
            st.pop();
            current = current->right;
            }
        }

        void __inorderTraverse_i(TreeNode* root){

            if(root == nullptr)
                return;

            TreeNode* current = root;

            Stack<TreeNode*> st;
            
            while(current != nullptr || !st.isempty()){

                while(current){
                    st.push(current);
                    current = current->left;
                }

                current = st.top();
                st.pop();
                std::cout << current->data << " ";
                current = current->right;

            }

        }


  TreeNode* findMin(TreeNode* node)
  {
    while(node && node->left != nullptr){
        node = node->left;
    }

    return node;
  }

        void printlevel(TreeNode* current, int level){
            if(current == nullptr){
                return;
            }else if(level == 1){
                std::cout << current->data << " ";
            }else{
                printlevel(current->left, level - 1);
                printlevel(current->right, level - 1);
            }
        }

        void __levelorder_r(TreeNode* current){
            int height = getHeightrec(current);
            for(int i = 1; i <= height; ++i){
                printlevel(current, i);
            }
        }

        void __rev_inorderTraverse_r(TreeNode* current){
            if(current == nullptr){
                return;
            }

            __rev_inorderTraverse_r(current->right);
            std::cout << current->data << " ";
            __rev_inorderTraverse_r(current->left);
            
        }

        void __postorderTraverse_r(TreeNode* current){
            if(current == nullptr){
                return;
            }

            __postorderTraverse_r(current->left);
            __postorderTraverse_r(current->right);
            std::cout << current->data << " ";
            
        }

        void __preorderTraverse_r(TreeNode* current){
            if(current == nullptr){
                return;
            }

            std::cout << current->data << " ";
            __preorderTraverse_r(current->left);
            __preorderTraverse_r(current->right);
            
        }

        bool __add_r(TreeNode* current, T data){
           
            if(current == root && root == nullptr){
                root = new TreeNode(data);
                return true;
            }

            if(current->data == data){
                return false;
            }else if(current->data > data){
                if(current->left == nullptr){
                    current->left = new TreeNode(data);
                    return true;
                }else{
                    return __add_r(current->left, data);
                }
            }else{
                if(current->right == nullptr){
                    current->right = new TreeNode(data);
                    return true;
                }else{
                    return __add_r(current->right, data);
                }
            }


            
        }

        TreeNode* getEntry_r(TreeNode* current, T data){
            if(current == nullptr){
                return nullptr;
            }

            if(current->data == data){
                return current;
            }else if(current->data > data){
                return getEntry_r(current->left, data);
            }else{
                return getEntry_r(current->right, data);
            }
        }

        void inorderTraverse_r(TreeNode* current){
            if(current == nullptr){
                return;
            }

            inorderTraverse_r(current->left);
            std::cout << current->data << " ";
            inorderTraverse_r(current->right);
        }

        void clearrec(TreeNode* current){
        if(current != nullptr){
                clearrec(current->left);
                clearrec(current->right);
                delete current;
        }
        }

        int getHeightrec(TreeNode* current){
            if(current != nullptr){
                int left = getHeightrec(current->left);
                int right = getHeightrec(current->right);
                return (left >= right)?left + 1: right + 1;
            }else{
                return 0;
            }
        }

        int getNumberOfNodesrec(TreeNode* current){
             if(current != nullptr){
                int left = getNumberOfNodesrec(current->left);
                int right = getNumberOfNodesrec(current->right);
                return left + right + 1;
            }else{
                return 0;
            }
        }

};

#endif