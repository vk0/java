# Ensuring Container Uptime With Restart Policies

# Understand how you can use Docker to ensure your containers stay up

# Step 1 - Stop On Fail

docker run -d --name restart-default scrapbook/docker-restart-example
docker ps -a
docker logs restart-default

# Step 2 - Restart On Fail
# The option --restart=on-failure:
# allows you to say how many times Docker should try again. In the example below, Docker will restart the container three times before stopping.

docker run -d --name restart-3 --restart=on-failure:3 scrapbook/docker-restart-example
docker logs restart-3

# Step 3 - Always Restart
# Use the always flag to automatically restart the container when is crashes for example

docker run -d --name restart-always --restart=always scrapbook/docker-restart-example
docker logs restart-always