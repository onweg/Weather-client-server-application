FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    build-essential \
    qt5-qmake \
    qtbase5-dev \
    qtchooser \
    qt5-qmake-bin \
    libqt5sql5 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY . /app

WORKDIR /app/server

RUN qmake HttpServer2.pro && make

EXPOSE 33333 5432

CMD ["./HttpServer2.app/Contents/MacOS/HttpServer2"]
