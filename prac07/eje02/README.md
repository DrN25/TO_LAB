# Ejercicio 02: Logger Compartido

Logger implementado como Singleton para centralizar la escritura en `bitacora.log`.

### Detalles Técnicos
- La clase gestiona la apertura del archivo en modo `append`.
- Al ser Singleton, evitamos conflictos de múltiples objetos intentando abrir el archivo simultáneamente de formas incompatibles.
- Incluye marca de tiempo simple usando `ctime`.