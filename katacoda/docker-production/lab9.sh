# Start Docker Containers on Boot with Systemd
# Use Systemd to manage launching containers

# Create Systemd Unit File

> cat postgres.service
[Unit]
Description=PostgreSQL container
Requires=docker.service
After=docker.service
[Service]
Restart=on-failure
RestartSec=10
ExecStartPre=-/usr/bin/docker stop postgres
ExecStartPre=-/usr/bin/docker rm postgres
ExecStart=/usr/bin/docker run --name postgres \
 --volume /opt/db/postgres:/var/lib/pgsql/data \
 kiasaki/alpine-postgres
ExecStop=/usr/bin/docker stop postgres
[Install]
WantedBy=multi-user.target

# Enable Systemd Unit File

sudo cp postgres.service /etc/systemd/system
sudo systemctl enable /etc/systemd/system/postgres.service

# Start Systemd Unit File

sudo systemctl start postgres.service

# Check Results

journalctl --no-pager -u postgres.service