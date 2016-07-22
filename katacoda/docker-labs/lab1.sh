# Launching Containers
# Learn how to launch containers using docker

# Step 1 - Running A Container
# To complete this step you need to execute the following code:

docker run -d redis:latest

# Step 2 - Listing Running Containers

docker inspect <friendly-name|container-id>
docker logs <friendly-name|container-id>

# Step 3 - Binding Ports
# To complete this step you need to execute the following code:

docker run -d --name redisFixed -p 6379:6379 redis:latest

# Step 4 - Binding Ports
# To complete this step you need to execute the following code:

docker run -d --name redisDynamic -p 6379 redis:latest
docker port redisDynamic 6379

# Step 5 - Binding Directories
# To complete this step you need to execute the following code:

docker run -d --name redisMapped -v "$PWD/data":/data redis

# Step 6 - Running A Container In The Foreground

docker run ubuntu ps