#include <iostream>
#include <string>
using namespace std;

//Definicion de la clase que contiene la informacion a manejar
class CDatos{
public:
    string nombre;
    int semestre;
    float promedio;
    CDatos(string x, int y, float b)
    {
        nombre=x;
        semestre=y;
        promedio=b;
    }
};
//Declaracion de la clase nodo
class nodo{
public:
    nodo (CDatos *apDatos, nodo *sig=NULL)
    {
        info=apDatos;
        siguiente=sig;
    }
private:
    CDatos *info;
    nodo *siguiente;
friend class pila;
};

typedef nodo *pnodo;
//Declaracion de la clase pila
class pila{
public:
    pila():ultimo(NULL){}
    ~pila();
    
    void Push(CDatos *apDatos);
    CDatos* Pop();
    
private:
    pnodo ultimo;
    
};
pila::~pila()
{
    pnodo aux;
    while (ultimo){
        aux=ultimo;
        ultimo=ultimo->siguiente;
        delete aux;
    }
}
//Creando Push
void pila::Push(CDatos *apDatos)
{
    pnodo nuevo;
    nuevo=new nodo(apDatos, ultimo);
    ultimo=nuevo;
    
}
//Creando Pop
CDatos* pila::Pop()
{
    pnodo nodo;
    CDatos *v;
    if (!ultimo) return NULL;
    nodo=ultimo;
    ultimo=ultimo->siguiente;
    v=nodo->info;
    delete nodo;
    return v;
}
int main()
{
    pila miPila;
    //Insertar elementos en la pila
    cout<<"Insertando (Angelica, 3, 9.1) en la pila"<<endl;
    CDatos Angelica("Angelica",3,9.1);
    miPila.Push(&Angelica);
    cout<<"Insertando (Ernesto, 2, 9.3) en la pila"<<endl;
    CDatos Ernesto("Ernesto",2,9.3);
    miPila.Push(&Ernesto);
    cout<<"Insertando (Alejandra, 4, 9.5) en la pila"<<endl;
    CDatos Alejandra("Alejandra",4,9.5);
    miPila.Push(&Alejandra);
    CDatos*aux=miPila.Pop();
    if (aux)
        cout<<"Sacando un elemento de la pila con nombre: "<<aux->nombre<<" Semestre: "<<aux->semestre<<" Promedio: "<<aux->promedio<<endl;
    else
        cout<<"La pila ya esta vacia"<<endl;
    aux=miPila.Pop();
    if (aux)
            cout<<"Sacando un elemento de la pila con nombre: "<<aux->nombre<<" Semestre: "<<aux->semestre<<" Promedio: "<<aux->promedio<<endl;
        else
            cout<<"La pila ya esta vacia"<<endl;
    
aux=miPila.Pop();
         if (aux)
             cout<<"Sacando un elemento de la pila con nombre: "<<aux->nombre<<" Semestre: "<<aux->semestre<<" Promedio: "<<aux->promedio<<endl;
         else
             cout<<"La pila ya esta vacia"<<endl;

aux=miPila.Pop();
    if (aux)
        cout<<"Sacando un elemento de la pila con nombre: "<<aux->nombre<<" Semestre: "<<aux->semestre<<" Promedio: "<<aux->promedio<<endl;
    else
        cout<<"La pila ya esta vacia"<<endl;

}
