#!/bin/bash

echo "Генерация db_config.json..."
cat <<EOF > Server/db_config.json
{
  "host": "postgres_db",
  "port": 5432,
  "database": "myapp",
  "username": "user",
  "password": "password"
}
EOF

echo "Сборка сервера..."
cd Server
qmake HttpServer.pro
make

echo "Запуск сервера..."
./HttpServer
