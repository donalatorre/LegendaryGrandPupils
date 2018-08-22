
class BST{
    public:
        BST();
        ~BST();
        bool find(int data);
        bool add(int data);
        bool del(int data);
        void print(int num);
        bool isEmpty();
        void printLeaf();
        int count();
        int height();
        void ancestors(int d);
        int wherelevelIam(int data);
        int maxwitdh();
        int nearestParent(int a, int b);
        bool isBST();

    private:
        nodeT *root;
        int howManyChildern(nodeT *aux);
        void preorden(nodeT *r);
        void inorden(nodeT *r);
        void postorden(nodeT *r);
        void porNivel(nodeT *r);
        int prev(nodeT *r);
        int next(nodeT *r);
        bool printLeafs(nodeT *r);
        int counts(nodeT *r);
        int obtHeight(int a, nodeT *r);
        bool obtAncestors(int d, nodeT *r);
        bool revisaBST(nodeT *r);
};

BST::BST(){
    root = NULL;
}

BST::~BST(){

}

bool BST::find(int data){
    if(this->isEmpty())
        return false;

    nodeT *aux=root;

    while(aux!=NULL){
        if (aux->getInfo()==data){
            return true;
        }

        if(aux->getInfo() > data) aux=aux->getLeft();
        else aux=aux->getRight();
    }

    return false;
}

bool BST::add(int data){
    if(this->isEmpty()){
        root=new nodeT(data);
        return true;
    }

    nodeT *father=NULL;
    nodeT *aux=root;

    while(aux!=NULL){
        if (aux->getInfo()==data){
            return false;
        }

        father=aux;

        if(aux->getInfo() > data) aux=aux->getLeft();
        else aux=aux->getRight();
    }

    if(father->getInfo() > data)
        father->setLeft(new nodeT(data));
    else
        father->setRight(new nodeT(data));
    return true;
}

void BST::print(int num){
    switch(num){
        case 1: preorden(root);
                break;
        case 2: inorden(root);
                break;
        case 3: postorden(root);
                break;
        case 5: porNivel(root);
                break;
        default:
                break;
    }
    cout << endl;
}

void BST::preorden(nodeT *r){
    if(r != NULL){
        cout << r->getInfo() << " ";
        preorden(r->getLeft());
        preorden(r->getRight());
    }
}

void BST::inorden(nodeT *r){
    if(r != NULL){
        inorden(r->getLeft());
        cout << r->getInfo() << " ";
        inorden(r->getRight());
    }
}

void BST::postorden(nodeT *r){
    if(r != NULL){
        postorden(r->getLeft());
        postorden(r->getRight());
        cout << r->getInfo() << " ";
    }
}

void BST::porNivel(nodeT *r){
    if(r == NULL){
        cout << "ABB vacio " << endl;
        return;
    }

    int i=1,j=0;
    queue<nodeT *> cola;
    cola.push(r);

    do{
        while(i){
            nodeT *aux1, *aux2, *aux3;
            aux1=cola.front();
            cola.pop();

            cout << aux1->getInfo() << " ";

            aux2=aux1->getLeft();
            if(aux2!=NULL){
                cola.push(aux2);
                j++;
            }

            aux3=aux1->getRight();
            if(aux3!=NULL){
                cola.push(aux3);
                j++;
            }

            i--;
        }
        i=j;
        j=0;
    }while(!cola.empty());

}

int BST::howManyChildern(nodeT *aux){
    int cont=0;
    if(aux->getLeft()!=NULL)
        cont++;
    if(aux->getRight()!=NULL)
        cont++;
    return cont;
}

bool BST::isEmpty(){
    return (root==NULL);
}


bool BST::del(int data){
    nodeT *aux=root;
    nodeT *father = NULL;

    while(aux!=NULL && aux->getInfo()!=data){
        father=aux;

        if(aux->getInfo() > data) aux=aux->getLeft();
        else aux=aux->getRight();
    }

    if(aux==NULL)
        return false;

    int cantHijos=howManyChildern(aux);

    if(cantHijos==0){
        if(father == NULL){
            delete root;
            root= NULL;
        }else{
            if(father->getInfo() > data)
                father->setLeft(NULL);
            else
                father->setRight(NULL);
        }
    }else if(cantHijos==1){
        if(father == NULL){
            if(aux->getLeft()!=NULL)
                root=aux->getLeft();
            else
                root=aux->getRight();
        }else{
            if(father->getInfo() > aux->getInfo())
                if(aux->getLeft()!=NULL)
                    father->setLeft(aux->getLeft());
                else
                    father->setLeft(aux->getRight());
            else
                if (aux->getLeft() != NULL)
					father->setRight(aux->getLeft());
				else
					father->setRight(aux->getRight());
        }

        delete aux;
    }else{
        int s=next(aux);
        del(s);
        aux->setInfo(s);
    }

    return true;
}

int BST::prev(nodeT *r){
    nodeT *aux= r->getLeft();

    while(aux->getRight() != NULL)
        aux=aux->getRight();

    return aux->getInfo();
}

int BST::next(nodeT *r){
    nodeT *aux=r->getRight();

    while(aux->getLeft() != NULL)
        aux=aux->getLeft();

    return aux->getInfo();
}

void BST::printLeaf(){
    if(this->root == NULL)
        cout << "No hay nodos" << endl;
    else{
        printLeafs(root);
        cout << endl;
    }
}

bool BST::printLeafs(nodeT *r){
    if(r == NULL){
        return true;
    }

    bool a=printLeafs(r->getLeft());
    bool b=printLeafs(r->getRight());

    if(a && b)
        cout << r->getInfo() << " ";

    return false;
}


int BST::count(){
    return counts(root);
}

int BST::counts(nodeT *r){
    if(r == NULL){
        return 0;
    }

    return 1 + counts(r->getLeft()) + counts(r->getRight());
}

int BST::obtHeight(int a, nodeT *r){
    if(r == NULL){
        return a;
    }

    int b=obtHeight(a+1,r->getLeft());
    int c=obtHeight(a+1,r->getRight());

    if(b>c)
        return b;
    else
        return c;
}

int BST::height(){
    return obtHeight(0,root);
}

bool BST::obtAncestors(int d, nodeT *r){
    if(r==NULL){
        cout << "No existe el dato";
        return false;
    }


    if (r->getInfo()==d){
        return true;
    }

    if(r->getInfo() > d){
        if(obtAncestors(d,r->getLeft()))
            cout << r->getInfo() << " ";
    }else{
        if(obtAncestors(d,r->getRight()))
            cout << r->getInfo() << " ";
    }

}

void BST::ancestors(int d){
    if(this->isEmpty()){
        cout << "ABB vacio" << endl;
        return;
    }else if(root->getInfo() == d){
        cout << "El dato es el raiz" << endl;
        return;
    }

    cout << "ABB: ";
    obtAncestors(d,root);
    cout << endl;
}

int BST::wherelevelIam(int data){
    if(this->isEmpty())
        return -1;

    nodeT *aux=root;

    int i=0;

    while(aux!=NULL){
        if (aux->getInfo()==data){
            return i;
        }

        if(aux->getInfo() > data) aux=aux->getLeft();
        else aux=aux->getRight();

        i++;
    }

    return -1;
}


int BST::maxwitdh(){
    nodeT *r=root;

    if(r == NULL){
        cout << "ABB vacio" << endl;
        return -1;
    }

    int i=1,j=0,maxW=1;
    queue<nodeT *> cola;
    cola.push(r);

    do{
        while(i){
            nodeT *aux1, *aux2, *aux3;
            aux1=cola.front();
            cola.pop();

            aux2=aux1->getLeft();
            if(aux2!=NULL){
                cola.push(aux2);
                j++;
            }

            aux3=aux1->getRight();
            if(aux3!=NULL){
                cola.push(aux3);
                j++;
            }

            i--;


        }
        i=j;
        j=0;

        if(i>maxW)
            maxW=i;

    }while(!cola.empty());

    return maxW;
}


int BST::nearestParent(int a, int b){
    if(this->root==NULL)
        return -1;

    nodeT *aux=this->root;

    if(aux->getInfo()==a || aux->getInfo()==b){
        return -1;
    }

    queue<int> filaA,filaB;

    do{


        if(aux->getInfo() == a){
            break;
        }

        filaA.push(aux->getInfo());

        if(aux->getInfo() > a){
            aux=aux->getLeft();
        }else{
            aux=aux->getRight();
        }

    }while(aux!=NULL && aux->getInfo()!=a);

    if(aux==NULL)
        return -1;

    aux=this->root;

    do{
        if(aux->getInfo() == b){

            break;
        }
        filaB.push(aux->getInfo());

        if(aux->getInfo() > b){
            aux=aux->getLeft();
        }else{
            aux=aux->getRight();
        }

    }while(aux!=NULL && aux->getInfo()!=b);

    if(aux==NULL)
        return -1;

    int c;
    while( !filaA.empty() && !filaB.empty() ){
        //cout << filaA.front() << " " << filaB.front() << endl;
        if(filaA.front()==filaB.front()){
            c=filaA.front();
            filaA.pop();
            filaB.pop();

        }else{
            return c;
        }
    }
    return c;
}

bool BST::isBST(){
    if(this->isEmpty()){
        return true;
    }

    return revisaBST(root);
}

bool BST::revisaBST(nodeT *r){
    if(r==NULL)
        return true;

    if(r->getLeft()!=NULL)
        if(r->getLeft()->getInfo()<r->getInfo()){ revisaBST(r->getLeft()); }
        else{   return false; }


    if(r->getRight()!=NULL)
        if(r->getRight()->getInfo() > r->getInfo()){ revisaBST(r->getRight()); }
        else{   return false; }


    return true;
}
