# Weather Client-Server Application

## 📦 Быстрый старт

### 1. Клонирование репозитория

```bash
git clone git@github.com:onweg/Weather-client-server-application.git
cd Weather-client-server-application
```

---

### 2. Запуск без использования Docker

Создайте файл `db_config.json` в папке `Server` со следующим содержимым:

```json
{
  "host": "192.168.0.100",
  "port": 5432,
  "user": "your_user",
  "password": "your_password",
  "dbname": "your_database"
}
```

> ⚠️ **Важно:** Этот файл содержит конфиденциальные данные и **не должен попадать в репозиторий Git!**

- Данные для подключения можно запросить у создателя репозитория.
- Либо можно развернуть локальный экземпляр PostgreSQL, создать базу данных и таблицу `users` с полями `id`, `username`, `password_hash`.

Сборка и запуск сервера на MacOS:

```bash
qmake HttpServer.pro
make
./HttpServer.app/Contents/MacOS/HttpServer
```

---

### 3. Запуск через Docker

Соберите Docker-образ и запустите приложение:

```bash
docker-compose up --build
```

> 💡 **На Windows:**  
> Используйте корректную настройку Docker Desktop и аналогичную команду через терминал.

---

## 🛠️ Примеры ручной отправки запросов

### С помощью netcat:

```bash
echo -e "POST / HTTP/1.1\r\nHost: localhost\r\nContent-Type: application/json\r\nContent-Length: 68\r\n\r\n{\"command\":\"LOGIN\",\"login\":\"admin\",\"password\":\"1234\"}" | nc localhost 8080
```

### С помощью curl:

```bash
curl -X POST http://localhost:8080/ \
     -H "Content-Type: application/json" \
     -d '{"command":"LOGIN", "login":"admin", "password":"1234"}'
```

---

## ℹ️ Примечания

- Сервер принимает запросы по TCP и извлекает только тело HTTP-запроса (JSON-объект).
- Все команды и ответы обрабатываются в формате JSON.
- В теле запроса обязательно должно быть корректное значение поля `command`.
- Отправку можно тестировать через `curl`.

---

## 📱 Клиент (Aurora OS)

Клиентская часть запускается на устройствах под управлением операционной системы **Аврора**.

---
