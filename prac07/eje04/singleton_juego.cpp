#include <iostream>

using namespace std;

class ControlJuego {
private:
    static ControlJuego* instancia;

    ControlJuego() {
        nivel = 1;
        puntaje = 0;
        vidas = 3;
    }

public:
    int nivel;
    int puntaje;
    int vidas;

    static ControlJuego* getInstancia() {
        if (instancia == nullptr) {
            instancia = new ControlJuego();
        }
        return instancia;
    }

    void mostrarEstado() {
        cout << "Nivel: " << nivel << " | Puntaje: " << puntaje << " | Vidas: " << vidas << endl;
    }
};

ControlJuego* ControlJuego::instancia = nullptr;

void enemigoAtaca() {
    ControlJuego* juego = ControlJuego::getInstancia();
    juego->vidas--;
    cout << "-> Un enemigo te golpeo! Vidas restantes: " << juego->vidas << endl;
}

void recogerMoneda() {
    ControlJuego* juego = ControlJuego::getInstancia();
    juego->puntaje += 50;
    cout << "-> Moneda recogida! Puntaje: " << juego->puntaje << endl;
}

int main() {
    ControlJuego* mainJuego = ControlJuego::getInstancia();
    mainJuego->mostrarEstado();

    recogerMoneda();
    recogerMoneda();
    enemigoAtaca();

    cout << "\nEstado Global Final:" << endl;
    ControlJuego::getInstancia()->mostrarEstado();

    return 0;
}