
class nodeT{
    public:
        nodeT();
        int getWords();
        int getPrefixes();
        void setWords(int cant);
        void setPrefixes(int cat);
        void setNewNode(nodeT *node, int pos);
        nodeT* getSon(int pos);
        bool isSonNull(int pos);

    private:
        int caracter;
        int words;
        int prefixes;
        nodeT *son[26];
};

nodeT::nodeT(){
    this->caracter = -1;
    this->words = 0;
    this->prefixes = 0;

    for(int i = 0; i < 26; i++) {
        this->son[i] = NULL;
    }
}

int nodeT::getWords() {
    return this->words;
}

int nodeT::getPrefixes() {
    return this->prefixes;
}

void nodeT::setWords(int cant) {
    this->words = cant;
}

void nodeT::setPrefixes(int cant) {
    this->prefixes = cant;
}

void nodeT::setNewNode(nodeT *node, int pos) {
    this->son[pos] = node;
}

nodeT* nodeT::getSon(int pos) {
    return this->son[pos];
}

bool nodeT::isSonNull(int pos){
    return this->son[pos] == NULL;
}
