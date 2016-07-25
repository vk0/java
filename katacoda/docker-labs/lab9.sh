# Creating Networks Between Containers using Networks

# Learn how containers communicate via networks

# Step 1 - Create Network
# Task: Create Network
# To start with we create the network with our predefined name.

docker network create backend-network

# Task: Connect To Network
# When we launch new containers we can use the --net attribute to assign which network they should be connected to.

docker run -d --name=redis --net=backend-network redis

# Step 2 - Network Communication
docker run --net=backend-network ubuntu env
docker run --net=backend-network ubuntu cat /etc/hosts
docker run --net=backend-network ubuntu cat /etc/resolv.conf
docker run --net=backend-network ubuntu ping -c1 redis

# Step 3 - Connect Two Containers

docker network create frontend-network
docker network connect frontend-network redis
docker run -d -p 3000:3000 --net=frontend-network katacoda/redis-node-docker-example

# Step 4 - Create Aliases
# Connect Container with Alias
# The following command will connect our Redis instance to the frontend-network with the alias of db.

docker network create frontend-network2
docker network connect --alias db frontend-network2 redis

# When containers attempt to access a service via the name db, they will be given the IP address of our Redis container.

docker run --net=frontend-network2 ubuntu ping -c1 db

# Step 5 - Disconnect Containers

docker network ls
docker network inspect frontend-network
docker network disconnect frontend-network redis