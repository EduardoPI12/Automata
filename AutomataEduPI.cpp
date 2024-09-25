#include <iostream>
#include <string>

using namespace std;

// Funcion que define el estado inicial, los estados de aceptación, y las transiciones.
bool procesarPalabra(const string& palabra) {
    // Estado inicial
    int estado = 0;
    
    // Recorremos cada simbolo de la palabra
    for (char simbolo : palabra) {
        switch (estado) {
            case 0: // Estado q0
                if (simbolo == 'a')
                    estado = 1; // Transición de q0 a q1 con 'a'
                else if (simbolo == 'b')
                    estado = 2; // Transición de q0 a q2 con 'b'
                else
                    return false; // Simbolo no valido
                break;
                
            case 1: // Estado q1
                if (simbolo == 'a')
                    estado = 1; // Permanecer en q1 con 'a'
                else if (simbolo == 'b')
                    estado = 1; // Permanecer en q1 con 'b'
                else
                    return false; // Simbolo no valido
                break;
                
            case 2: // Estado q2
                if (simbolo == 'b')
                    estado = 2; // Permanecer en q2 con 'b'
                else
                    return false; // Cualquier otro simbolo no es valido
                break;
                
            default:
                return false;
        }
    }
    
    // Comprobamos si el estado final es de aceptación (q1)
    return estado == 1;
}

int main() {
    string palabra;
    
    // Pedir al usuario la palabra a procesar
    cout << "Ingrese la palabra a procesar: ";
    cin >> palabra;
    
    // Procesar la palabra e imprimir si es aceptada o no
    if (procesarPalabra(palabra)) {
        cout << "La palabra es aceptada por el automata." << endl;
    } else {
        cout << "La palabra NO es aceptada por el automata." << endl;
    }
    
    return 0;
}
