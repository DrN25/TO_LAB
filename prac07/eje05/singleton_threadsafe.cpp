#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class SingletonSeguro {
private:
    static SingletonSeguro* instancia;
    static mutex mtx; // Mutex para el bloqueo
    string data;

    SingletonSeguro(string valor) : data(valor) {}

public:
    // Evitar copia
    SingletonSeguro(SingletonSeguro &other) = delete;
    void operator=(const SingletonSeguro &) = delete;

    static SingletonSeguro* getInstancia(string valor) {\
        if (instancia == nullptr) {
            lock_guard<mutex> lock(mtx); // Bloqueo
            if (instancia == nullptr) {
                instancia = new SingletonSeguro(valor);
            }
        }
        return instancia;
    }

    string getData() {
        return data;
    }
};

// Inicializacion de miembros estaticos
SingletonSeguro* SingletonSeguro::instancia = nullptr;
mutex SingletonSeguro::mtx;

void procesoHilo(string nombre) {
    // Intentar crear con el nombre del hilo, donde solo el primero deberia ganar
    SingletonSeguro* s = SingletonSeguro::getInstancia(nombre);
    cout << "Hilo " << nombre << " obtuvo instancia con valor: " << s->getData() << endl;
}

int main() {
    cout << "Iniciando hilos concurrentes..." << endl;
    
    vector<thread> hilos;
    
    // Lanzar 5 hilos
    for (int i = 0; i < 5; ++i) {
        hilos.push_back(thread(procesoHilo, "H" + to_string(i)));
    }

    // Esperar a que terminen
    for (auto& t : hilos) {
        t.join();
    }

    return 0;
}