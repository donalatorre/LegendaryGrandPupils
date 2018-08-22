/**
 ** Trie
 ** Solo para para letras minusculas
 **
**/

class trie{
    public:
        trie();
        ~trie();
        bool isEmpty();
        void addWord(string word);
        int countPrefixes(string word);
        int countWords();
        int countWords(string word);
        int cuentaPalabras(nodeT *node);
        int getCantPalabras();
        void setCantPalabras(int cantPalabras);

    private:
        nodeT *root;
        int cantPalabras;
};


trie::trie() {
    root = NULL;
    cantPalabras = 0;
}

trie::~trie() {

}

void trie::addWord(string word) {
    if (word == "")
        return;

    if(this->isEmpty()) {
        root = new nodeT();
    }

    nodeT *aux = root;

    while(word.length() > 0) {
        if (aux->isSonNull(word[0] - 'a')) {
            aux->setNewNode(new nodeT(), word[0] - 'a');
        }
        aux = aux->getSon(word[0] - 'a');
        aux->setPrefixes(aux->getPrefixes() + 1);


        word = word.substr(1);
    }

    aux->setWords(aux->getWords() + 1);

    this->setCantPalabras(this->getCantPalabras() + 1);
}

int trie::countPrefixes(string word) {
    if(this->isEmpty()) {
        return 0;
    }

    nodeT *aux = root;

    while (word.length() > 0 && !aux->isSonNull(word[0] - 'a')) {
        aux = aux->getSon(word[0] - 'a');
        word = word.substr(1);
    }

    if (word.length() == 0)
        return aux->getPrefixes();
    return 0;
}

int trie::countWords() {
    if(this->isEmpty()){
        return 0;
    }

    return cuentaPalabras(this->root);
}

int trie::cuentaPalabras(nodeT *node) {
    int cant = 0;

    for(int i = 0; i < 26; i++) {
        if (!node->isSonNull(i))
            cant += cuentaPalabras(node->getSon(i));
    }

    return cant + node->getWords();
}

int trie::countWords(string word) {
    if(this->isEmpty()){
        return 0;
    }

    nodeT *aux = root;

    while (word.length() > 0 && !aux->isSonNull(word[0]) - 'a') {
        aux = aux->getSon(word[0] - 'a');
        word = word.substr(1);
    }

    if (word.length() == 0)
        return aux->getWords();
    return 0;
}


int trie::getCantPalabras() {
    return this->cantPalabras;
}

void trie::setCantPalabras(int cantPalabras) {
    this->cantPalabras = cantPalabras;
}

bool trie::isEmpty(){
    return (root==NULL);
}
