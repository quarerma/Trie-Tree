#include <iostream>
#include <string>

using namespace std;
class Trie
{    
public:
    bool isKey;
    Trie* data[128];
    Trie* root = this;
     
    Trie()
    {
        this->isKey = false;
        for (size_t i = 0; i < 128; i++)
        {
            this->data[i] = nullptr;
        }
    }

    void insert(string);
    void deletion(string key){ Auxdeletion(root, key); }
    bool Auxdeletion(Trie*&,string);
    bool search(string);
    bool haveKeys(Trie const*);
};

void Trie::insert(string key){

    
    Trie* current = root;
    for (int i = 0; i < key.length(); i++)
    {
        
        if (current->data[key[i]] == nullptr) {
            current->data[key[i]] = new Trie();
        }
 

        current = current->data[key[i]];
    }
 

    current->isKey = true;
}

bool Trie::search(string str){
    if (root == nullptr)
    {
        return false; //arvore vazia
    }
    Trie *current = root;
    for (int i = 0; i < str.length(); i++)
    {
        current = current->data[str[i]];

        if(current == nullptr){
            return false;
        }
    }
    
    return current->isKey;
}

bool Trie::haveKeys(Trie const* current){
    for (int i = 0; i < 128; i++)
    {
        if(current->data[i] != nullptr)
            return true;
    }

    return false;   
}

bool Trie::Auxdeletion(Trie*& current, string str){

    if(current == nullptr) return false;

    if(str.length())
    {

        if(current != nullptr && current->data[str[0]] != nullptr && Auxdeletion(current->data[str[0]], str.substr(1)) && !current->isKey)
        {
            if(!haveKeys(current))
            {
                delete current;
                current = nullptr;
                return true;
            }
            else return false;
        }
    }

    if(current->isKey && str.length() == 0)
    {
        if(!haveKeys(current))
        {
            delete current;
            current = nullptr;

            return true;
        }

        else
        {
            current->isKey = false;

            return false;
        }
    }

    return false;
}
