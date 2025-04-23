#!/bin/bash

echo "🔧 Генерация config.json..."
cat <<EOF > server/config.json
{
  "host": "db",
  "port": 5432,
  "database": "myapp",
  "username": "user",
  "password": "password"
}
EOF

echo "🔨 Сборка сервера..."
cd server
qmake HttpServer2.pro
make

echo "🚀 Запуск сервера..."
./HttpServer2
