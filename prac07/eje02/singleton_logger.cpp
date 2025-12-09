#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Logger {
private:
    static Logger* instancia;
    string nombreArchivo;

    Logger() {
        nombreArchivo = "bitacora.log";
    }

public:
    static Logger* getInstancia() {
        if (instancia == nullptr) {
            instancia = new Logger();
        }
        return instancia;
    }

    void log(string mensaje) {
        ofstream archivo;
        // Abrir en modo append (ios::app)
        archivo.open(nombreArchivo, ios::app);
        
        if (archivo.is_open()) {
            // Obtener hora simple
            time_t now = time(0);
            char* dt = ctime(&now);
            // ctime agrega un salto de linea al final
            string hora(dt);
            hora.pop_back(); 

            archivo << "[" << hora << "] " << mensaje << endl;
            cout << "Log registrado: " << mensaje << endl;
            archivo.close();
        } else {
            cerr << "No se pudo abrir el archivo log." << endl;
        }
    }
};

Logger* Logger::instancia = nullptr;

int main() {
    Logger* log1 = Logger::getInstancia();
    Logger* log2 = Logger::getInstancia();

    log1->log("Sistema iniciado");
    log2->log("Usuario administrador conectado");
    log1->log("Advertencia de memoria baja");

    cout << "\nVerifica el archivo 'bitacora.log' en la carpeta." << endl;
    
    return 0;
}