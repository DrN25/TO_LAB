# Ejercicio 01: Singleton

Implementación de la clase `Configuracion` garantizando una única instancia global.

### Detalles Técnicos
- Se utiliza un atributo estático `static Configuracion* instancia`.
- El constructor es `private` para impedir `new Configuracion()` desde fuera.
- Se accede mediante el método estático `getInstancia()`.
- Se comprueba en el `main` que dos punteros distintos apuntan a la misma dirección de memoria.

### Ejemplo de ejecución en consola

```shell
--- Ejercicio 01: Singleton Basico ---
Configuracion: Idioma=Espanol, Zona=UTC-5

Cambiando idioma a Ingles en conf2...
Configuracion: Idioma=Ingles, Zona=UTC-5

Direccion conf1: 0xf31a28
Direccion conf2: 0xf31a28
Exito: Ambos punteros apuntan a la misma memoria.
```