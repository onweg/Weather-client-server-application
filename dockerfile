FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    qt5-qmake \
    qtbase5-dev \
    build-essential \
    libpq-dev \
    curl \
    && apt-get clean

WORKDIR /app

COPY ./server /app/server

WORKDIR /app/server

RUN qmake HttpServer2.pro && make

RUN touch db_config.json

EXPOSE 33333

CMD ["./HttpServer2.app/Contents/MacOS/HttpServer2"]
