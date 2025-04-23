
# Weather-client-server-application

## Быстрый старт

### 1. Клонируй репозиторий

```bash
git clone https://github.com/yourusername/your-repo.git
cd Weather-client-server-application
```

---

### 2. Создай конфигурационный файл БД

Создай файл `db_config.json` внутри папки `server`:


```json
{
  "host": "192.168.0.100",
  "port": 5432,
  "user": "your_user",
  "password": "your_password",
  "dbname": "your_database"
}
```
Данные можно попросить у создателя этого репозитория, чтоб он дал ip, порт, логин, пароль и имя базы данных для удаленного подлкючения к базе данных, либо запустить у себя postgres и ввести свои данные, предварительно создать бд с таблицей users и такими полями как id username password_hash       

> ⚠️ **Важно**: Этот файл содержит конфиденциальные данные и **не должен попадать в Git!**

---

### 3. Собери Docker-образ и запусти

```bash
docker build -t qt-json-server .
docker run -v $(pwd)/server/db_config.json:/app/server/db_config.json \
    -p 33333:33333 \
    -p 5432:5432 \
    qt-json-server

```

> 💡 На Windows:
```bash
docker run -v %cd%/server/db_config.json:/app/server/db_config.json -p 8080:8080 qt-json-server
```

---


## REST-like API (через TCP)

Сервер обрабатывает JSON-запросы, полученные через обычное TCP-соединение. Каждый запрос должен содержать команду `LOGIN` или `REGISTER`, а также необходимые параметры.

В примерах будет использоваться localhost:8080, но если нужна реальная бд, попросите ip и порт у создателя этого репозитория или ипользуйте свои бд в котором есть таблицы users и поля id username password_hash 

---

### Авторизация пользователя (LOGIN)

**Адрес подключения (TCP):**
```
localhost:8080
```

**Пример запроса:**
```json
{
  "command": "LOGIN",
  "login": "admin",
  "password": "1234"
}
```

**Пример успешного ответа:**
```json
{
  "status": "success",
  "message": "Авторизация успешна"
}
```

**Пример ошибки (неверный логин или пароль):**
```json
{
  "status": "error",
  "message": "Неверный логин или пароль"
}
```

---

### Регистрация пользователя (REGISTER)

**Пример запроса:**
```json
{
  "command": "REGISTER",
  "login": "newuser",
  "password": "mypassword"
}
```

**Пример успешного ответа:**
```json
{
  "status": "success",
  "message": "Регистрация прошла успешно"
}
```

**Пример ошибки (пустые поля):**
```json
{
  "status": "error",
  "message": "Логин и пароль не должны быть пустыми"
}
```

**Пример ошибки (пользователь уже существует):**
```json
{
  "status": "error",
  "message": "Пользователь уже существует"
}
```

---

### Обработка ошибок

**Неверный формат JSON:**
```json
{
  "status": "error",
  "message": "Неверный JSON"
}
```

**Неизвестная команда:**
```json
{
  "status": "error",
  "message": "Неизвестная команда"
}
```

---

### Пример ручной отправки запроса (с помощью netcat):

```bash
echo -e "POST / HTTP/1.1\r\nHost: localhost\r\nContent-Type: application/json\r\nContent-Length: 68\r\n\r\n{\"command\":\"LOGIN\",\"login\":\"admin\",\"password\":\"1234\"}" | nc localhost 8080
```

---

### Пример ручной отправки запроса (с помощью curl):

```bash
curl -X POST http://localhost:8080/ \
     -H "Content-Type: application/json" \
     -d '{"command":"LOGIN", "login":"admin", "password":"1234"}'
```

---

### Примечания

- Сервер принимает запросы по TCP и извлекает только тело HTTP-запроса (JSON-объект).
- Все команды и ответы обрабатываются в формате JSON.
- Убедитесь, что в теле запроса указывается корректное значение поля `command`.
- Отправку можно тестировать с помощью `netcat`, Postman (TCP-режим), или собственных TCP-клиентов.


---

## 📱 Клиент (Aurora OS)

Клиентская часть запускается на устройствах с ОС **Аврора**.

---

## 🧹 Полезные команды

Удалить все Docker-образы:
```bash
docker system prune -a
```

Удалить все тома:
```bash
docker volume rm -f $(docker volume ls -q)
```

---

## 🔐 Безопасность

- `db_config.json` игнорируется через `.dockerignore`
- Используйте переменные окружения или Docker secrets для продакшна
- Не коммитьте пароли и логины в публичный репозиторий

---

## 🔗 Полезное

- [Docker Secrets](https://docs.docker.com/engine/swarm/secrets/)
- [Aurora OS SDK](https://developer.auroraos.ru/)

---

> Автор: **[Твоё имя]**
