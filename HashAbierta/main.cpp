// Implementación de una tabla hash abierta
#include <iostream>
#include <string>
using namespace std;

class TablaHashAbierta {
    private:
        static const int tamanoT = 50;
        // Almacena la informacion de cada elemento de la tabla
        struct diccionario {
            string palabra;
            string significado;
            diccionario* next;
        };
        diccionario* TablaH[tamanoT];

    public:
        int contador;
        TablaHashAbierta();
        int Hash(string key);
        void insertarPalabra(string palabra, string significado);
        int NumeroPalabrasCon(int index);
        void imprimirTabla();
        void imprimirPalabras(int index);
};

void TablaHashAbierta::insertarPalabra(string palabra, string significado) {
    int index = Hash(palabra);
    if (TablaH[index]->palabra == "empty")
    {
        TablaH[index]->palabra = palabra;
        TablaH[index]->significado = significado;
    }
    else {
        diccionario* Ptr = TablaH[index];
        diccionario* n = new diccionario;
        n->palabra = palabra;
        n->significado = significado;
        n->next = NULL;
        while (Ptr->next != NULL) {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

// Constructor de la tabla hash
TablaHashAbierta::TablaHashAbierta() {
    contador = 0;
    for (int i = 0; i < tamanoT; i++) {
        TablaH[i] = new diccionario;
        TablaH[i]->palabra = "empty";
        TablaH[i]->significado = "empty";
        TablaH[i]->next = NULL;
    }
}

int TablaHashAbierta::NumeroPalabrasCon(int index) {
    int cont = 0;
    if (TablaH[index]->palabra == "empty") {
        return cont;
    }
    else {
        cont++;
        diccionario* Ptr = TablaH[index];
        while (Ptr->next != NULL) {
            cont++;
            Ptr = Ptr->next;
        }
    }
    return cont;
}

void TablaHashAbierta::imprimirTabla() {
    int num;
    for (int i = 0; i < contador; i++) {
        num = NumeroPalabrasCon(i);
        cout << "-----------------------------" << endl;
        cout << "index = " << i << endl;
        cout << TablaH[i]->palabra << endl;
        cout << TablaH[i]->significado << endl;
        cout << "# de palabras = " << num << endl;
        cout << "-----------------------------" << endl;
    }
}

void TablaHashAbierta::imprimirPalabras(int index) {
    diccionario* Ptr = TablaH[index];
    if (Ptr->palabra == "empty") {
        cout << "inde = " << index << "esta vacio" << endl;
    }
    else {
        cout << "Index " << index << "contiene las siguientes palabras:" << endl;
        while (Ptr != NULL) {
            cout << "---------------------------------" << endl;
            cout << Ptr->palabra << endl;
            cout << Ptr->significado << endl;
            cout << "---------------------------------" << endl;
            Ptr = Ptr->next;
        }
    }
}

// Retorna la extensión de la palabra
int TablaHashAbierta::Hash(string key) {
    int hash = 0;
    int index;
    // Convierte el string a una cadena
    for (int i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    cout << "Hash = " << hash << endl;
    index = hash % contador;
    cout << "Index" << index << endl;
    return index;
}

int main()
{
    TablaHashAbierta Listas;
    while (1) {
        int div = 0;
        cout << "Introduce el numero de elementos que deseas insertar (número primo): ";
        cin >> Listas.contador;
        for (int i = 1; i <= Listas.contador; i++) {
            if (Listas.contador % i == 0) {
                div++;
            }
        }
        if (Listas.contador == 1) {
            break;
        }
        else if (div == 2) {
            break;
        }
        else {
            cout << "El número no es primo, vuelve a insertarlo" << endl;
        }
    }
    Listas.insertarPalabra("Efimero", "Aquellos que dura por un periodo muy corto de tiempo");
    Listas.insertarPalabra("Superfluo", "No necesario, que esta de más");
    Listas.insertarPalabra("Inefable", "Algo tan increible que no puede ser expresado en palabras");
    Listas.insertarPalabra("Inconmensurable", "Enorme, que no puede medirse");
    Listas.insertarPalabra("Etereo","Extremadamente delicado y ligero, algo fuera de este mundo");
    Listas.insertarPalabra("Sempiterno", "Que durara para siempre; que, habiendo tenido principiio, no tendrá fin");
    Listas.insertarPalabra("Petricor", "Es el nombre que recibe el olor que produce la lluvia al caer sobre suelos secos");
    Listas.insertarPalabra("Perenne", "Continuo, incesante, que no tiene intermisión");
    Listas.insertarPalabra("Ojala", "Denota vivo deseo de que suceda algo");
    Listas.insertarPalabra("Luminiscencia", "Propiedad de un cuerpo de emitir una luz debil pero visible en la oscuridad");
    Listas.insertarPalabra("Compasion", "Sentimiento de pena, de ternura y de identificacion ante los males de algo");
    Listas.insertarPalabra("Mondo", "Limpio y libre de cosas añadidas o superfluas");
    Listas.insertarPalabra("Infinito", "Que no tiene ni puede tener fin ni termino");
    Listas.insertarPalabra("Ademan", "Movimiento o actitud del cuerpo o de alguna parte suya con que se manifiesta disposicion, intencio o sentimiento");
    Listas.imprimirTabla();
    Listas.imprimirPalabras(10);
}

