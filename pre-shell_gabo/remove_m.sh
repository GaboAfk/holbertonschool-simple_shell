#!/bin/bash

# Verificar si se proporciona un archivo como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 archivo"
    exit 1
fi

# Verificar si el archivo existe y es legible
if [ ! -f "$1" ]; then
    echo "El archivo '$1' no existe o no es legible."
    exit 1
fi

# Crear una copia de respaldo del archivo original
cp "$1" "$1.bak"

# Eliminar el primer caracter ^M del archivo y guardar el resultado en un nuevo archivo temporal
tr -d '\r' < "$1.bak" > "$1.tmp"

# Mover el archivo temporal al archivo original
mv "$1.tmp" "$1"

echo "El primer caracter ^M ha sido eliminado del archivo '$1'."
