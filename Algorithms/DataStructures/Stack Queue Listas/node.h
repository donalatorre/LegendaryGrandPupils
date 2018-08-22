template <class T>

class node{
    public:
        node(T d);
        node(T d, node<T> *n);
        T getData();
        node<T>* getNext();
        void setData(T d);
        void setNext(node<T> *n);



    private:
        T data;
        node<T> *next;
};

template <typename T>
node<T> :: node(T d){
    this->data=d;
    this->next=NULL;
}

template <typename T>
node<T> :: node(T d, node<T> *n){
    this->data=d;
    this->next=n;
}

template <typename T>
T node<T> :: getData(){
    return this->data;
}

template <typename T>
node<T>* node<T> :: getNext(){
    return this->next;
}

template <typename T>
void node<T> :: setData(T d){
    this->data=d;
}

template <typename T>
void node<T> :: setNext(node<T> *n){
    this->next=n;
}
