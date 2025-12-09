# Ejercicio 03: Conexión BD Simulada

Control de acceso a un recurso único (conexión) para evitar duplicidad.

### Funcionamiento
- Mantiene un estado interno `bool conectado`.
- Si se llama a `conectar()` y ya es true, simplemente avisa y no hace nada, protegiendo el recurso.
- Simula el comportamiento de drivers de base de datos que manejan pools de conexión o conexiones únicas.

### Ejemplo de ejecución en consola

```shell
Estado inicial: Desconectado
Conectando a la Base de Datos... Exito.
Ya existe una conexion activa. Retornando la existente.
Desconectando de la BD...
Estado final bd2: Desconectado
```