#include <vector>

#include "node.h"

template <class T>
class LinkedList{
	public:
		int length;
		LinkedList();
		~LinkedList();
		bool isEmpty();
		void addFirst(T data);
		void addLast(T data);
		bool add(T data, int pos);
		T deleteFirst();
		T deleteLast();
		int deleteAll();
		T del(int pos);
        T get(int pos);

		void print();
		void revers();
		bool shift(int a);
		void operator=(const LinkedList<T> &ll);
		bool operator==(const LinkedList<T> &l);
        void operator+=(T data);
        void operator+=(const LinkedList<T> &l);
        LinkedList(const LinkedList<T> &l);

	private:
		node<T> *head;
		void delAll();
};

template <typename T>
void LinkedList<T>::delAll(){
	node<T> *aux;
	while (head != NULL){
		aux = head;
		head = head->getNext();
		delete aux;
	}
	length=0;
}

template <typename T>
LinkedList<T>::LinkedList(){
	head = NULL;
	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	this->delAll();
}

template <typename T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}

template <typename T>
void LinkedList<T>::addFirst(T data){
	node<T> *aux = new node<T>(data, head);
	head = aux;
	length++;
}

template <typename T>
void LinkedList<T>::addLast(T data){
	if (this->isEmpty()){
		this->addFirst(data);
	}else{
		node<T> *aux = head;
		while (aux->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		node<T> *nuevo = new node<T>(data);
		aux->setNext(nuevo);
		length++;
	}
}

template <typename T>
bool LinkedList<T>::add(T data, int pos){
	if (pos < 0 || pos > this->length){
		return false;
	}
	else{
		if (pos == 0){
			this->addFirst(data);
		}else if (pos == this->length){
			this->addLast(data);
		}else{
			node<T> *aux1 = head;
			node<T> *aux2;
			for (int i=1; i<pos; i++){
				aux1 = aux1->getNext();
			}
			aux2 = aux1->getNext();
			node<T> *nuevo = new node<T>(data, aux2);
			aux1->setNext(nuevo);
		}
		//this->length++;
		return true;
	}
}

template <typename T>
T LinkedList<T>::deleteFirst(){
	if (this->isEmpty()){
		return NULL;
	}
	else{
		node<T> *aux = head;
		T infoaux = head->getData();
		head = head->getNext();
		delete aux;
		this->length--;
		return infoaux;
	}
}

template <typename T>
T LinkedList<T>::deleteLast(){
	if (this->length <= 1){
		return this->deleteFirst();
	}else{
		node<T> *aux1 = head;
		node<T> *aux2;
		while (aux1->getNext()->getNext() != NULL){
			aux1 = aux1->getNext();
		}
		aux2 = aux1->getNext();
		T infoaux = aux2->getData();
		delete aux2;
		aux1->setNext(NULL);
		this->length--;
		return infoaux;
	}
}

template <typename T>
int LinkedList<T>::deleteAll(){
	this->delAll();
	int total = length;
	length = 0;
	return total;
}

template <typename T>
T LinkedList<T>::del(int pos){
	if (pos < 0 || pos >= this->length){
		return NULL;
	}
	else{
		if (pos == 0){
			return this->deleteFirst();
		}
		else if (pos == this->length-1){
			return this->deleteLast();
		}
		else{
			node<T> *aux1 = head;
			node<T> *aux2;
			for (int i=1; i<pos; i++){
				aux1 = aux1->getNext();
			}
			aux2 = aux1->getNext();
			aux1->setNext(aux2->getNext());
			T infoaux = aux2->getData();
			delete aux2;
			this->length--;
			return infoaux;
		}
	}
}

template <typename T>
T LinkedList<T>::get(int pos){
	if (pos < 0 || pos >= this->length){
		return NULL;
	}
	else{
		node<T> *aux = head;
		for (int i=1; i<=pos; i++){
			aux = aux->getNext();
		}
		T infoaux = aux->getData();
		return infoaux;
	}
}

template <typename T>
void LinkedList<T>::print(){
    cout << "Lista: " << endl;
    if(this->length<=0){
        cout << " -- Vacia -- " << endl;
    }else{
        node<T> *aux1 = head;
        while(aux1->getNext() !=NULL){
            cout << aux1->getData() << endl;
            aux1 = aux1->getNext();
        }
        cout << aux1->getData() << endl;
    }
    cout << endl;
}

template <typename T>
void LinkedList<T>::revers(){
    if(this->length <= 0){

    }else if(this->length == 1){

    }else{
        node<T> *aux1 = head;
        node<T> *aux2 = aux1->getNext();
        node<T> *aux3;

        aux1->setNext(NULL);

        while(aux2->getNext()!=NULL){
            aux3=aux1;
            aux1=aux2;
            aux2=aux2->getNext();
            aux1->setNext(aux3);
        }
        aux3=aux1;
        aux1=aux2;
        aux1->setNext(aux3);

        head=aux2;

    }

}

template <typename T>
bool LinkedList<T>::shift(int a){
    if(this->length == 0){

    }else if(a!=0){
        a=(a%this->length);

        if(a<0)
            a+=length;
        node<T> *aux1 = head;
        node<T> *aux2 = head;

        int i=0;
        while(i<a){
            aux1=aux1->getNext();
            i++;
            //cout << i << endl;
        }

        head=aux1;
        while(aux1->getNext() != NULL){
            //cout << aux1->getData() << endl;
            aux1=aux1->getNext();
            i++;
            //cout << i << endl;
        }

        i=0;

        while(i<a){
            //cout << i << endl;
            node<T> *nuevo = new node<T>(aux2->getData());//cout << i << endl;
            //cout << aux2->getData() << endl;
            aux1->setNext(nuevo);//cout << i << endl;
            aux1=aux1->getNext();
            aux2=aux2->getNext();
            i++;
        }


        //aux2=aux2->setNext(NULL);
    }
}

template <typename T>
void LinkedList<T>::operator=(const LinkedList<T> &ll){
    if(ll.length==0){
        this->deleteAll();
    }else{
        this->deleteAll();
        node<T> *aux2=ll.head;
        node<T> *aux = new node<T>(aux2->getData());
        this->head = aux;
        length++;

        //cout << ll.length << " " << this->length << endl;
        for(int i=1; i<ll.length; i++){
            aux2 = aux2->getNext();
            node<T> *nuevo = new node<T>(aux2->getData());
            aux->setNext(nuevo);
            aux=aux->getNext();
            this->length++;
            //cout <<  i  << this->length << endl;
        }

        //cout << ll.length << " " << this->length << endl;
        //cout << aux->getData() << endl;
    }
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &l){
    //cout << l.length << "  " << this->length << endl;
    if(l.length!=this->length){
        return false;
    }else{

        node<T> *aux1=l.head;
        node<T> *aux2=this->head;
        //cout << aux1->getData() << "  " << aux2->getData() << endl;


        for(int i=0; i<this->length; i++){
/*
            if(l.get(i)!=this->get(i))
                return false;
            */
            aux1=aux1->getNext();
            aux2=aux2->getNext();
            //cout << i << endl;

        }
    }

    return true;
}

template <typename T>
void LinkedList<T>::operator+=(T data){
    this->addLast(data);
}

template <typename T>
void LinkedList<T>::operator+=(const LinkedList<T> &l){
    node<T> *aux = this->head;
    node<T> *aux2=l.head;

    while(aux->getNext()!=NULL){
        aux=aux->getNext();
    }

    //cout << ll.length << " " << this->length << endl;
    for(int i=0; i<l.length; i++){
        node<T> *nuevo = new node<T>(aux2->getData());
        aux->setNext(nuevo);
        aux=aux->getNext();
        aux2=aux2->getNext();
        this->length++;
        //cout <<  i  << this->length << endl;
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &l){
	head = NULL;
	length = 0;

    node<T> *aux2=l.head;
    this->addFirst(aux2->getData());
    aux2=aux2->getNext();
    node<T> *aux = this->head;

    //cout << l.length << " " << this->length << endl;
    for(int i=1; i<l.length; i++){
        node<T> *nuevo = new node<T>(aux2->getData());
        aux->setNext(nuevo);

        aux=aux->getNext();
        aux2=aux2->getNext();
        this->length++;
        //cout <<  i  << this->length << endl;
    }
}
