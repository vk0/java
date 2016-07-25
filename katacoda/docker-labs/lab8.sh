# Creating Networks Between Containers using Links

# Learn how containers communicate via links

# Step 1 - Start Redis

docker run -d --name redis-server redis

# Step 2 - Create Link
docker run --link redis-server:redis ubuntu env
docker run --link redis-server:redis ubuntu cat /etc/hosts
docker run --link redis-server:redis ubuntu ping -c 1 redis

# Step 3 - Connect To App

docker run -d -p 3000:3000 --link redis-server:redis katacoda/redis-node-docker-example
curl localhost:3000

# Step 4 - Connect to Redis CLI

docker run -it --link redis-server:redis redis redis-cli -h redis