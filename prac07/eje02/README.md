# Ejercicio 02: Logger Compartido

Logger implementado como Singleton para centralizar la escritura en `bitacora.log`.

### Detalles Técnicos
- La clase gestiona la apertura del archivo en modo `append`.
- Al ser Singleton, evitamos conflictos de múltiples objetos intentando abrir el archivo simultáneamente de formas incompatibles.
- Incluye marca de tiempo simple usando `ctime`.

### Ejemplo de ejecución en consola

```shell
Log registrado: Sistema iniciado
Log registrado: Usuario administrador conectado
Log registrado: Advertencia de memoria baja

Verifica el archivo 'bitacora.log' en la carpeta.
```
bitacora.log
```bitacora.log
[Mon Dec 08 23:08:54 2025] Sistema iniciado
[Mon Dec 08 23:08:54 2025] Usuario administrador conectado
[Mon Dec 08 23:08:54 2025] Advertencia de memoria baja
```