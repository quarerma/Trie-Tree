#include "Trie.h"


int main(int argc, char *argv[]){
    

    Trie *arvore = new Trie();


    arvore->insert("barbara");
    arvore->insert("melhor");
    arvore->insert("professora");

    cout << "Buscando barbara: " << arvore->search("barbara") << endl;
    cout << "Buscando melhor: " << arvore->search("melhor") << endl;
    cout << "Buscando professora: " << arvore->search("professora") << endl;

    cout << "Buscando prof: " << arvore->search("prof") << endl;

    arvore->insert("mel");
    arvore->deletion("melhor");

    cout << "Buscando melhor depois de deletar: " << arvore->search("melhor") << endl;
    cout << "Buscando mel: " << arvore->search("mel") << endl;
    
    return 0;
}