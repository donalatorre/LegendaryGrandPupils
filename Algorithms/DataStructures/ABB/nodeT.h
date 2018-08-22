

class nodeT{
    public:
        nodeT(int data);
        nodeT(int data, nodeT *left, nodeT *right);
        int getInfo();
        nodeT* getLeft();
        nodeT* getRight();
        void setInfo(int data);
        void setLeft(nodeT *left);
        void setRight(nodeT *right);
    private:
        int info;
        nodeT *left;
        nodeT *right;
};

nodeT::nodeT(int data){
    this->info=data;
    this->left=NULL;
    this->right=NULL;
}

nodeT::nodeT(int data, nodeT *left, nodeT *right){
    this->info=data;
    this->left=left;
    this->right=right;
}

int nodeT::getInfo(){
    return this->info;
}

nodeT* nodeT::getLeft(){
    return left;
}

nodeT* nodeT::getRight(){
    return right;
}

void nodeT::setInfo(int data){
    this->info=data;
}

void nodeT::setLeft(nodeT *left){
    this->left=left;
}

void nodeT::setRight(nodeT *right){
    this->right=right;
}
