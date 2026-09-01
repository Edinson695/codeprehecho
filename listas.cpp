#include <iostream>

template<typename data_type>
struct nodo {
    data_type data;
    nodo* next;

    nodo(){ next = nullptr; }
    nodo(data_type data, nodo<data_type>* next = nullptr) : data(data), next(next) {}
};

template<typename data_type>
struct nodoDoble{
    data_type data;
    nodoDoble* next;
    nodoDoble* prev;

    nodoDoble(){ next = prev = nullptr; }
};

template<typename data_type>
struct lista {
    nodo<data_type>* head;
    nodo<data_type>* tail;

    lista() { head = tail = nullptr; }

    void push_front(data_type value){
        nodo<data_type>* new_node = new nodo<data_type>(value, head);
        
        if (head == nullptr){
            tail = new_node;
        }

        head = new_node;
    }

    void push_back(data_type value){
        if (tail == nullptr){
            head = tail = new nodo<data_type>(value);
        } else {
            tail->next = new nodo<data_type>(value);
            tail = tail->next;
        }
    }
    void insert(nodo<data_type>* node, data_type value){
        //inserta nodo con data dps del nodo "node"
        //dps del nodo "node" que no es nulo 
        //le pasas un nodo de la lista y le inserto un nodo nuevo con el valor dado
        nodo<data_type>* new_node = new nodo<data_type>(value, node->next);
        if (node == tail){
            tail = new_node;
        }

        node->next = new_node;
    }
    void insertk(int k, data_type value) {
        if (k == 0) { push_front(value);}
        else{
            nodo<data_type>* current = head;
            for (int i = 1; i < k - 1; ++i){
                current = current->next;
            }
            insert(current, value);
        }
    }

    void pop_front(){
        nodo<data_type>* current = head;
        head = head->next;
        if (head == nullptr) {tail = nullptr;}
        delete current;

    }
    void erase(nodo<data_type>* node){
        //elimina el siguiente al node
        if (node->next){
            nodo<data_type> current = node->next;
            if (node->next == tail){
                tail = node;
            }
            node->next = node->next->next;
            delete current;
        }
        if (node = head){
            pop_front(node);
        }
    }
    void erase(int k){
        if (k == 0) { pop_front();}
        else {
            nodo<data_type>* current = head;
            for (int i = 1; i <= k - 1; ++i){
                current = current->next;
            }
            erase(current);
        }
    }
    void print()
    {
        nodo<data_type> *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

template<typename data_type>
struct listaDoble{
    nodoDoble<data_type>* head;
    nodoDoble<data_type>* tail;
    listaDoble(){ head = tail = nullptr;}

    listaDoble(data_type value, nodoDoble<data_type>* node): head(node), tail(node) {}

    void push_front(data_type value){
        nodoDoble<data_type>* new_node = new listaDoble<data_type>(value, head);
        if (head == nullptr){
            tail = new_node;
        } else {
            head.prev = new_node;
        }
    }

    void erase(nodoDoble<data_type>* node){
        if (node == head){
            if (head == tail){
                delete node;
                head = tail = nullptr;
            }
        
            else {
                tail = tail->prev;
                tail->next = nullptr;
                delete node;
            }
        }
        else if (node == tail){
            tail = tail->prev;
            tail->next = nullptr;
            delete node;
        }
        else {
            nodoDoble<data_type>* predecessor = node->prev;
            nodoDoble<data_type>* successor =  node->next;
            predecessor->next = successor;
            successor->prev = predecessor;
            delete node;
        }
    }

    void delete_first(data_type key){
        nodoDoble<data_type>* current = head;
        while (current != nullptr){
            if (current->data == key){
                erase(current);
                break;
            }
        }
    }
};

class listaCircular{

};


int main(){
    lista<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(0);
    L.push_back(0);
    L.print();
    L.pop_front();
    L.print();
    L.erase(2);
    L.print();
    return 0;
}