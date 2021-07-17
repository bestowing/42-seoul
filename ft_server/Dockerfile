FROM debian:buster

RUN apt update && apt -y install \
    nginx \
    php-fpm \
    openssl \
    mariadb-server \
    php-mysql \
    php-mbstring

ENV AUTOINDEX on

COPY /srcs/default ./etc/nginx/sites-available/
ADD /srcs/phpMyAdmin-5.0.4-all-languages.tar.gz ./
COPY /srcs/config.inc.php ./
ADD /srcs/latest.tar.gz ./
COPY /srcs/wp-config.php ./
COPY /srcs/init.sh ./

EXPOSE 80 443

CMD bash init.sh