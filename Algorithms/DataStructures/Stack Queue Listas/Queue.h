template <class T>

class Queue{
    public:
        Queue();
        ~Queue();
        void push(T data);
        T pop();
        T peek();
        bool isEmpty();

    private:
        node<T> *last;
        int length;
};

template <typename T>
Queue<T>::Queue(){
    last=NULL;
}

template <typename T>
Queue<T>::~Queue(){
    if(last != NULL){
        node<T> *aux=last->getNext();
        last->setNext(NULL);
        last=aux;

        while(last!=NULL){
            aux=last;
            last=last->getNext();
            delete aux;
        }

    }
}

template <typename T>
T Queue<T>::peek(){
    if (this->isEmpty()){
		return NULL;
	}
	else{
		T infoaux = last->getNext()->getData();
		return infoaux;
	}
}

template <typename T>
T Queue<T>::pop(){
    if (this->isEmpty()){
		return NULL;
	}

	T infoaux = last->getNext()->getData();
    node<T> *aux=last->getNext();
	if(last->getNext()==last){
        last=NULL;
	}else{
        last->setNext(aux->getNext());

	}
	delete aux;
	return infoaux;
}



template <typename T>
void Queue<T>::push(T data){
    if(this->isEmpty()){
        last= new node<T>(data);
        last->setNext(last);
    }else{
        node<T> *aux=new node<T>(data,last->getNext());
        last->setNext(aux);
        last=aux;
    }
}

template <typename T>
bool Queue<T>::isEmpty(){
	return last==NULL;
}
