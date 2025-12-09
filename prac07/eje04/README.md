# Ejercicio 04: Estado Global de Juego

Uso de Singleton para manejar variables globales (`vidas`, `puntaje`, `nivel`) accesibles desde distintas funciones.

### Simulación
- Funciones independientes (`enemigoAtaca`, `recogerMoneda`) modifican el estado del juego sin necesidad de pasar el objeto juego por parámetros, ya que lo obtienen vía `getInstancia()`.
### Ejemplo de ejecución en consola

```shell
Nivel: 1 | Puntaje: 0 | Vidas: 3
-> Moneda recogida! Puntaje: 50
-> Moneda recogida! Puntaje: 100
-> Un enemigo te golpeo! Vidas restantes: 2

Estado Global Final:
Nivel: 1 | Puntaje: 100 | Vidas: 2
```