# sudo apt-get update
# sudo apt-get install -y nginx
# mkdir -p /home/box/web/public/{img,css,js}
# mkdir -p /home/box/web/{uploads,etc}

sudo unlink /etc/nginx/sites-enabled/default
sudo ln -fs /home/box/web/etc/nginx.conf /etc/nginx/sites-enabled/test.conf
sudo nginx -t && sudo /etc/init.d/nginx restart
sudo ln -fs /home/box/web/etc/hello.py /etc/gunicorn.d/hello.py
sudo /etc/init.d/gunicorn restart