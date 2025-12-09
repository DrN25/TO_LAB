#include <iostream>
#include <string>

using namespace std;

class ConexionBD {
private:
    static ConexionBD* instancia;
    bool conectado;

    ConexionBD() {
        conectado = false;
    }

public:
    static ConexionBD* getInstancia() {
        if (instancia == nullptr) {
            instancia = new ConexionBD();
        }
        return instancia;
    }

    void conectar() {
        if (!conectado) {
            conectado = true;
            cout << "Conectando a la Base de Datos... Exito." << endl;
        } else {
            cout << "Ya existe una conexion activa. Retornando la existente." << endl;
        }
    }

    void desconectar() {
        if (conectado) {
            conectado = false;
            cout << "Desconectando de la BD..." << endl;
        } else {
            cout << "No hay conexion activa para cerrar." << endl;
        }
    }

    string getEstado() {
        return conectado ? "Conectado" : "Desconectado";
    }
};

ConexionBD* ConexionBD::instancia = nullptr;

int main() {
    ConexionBD* bd1 = ConexionBD::getInstancia();
    
    cout << "Estado inicial: " << bd1->getEstado() << endl;

    bd1->conectar();
    
    // Intentando conectar desde otra referencia
    ConexionBD* bd2 = ConexionBD::getInstancia();
    bd2->conectar(); // Deberia decir que ya existe

    bd1->desconectar();
    
    cout << "Estado final bd2: " << bd2->getEstado() << endl;

    return 0;
}