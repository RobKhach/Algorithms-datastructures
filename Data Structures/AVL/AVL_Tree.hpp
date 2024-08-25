#include "AVL_Tree.h"

template <arithmetic T>
AVLTree<T>::TreeNode::TreeNode(T val): left(nullptr), right(nullptr), value(val), height(1){}

template <arithmetic T>
AVLTree<T>::AVLTree():root(nullptr){}

template <arithmetic T>
AVLTree<T>::AVLTree(const AVLTree& other){
    root = nullptr;
    copyTree(other.root); 
}

template <arithmetic T>
AVLTree<T>::AVLTree(AVLTree&& other){
    root = other.root;
    other.root = nullptr;
}

template <arithmetic T>
AVLTree<T>::AVLTree(T val){
    root = new TreeNode(val);
}

template <arithmetic T>
AVLTree<T>::AVLTree(std::initializer_list<T> list): root(nullptr){
    for(const auto& i : list){
        insert(i); //Implement INSERT
    }
}

template <arithmetic T>
template <AllSameAs<T>... Args>
AVLTree<T>::AVLTree(Args... args):root(nullptr){
    (insert(args), ...); //Implement Insert
}

template <arithmetic T>
AVLTree<T>::~AVLTree(){
    destroy(root);
}

template <arithmetic T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree& other){
    if(this != &other){

        destroy(root); 
        copyTree(other.root); 
    
        return *this;
    }else{

        return *this;
    }
}

template <arithmetic T>
AVLTree<T>& AVLTree<T>::operator=(AVLTree&& other){
    if(this != &other){
        destroy(root); 
        root = other.root;
        other.root = nullptr;

        return *this;
    }else{
        return *this;
    }
}

template <arithmetic T>
int AVLTree<T>::getHeight() const{
    return getHeight(root);
}

template <arithmetic T>
int AVLTree<T>::getBalance() const{
    return getBalance(root); 
}

template <arithmetic T>
void AVLTree<T>::insert(const T& val){
    root =  insert(root, val);
}


template <arithmetic T>
void AVLTree<T>::remove(const T& val){
    root = deleteNode(root, val); //IMPLEMENT DELETENODE
}

template <arithmetic T>
bool AVLTree<T>::search(const T& val) const{
    TreeNode* ptr = search(root, val); 
    return ptr ? true : false;
}

template <arithmetic T>
T AVLTree<T>::minVal() const{
    TreeNode* ptr = minValueNode(root); 
    if(ptr){
        return ptr->value;
    }else{
        throw std::runtime_error("The tree is empty, no minimum value exists.");
    }
}

template <arithmetic T>
T AVLTree<T>::maxVal() const{
    TreeNode* ptr = maxValueNode(root); 
    if(ptr){
        return ptr->value;
    }else{
        throw std::runtime_error("The tree is empty, no maximum value exists.");
    }
}

template <arithmetic T>
void AVLTree<T>::inorder() const{
    inOrderTraverse(root); 
}

template <arithmetic T>
void AVLTree<T>::postorder() const{
    postOrderTraverse(root); 
}

template <arithmetic T>
void AVLTree<T>::preorder() const{
    preOrderTraverse(root); 
}

template <arithmetic T>
bool AVLTree<T>::isEmpty() const{
    return root ? false : true;
}

template <arithmetic T>
void AVLTree<T>::clear(){
    destroy(root);
    root = nullptr; 
}

template <arithmetic T>
void AVLTree<T>::copyTree(TreeNode* node){
    if(!node){
        return;
    }

    copyTree(node->left);
    insert(node->value);
    copyTree(node->right);

}

template <arithmetic T>
int AVLTree<T>::getHeight(TreeNode* node) const{
    return node ? node->height : 0;
}

template <arithmetic T>
int AVLTree<T>::getBalance(TreeNode* node) const{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

template <arithmetic T>
AVLTree<T>::TreeNode* AVLTree<T>::minValueNode(TreeNode* node) const{
    
    if(!node){
        return nullptr;
    }

    while(node->left != nullptr){
        node = node->left;
    }

    return node;
}

template <arithmetic T>
AVLTree<T>::TreeNode* AVLTree<T>::maxValueNode(TreeNode* node) const{
    if(!node){
        return nullptr;
    }

    while(node->right != nullptr){
        node = node->right;
    }

    return node;
}

template <arithmetic T>
void AVLTree<T>::inOrderTraverse(TreeNode* node) const{
    if(!node){
        return;
    }

    inOrderTraverse(node->left);
    std::cout << node->value << " ";
    inOrderTraverse(node->right);

}

template <arithmetic T>
void AVLTree<T>::preOrderTraverse(TreeNode* node) const{
    if(!node){
        return;
    }

    std::cout << node->value << " ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);

}

template <arithmetic T>
void AVLTree<T>::postOrderTraverse(TreeNode* node) const{
    if(!node){
        return;
    }

    postOrderTraverse(node->left);
    postOrderTraverse(node->right);
    std::cout << node->value << " ";

}

template <arithmetic T>
typename AVLTree<T>::TreeNode* AVLTree<T>::search(TreeNode* node, const T& val) const {
    if (!node) {
        return nullptr;
    }
    if (node->value == val) {
        return node;
    }
    if (node->value < val) {
        return search(node->right, val);
    } else {
        return search(node->left, val);
    }
}

template <arithmetic T>
void AVLTree<T>::destroy(TreeNode* node){
    if(!node){
        return; 
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
    node = nullptr;
}

template <arithmetic T>
AVLTree<T>::TreeNode* AVLTree<T>::rightRotate(TreeNode* node){
    if(!node){
        return node;
    }

    TreeNode* x = node->left;
    TreeNode* tmp = x->right;
    x->right = node;
    node->left = tmp;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

template <arithmetic T>
AVLTree<T>::TreeNode* AVLTree<T>::leftRotate(TreeNode* node){
    if(!node){
        return node;
    }

    TreeNode* y = node->right;
    TreeNode* tmp = y->left;
    y->left = node;
    node->right = tmp;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}


template <arithmetic T>
typename AVLTree<T>::TreeNode* AVLTree<T>::insert(TreeNode* node, const T& val) {
    if (node == nullptr) {
        return new TreeNode(val);
    }

    if (val < node->value) {
        node->left = insert(node->left, val);
    } else if (val > node->value) {
        node->right = insert(node->right, val);
    } else {
        return node;
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);


    if (balance > 1 && val < node->left->value) {
        return rightRotate(node);
    }

    if (balance < -1 && val > node->right->value) {
        return leftRotate(node);
    }

    if (balance > 1 && val > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && val < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <arithmetic T>
typename AVLTree<T>::TreeNode* AVLTree<T>::deleteNode(TreeNode* node, const T& val) {
    if (node == nullptr) {
        return node;
    }

    if (val < node->value) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->value) {
        node->right = deleteNode(node->right, val);
    } else {

        if ((node->left == nullptr) || (node->right == nullptr)) {
            TreeNode* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else { 
                *node = *temp; 
            }

            delete temp;
        } else {
            TreeNode* temp = minValueNode(node->right);

            node->value = temp->value;

            node->right = deleteNode(node->right, temp->value);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}








