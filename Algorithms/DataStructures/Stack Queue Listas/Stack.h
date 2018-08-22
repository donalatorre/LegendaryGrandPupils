template <class T>

class Stack{
    public:
        Stack();
        ~Stack();
        void push(T data);
        T pop();
        T peek();
        bool isEmpty();

    private:
        node<T> * top;
        int length;
};

template <typename T>
Stack<T>::Stack(){
    top=NULL;
}

template <typename T>
Stack<T>::~Stack(){
    node<T> *aux;

    while(top!=NULL){
        aux=top;
        top=top->getNext();
        delete aux;
    }
}

template <typename T>
void Stack<T>::push(T data){
    node<T> *aux= new node<T>(data, top);
    top=aux;
}

template <typename T>
T Stack<T>::pop(){
    if (this->isEmpty()){
		return NULL;
	}
	else{
		node<T> *aux = top;
		T infoaux = top->getData();
		top = top->getNext();
		delete aux;
		this->length--;
		return infoaux;
	}
}

template <typename T>
T Stack<T>::peek(){
    if (this->isEmpty()){
		return NULL;
	}
	else{
		T infoaux = top->getData();
		return infoaux;
	}
}

template <typename T>
bool Stack<T>::isEmpty(){
	return top==NULL;
}
