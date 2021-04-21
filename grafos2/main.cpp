#include <iostream>
#include <string>
using namespace std;

class CGrafo
{
public:
    int cont;
    string ciudad[20];
    int recorridos[20][20];
    CGrafo();
    void Insertar1(string city);
    void Insertar2(int ciud1, int ciud2, int horas);
    void Listaciudades();
    void todos_recorridos();
    void mostrar_recorrido(int num1, int num2);
    void Breadth_first();
    void Depth_first();
};


CGrafo::CGrafo() {
    cont = 6;
    ciudad[0] = "CDMX";
    ciudad[1] = "Monterrey";
    ciudad[2] = "Cancun";
    ciudad[3] = "Acapulco";
    ciudad[4] = "Guadalajara";
    ciudad[5] = "Hidalgo";
    recorridos[0][0] = 0;
    recorridos[0][1] = 7;
    recorridos[0][2] = 12;
    recorridos[0][3] = 5;
    recorridos[0][4] = 7;
    recorridos[0][5] = 1;
    recorridos[1][0] = 7;
    recorridos[1][1] = 0;
    recorridos[1][2] = 18;
    recorridos[1][3] = 6;
    recorridos[1][4] = 4;
    recorridos[1][5] = 8;
    recorridos[2][0] = 12;
    recorridos[2][1] = 18;
    recorridos[2][2] = 0;
    recorridos[2][3] = 0;
    recorridos[2][4] = 15;
    recorridos[2][5] = 0;
    recorridos[3][0] = 5;
    recorridos[3][1] = 6;
    recorridos[3][2] = 0;
    recorridos[3][3] = 0;
    recorridos[3][4] = 3;
    recorridos[3][5] = 5;
    recorridos[4][0] = 7;
    recorridos[4][1] = 4;
    recorridos[4][2] = 15;
    recorridos[4][3] = 3;
    recorridos[4][4] = 0;
    recorridos[4][5] = 0;
    recorridos[5][0] = 1;
    recorridos[5][1] = 8;
    recorridos[5][2] = 0;
    recorridos[5][3] = 5;
    recorridos[5][4] = 0;
    recorridos[5][5] = 0;
}
void CGrafo::Insertar1(string city)
{
    ciudad[cont] = city;
    for (int i = 0;i <= cont;i++) {
        recorridos[cont][i] = 0;
        recorridos[i][cont] = 0;
    }
    cont = cont += 1;
}

void CGrafo::Listaciudades() {
    cout << "Lista de ciudades" << endl;
    for (int i = 0;i < cont;i++) {
        cout << i << ".- " << ciudad[i] << endl;
    }
}

void CGrafo::Insertar2(int ciud1, int ciud2, int horas) {
    recorridos[ciud1][ciud2] = horas;
    recorridos[ciud2][ciud1] = horas;
}

void CGrafo::todos_recorridos() {
    for (int i = 0;i < cont;i++) {
        for (int j = 0;j < cont;j++) {
            if (recorridos[i][j] != 0) {
                cout << "De " << ciudad[i] << " a " << ciudad[j] << " son: " << recorridos[i][j] << " horas" << endl;
            }
        }
    }
}

void CGrafo::mostrar_recorrido(int num1, int num2) {
    if (recorridos[num1][num2] == 0) {
        cout << "No hay recorrido para estas ciudades" << endl;
    }
    else {
        cout << "Si tiene recorrido y tiene una duracion de: " << recorridos[num1][num2] << " horas" << endl;
    }
}

void CGrafo::Breadth_first() {
    string lista[200];
    lista[0] = ciudad[0];
    int cont_aux = 1;
    int var_aux = 0;
    int var_aux2 = 0;
    for (int i = 0;i < cont;i++) {
        for (int j = 0;j < cont;j++) {
            if (recorridos[i][j] != 0) {
                for (int x = 0; x <= cont_aux;x++) {
                    if (ciudad[j] != lista[x]) {
                        var_aux += 1;
                        if (cont_aux +1  == var_aux) {
                            lista[cont_aux] = ciudad[j];
                            cont_aux++;
                            var_aux = 0;
                        }
                    }
                }
            }
        }
    }
    
    cout << "\nRecorrido Breadth First" << endl;
    for (int i = 0;i < cont;i++) {
        cout << lista[i] << ", ";
    }
    cout << endl;
}

void CGrafo::Depth_first() {
    string pila[400];
    string salida[20];
    salida[0] = ciudad[0];
    pila[0] = ciudad[0];
    int cont_pila = 1;
    int cont_salida=1;
    for (int i = 0;i < cont;i++) {
        for (int j = cont-1;j > 0;j--) {
            if (recorridos[i][j] != 0) {
                pila[cont_pila] = ciudad[j];
                cont_pila++;
            }
        }
        if (cont_salida < cont) {
            for (int x = cont_pila-1;x >= 0;x--) {
                salida[cont_salida] = pila[x];
                cont_salida++;
            }
        }
    }
    cout << "\nRecorrido Depth First" << endl;
    for (int i = 0;i < cont;i++) {
        cout << salida[i] << ", ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    CGrafo grafo;
    int opcion, h;
    h = 0;
    while (h == 0)
    {
        cout << "----Para agregar una nueva ciudad presiona 1----" << endl;
        cout << "----Para asignar tiempo a un recorrido presiona 2----" << endl;
        cout << "----Para mostrar los recorridos disponibles 3----" << endl;
        cout << "----Para preguntar si hay un recorrido entre dos ciudades y cual es su duracion presiona 4----" << endl;
        cout << "----Para revisar el recorrido Breadth First presiona 5----" << endl;
        cout << "----Para revisar el recorrido Depth First presiona 6----" << endl;
        cout << "----Para terminar el programa presiona 7----" << endl;
        cin >> opcion;
        if (opcion == 1)
        {
            string ciudad;
            cout << "Inserta el nombre de la ciuidad que quieras añadir: ";
            cin.clear();
            cin.ignore();
            getline(cin, ciudad);
            grafo.Insertar1(ciudad);
        }
        else if (opcion == 2)
        {
            grafo.Listaciudades();
            int ciud1, ciud2, horas;
            cout << "Número de ciudad de origen para asignar tiempo al recorrido: ";
            cin >> ciud1;
            cout << "Número de ciudad de destino para asignar tiempo al recorrido: ";
            cin >> ciud2;
            cout << "¿Cuántas horas dura el recorrido? ";
            cin >> horas;
            grafo.Insertar2(ciud1, ciud2, horas);
        }
        else if (opcion == 3)
        {
            grafo.todos_recorridos();
        }
        else if (opcion == 4)
        {
            grafo.Listaciudades();
            int ciud1, ciud2;
            cout << "Número de ciudad de origen: ";
            cin >> ciud1;
            cout << "Número de ciudad de destino: ";
            cin >> ciud2;
            grafo.mostrar_recorrido(ciud1, ciud2);
        }
        else if (opcion == 5) {
            grafo.Breadth_first();
        }
        else if (opcion == 6) {
            grafo.Depth_first();
        }
        else if (opcion == 7)
        {
            cout << "El programa termino" << endl;
            break;
        }
        else
        {
            cout << "Esa opción no existe, elige otra" << endl;
        }

    }

    return 0;
}
