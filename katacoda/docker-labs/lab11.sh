# Manage Container Log Files

# Learn the different approaches for handling container log files

# Step 1 - Docker Logs

docker logs redis-server

# Step 2 - SysLog
# By default the Docker logs are outputting using the json-file logger meaning the output stored in a JSON file on the host. This can result in large files filling the disk, as a result you can change the log driver to move to a different destination.
# The command below will redirect the redis logs to syslog.

docker run -d --name redis-syslog --log-driver=syslog redis
docker run -v /var/log/syslog:/var/log/syslog ubuntu ls /var/log/syslog | grep docker/

# Step 3 - Disable Logging

docker run -d --name redis-none --log-driver=none redis

docker inspect --format '{{ .HostConfig.LogConfig }}' redis-server
docker inspect --format '{{ .HostConfig.LogConfig }}' redis-syslog
docker inspect --format '{{ .HostConfig.LogConfig }}' redis-none