#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class TresEnRaya {
private:
    char tablero[3][3];
    char simboloActual;
    string jugador1;
    string jugador2;

public:
    TresEnRaya(string j1, string j2) {
        jugador1 = j1;
        jugador2 = j2;

        reiniciar();

        simboloActual = (rand() % 2 == 0) ? 'X' : 'O';
    }

    void mostrarTablero() {
        cout << endl;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << tablero[i][j] << " ";

                if (j < 2)
                    cout << "|";
            }

            cout << endl;

            if (i < 2)
                cout << "-----------" << endl;
        }

        cout << endl;
    }
//le hice si ya que se me hizo mas facil para no confundirme con mostrarTablero y mezclar cosas que no son (Christian morales)
    void mostrarGuia() {
        cout << " 1 | 2 | 3 " << endl;
        cout << "-----------" << endl;
        cout << " 4 | 5 | 6 " << endl;
        cout << "-----------" << endl;
        cout << " 7 | 8 | 9 " << endl;
        cout << endl;
    }

    bool colocarFicha(int posicion) {

        if (posicion < 1 || posicion > 9)
            return false;

        int fila = (posicion - 1) / 3;
        int col = (posicion - 1) % 3;

        if (tablero[fila][col] != ' ')
            return false;

        tablero[fila][col] = simboloActual;

        return true;
    }

    char verificarGanador() {

        // Filas y columnas
        for (int i = 0; i < 3; i++) {

            if (tablero[i][0] != ' ' &&
                tablero[i][0] == tablero[i][1] &&
                tablero[i][1] == tablero[i][2])
                return tablero[i][0];

            if (tablero[0][i] != ' ' &&
                tablero[0][i] == tablero[1][i] &&
                tablero[1][i] == tablero[2][i])
                return tablero[0][i];
        }

    
    if (tablero[0][0] != ' ' &&
         tablero[0][0] == tablero[1][1] &&
        tablero[1][1] == tablero[2][2])
return tablero[0][0];

    if (tablero[0][2] != ' ' &&
        tablero[0][2] == tablero[1][1] &&
    tablero[1][1] == tablero[2][0])
    return tablero[0][2];

return ' ';
    }

 bool tableroLleno() {

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

    if (tablero[i][j] == ' ')
    return false;
}
}

    return true;
}

 void reiniciar() {

for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) {
    tablero[i][j] = ' ';
}
}
}

string getNombreActual() {
    return (simboloActual == 'X') ? jugador1 : jugador2;
    }

 char getSimboloActual() {
    return simboloActual;
    }

void cambiarTurno() {
     simboloActual = (simboloActual == 'X') ? 'O' : 'X';
    }
};


void actualizarPuntaje(int* ptrPuntaje) {
    (*ptrPuntaje)++;
}

int main() {
srand(time(0));
int puntos1 = 0;
int puntos2 = 0;
    int opcion;
    do {

cout << "\n=== TRES EN RAYA ===" << endl;
cout << "1. Jugar" << endl;
cout << "2. Ver puntajes" << endl;
cout << "3. Salir" << endl;
cout << "Opcion: ";

cin >> opcion;

 if (opcion == 1) {

 string j1, j2;

     cout << "Jugador 1 (X): ";
cin >> j1;

    cout << "Jugador 2 (O): ";
cin >> j2;

TresEnRaya juego(j1, j2);

cout << "Comienza: " << juego.getNombreActual()<< " (" << juego.getSimboloActual() << ")" << endl;

bool jugando = true;

while (jugando) {

juego.mostrarGuia();
    juego.mostrarTablero();

 int posicion;

 cout << juego.getNombreActual() << " (" << juego.getSimboloActual()<< "), elige posicion (1-9): ";
cin >> posicion;

 if (juego.colocarFicha(posicion)) {

char ganador = juego.verificarGanador();

if (ganador != ' ') {

juego.mostrarTablero();

 cout << juego.getNombreActual() << " GANA!" << endl;

if (ganador == 'X')
     actualizarPuntaje(&puntos1);
    else
     actualizarPuntaje(&puntos2);

    jugando = false;
}
else if (juego.tableroLleno()) {
juego.mostrarTablero();

cout << "EMPATE!" << endl;

 jugando = false;
}
else {
juego.cambiarTurno();
}
}
else {
cout << "Error: posicion invalida u ocupada." << endl;
}
}

cout << "\nPUNTAJES:" << endl;
    cout << j1 << ": " << puntos1 << endl;
    cout << j2 << ": " << puntos2 << endl;
char repetir;
 cout << "Jugar de nuevo? (s/n): ";
    cin >> repetir;

    if (repetir != 's' && repetir != 'S')
    opcion = 3;
        }
 else if (opcion == 2) {

    cout << "\n--- PUNTAJES ---" << endl;
cout << "Jugador 1: " << puntos1 << endl;
cout << "Jugador 2: " << puntos2 << endl;
        }

    } 
    while (opcion != 3);
    cout << "Hasta luego!" << endl;
    return 0;
}







