# Ejercicio 05: Singleton Thread-Safe (Multihilo)

Implementación robusta para entornos con concurrencia.

### Patrón utilizado
- **Double-Checked Locking:** Se verifica si la instancia es null antes de adquirir el bloqueo, y se verifica de nuevo dentro del bloqueo.
- Usa `std::mutex` de la librería `<mutex>` de C++11.
- Garantiza que aunque varios hilos intenten crear la instancia al nanosegundo exacto, solo uno lo logre.

### Ejemplo de ejecución en consola

```shell
Iniciando hilos concurrentes...
Hilo H0 obtuvo instancia con valor: H0
Hilo H1 obtuvo instancia con valor: H0
Hilo H2 obtuvo instancia con valor: H0
Hilo H3 obtuvo instancia con valor: H0
Hilo H4 obtuvo instancia con valor: H0
```