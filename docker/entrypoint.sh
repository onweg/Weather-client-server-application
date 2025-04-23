#!/bin/bash

echo "Генерация db_config.json..."
cat <<EOF > server/db_config.json
{
  "host": "postgres_db",
  "port": 5432,
  "database": "myapp",
  "username": "user",
  "password": "password"
}
EOF

echo "Сборка сервера..."
cd server
qmake HttpServer2.pro
make

echo "Запуск сервера..."
./HttpServer2
