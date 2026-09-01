#include <iostream>

class nodo
{
private:
    int elemento;
    nodo *siguiente;

public:
    nodo() {}
    nodo(int elemnt) : elemento(elemnt), siguiente(nullptr) {}

    int getElemento() { return elemento; }
    nodo *getSiguiente() { return siguiente; }
    void setElemento(int e) { elemento = e; }
    void setSiguiente(nodo *n) { siguiente = n; }
};

class Cola
{
private:
    nodo *cabeza;
    nodo *final;

public:
    Cola() : cabeza(nullptr), final(nullptr) {}
    Cola(int ero)
    {
        nodo *nuevo = new nodo(ero);
        cabeza = nuevo;
        final = nuevo;
        nuevo->setSiguiente(nullptr);
    }

    Cola(nodo *nuevo)
    {
        if (nuevo)
        {
            cabeza = nuevo;
            final = nuevo;
            nuevo->setSiguiente(nullptr);
        }
        else
        {
            cabeza = nullptr;
            final = nullptr;
        }
    }

    ~Cola()
    {
        nodo *temp = cabeza;

        while (temp != nullptr)
        {
            nodo *siguiente = temp->getSiguiente();
            delete temp;
            temp = siguiente;
        }
        
    }

    void insertar(int elemento)
    {
        nodo* nuevo = new nodo(elemento);
        nuevo->setSiguiente(nullptr);

        if (cabeza != nullptr)
        {
            final->setSiguiente(nuevo);
            final = nuevo;
        }
        else {
            cabeza = nuevo;
            final = cabeza;
        }
    }

    void eliminar()
    {
        if (cabeza != nullptr)
        {
            nodo* temp = cabeza;
            cabeza = cabeza->getSiguiente();

            if (cabeza == nullptr){
                final = nullptr;
            }

            delete temp;
        }
    }

    nodo* getCabeza() const 
    {
        return cabeza;
    }

    nodo* getFinal() const 
    {
        return (final != nullptr) ? final : nullptr;

    }
    // crear, destruir, insertar, eliminar, 1er, Ul,
};

int main()
{
    Cola cola;
    cola.insertar(5);
    std::cout << cola.getCabeza()->getElemento() << std::endl;
    return 0;
}