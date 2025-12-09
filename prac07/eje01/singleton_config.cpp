#include <iostream>
#include <string>

using namespace std;

class Configuracion {
private:
    static Configuracion* instancia;    // Puntero estatico unico
    
    // Constructor privado
    Configuracion() {
        idioma = "Espanol";
        zonaHoraria = "UTC-5";
    }

public:
    string idioma;
    string zonaHoraria;

    // Metodo estatico para obtener la instancia - SINGLETON
    static Configuracion* getInstancia() {
        if (instancia == nullptr) {
            instancia = new Configuracion();
        }
        return instancia;
    }

    void mostrarConfiguracion() {
        cout << "Configuracion: Idioma=" << idioma << ", Zona=" << zonaHoraria << endl;
    }
};

// Inicializar el puntero estatico a null
Configuracion* Configuracion::instancia = nullptr;

int main() {
    cout << "--- Ejercicio 01: Singleton Basico ---" << endl;

    // Probando a obtener la instancia dos veces
    Configuracion* conf1 = Configuracion::getInstancia();
    Configuracion* conf2 = Configuracion::getInstancia();

    conf1->mostrarConfiguracion();

    // Modificando usando el puntero 2
    cout << "\nCambiando idioma a Ingles en conf2..." << endl;
    conf2->idioma = "Ingles";

    // Verificacion en el puntero 1
    conf1->mostrarConfiguracion();

    // Verificacion de direcciones de memoria
    cout << "\nDireccion conf1: " << conf1 << endl;
    cout << "Direccion conf2: " << conf2 << endl;

    if (conf1 == conf2) {
        cout << "Exito: Ambos punteros apuntan a la misma memoria." << endl;
    }

    return 0;
}