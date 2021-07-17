#!/bin/bash

# SSL
openssl genrsa -out private.key 2048
openssl req -new -nodes -subj "/C=KR/ST=Ansan/L=Ansan/O=42Seoul/OU=chelee/CN=localhost" -key private.key -out private.csr
openssl req -x509 -days 365 -key private.key -in private.csr -out private.crt -days 365
mv private.crt etc/ssl/certs/
mv private.key etc/ssl/private/
rm -rf private.csr
chmod 600 etc/ssl/certs/private.crt etc/ssl/private/private.key

# phpmyadmin
mv phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin
mv config.inc.php /var/www/html/phpmyadmin/

# DB
service mysql start
mysql -u root --skip-password < var/www/html/phpmyadmin/sql/create_tables.sql
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER chelee@localhost IDENTIFIED by '1234';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* to chelee@localhost;" | mysql -u root --skip-password

# wordpress
mv wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
mv wp-config.php /var/www/html/wordpress/

if [ $AUTOINDEX == off ]
then
    sed -i '/autoindex on;/d' etc/nginx/sites-available/default
else
    # autoindex test
    rm -rf /var/www/html/index.nginx-debian.html
fi

# start services
service php7.3-fpm start
service nginx start
service mysql restart

bash