#include <iostream>

class nodo{
    private:
    int elemento;
    nodo* siguiente;
    /*Aca el compilador, al igual que los tipos de datos, asigna una cierta cantidad de memoria, 
        pero en si nodo no esta predeterminado, por eso se le asigna como un puntero, para que guarde su direccion,
        aca solo nos fijamos en direccion pq tamaño no sabemos. 
    */
    public:
    nodo(){}
    nodo(int elemnt): elemento(elemnt), siguiente(nullptr) {}

    int getElemento() { return elemento; }
    nodo* getSiguiente() { return siguiente; }
    void setSiguiente(nodo* n) { siguiente = n;}
};

class lista {
    private:
    nodo* cabeza;

    public:

    /*
    | Situación                                          | Usas                                                                    |
    | -------------------------------------------------- | ----------------------------------------------------------------------- |
    | "Tengo este objeto"                                | `nodo n;`                                                               |
    | "Quiero señalar a otro objeto"                     | `nodo* n;`                                                              |
    | "Quiero modificar un objeto que me pasaron"        | `nodo& n`                                                               |
    | "Quiero crear algo que viva después de la función" | `new nodo()` (aunque hoy en C++ moderno se suele preferir `unique_ptr`) |
    */
    lista() : cabeza(nullptr) {}
    ~lista(){
    nodo* temp = cabeza;

    while(temp != nullptr){
        nodo* siguiente = temp->getSiguiente();
        delete temp;
        temp = siguiente;
    }
    }

    void insertarElemento(int elemnt){
        nodo* nuevo = new nodo(elemnt);

        if (cabeza == nullptr){
            cabeza = nuevo;
        }
        else {
            nodo* temp = cabeza;
            while (temp->getSiguiente() != nullptr){
            temp = temp->getSiguiente();
            }
            temp->setSiguiente(nuevo);
        }
    }

    void recorrerLista(){
        nodo* temp = cabeza;
        
        while (temp != nullptr){
            std::cout<<temp->getElemento()<<std::endl;
            temp = temp->getSiguiente();
        }
    }
    void insertarPrincipio(int element){
        if (cabeza != nullptr){
        nodo* nuevo = new nodo(element);
        nuevo->setSiguiente(cabeza);
        cabeza = nuevo;
        }
    }

    void insertarPos(int element, int n){
        if (cabeza != nullptr){
            nodo* temp = cabeza;
            nodo* nuevo = new nodo(n);
            while (temp->getElemento() != element){
                temp = temp->getSiguiente();
            }
            nuevo->setSiguiente(temp->getSiguiente());
            temp->setSiguiente(nuevo);
        }
    }

    void eliminarPrincipio(){
        nodo* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
        temp = nullptr;
    }
};

int main () {
    lista l;
    l.insertarElemento(1);
    l.insertarElemento(2);
    l.insertarElemento(3);
    l.insertarElemento(4);
    l.insertarElemento(5);
    l.insertarPrincipio(6);
    l.insertarPos(3,9);
    l.eliminarPrincipio();

    l.recorrerLista();
    std::cout<<"Hola"<<std::endl;
    return 0;
}