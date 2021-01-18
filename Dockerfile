FROM ubuntu
RUN apt update
RUN apt -y  install default-libmysqlclient-dev   libulfius-dev uwsc  gcc
COPY rest.c /root
WORKDIR /root
RUN gcc rest.c -o rest  -L/usr/lib/`uname -m`-linux-gnu/libulfius.so -lulfius  `mysql_config --cflags --libs`
