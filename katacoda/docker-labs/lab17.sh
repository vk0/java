# Learn Docker Swarm 101

# Learn how to manage clusters using Docker Swarm Mode

# Step 1 - Initialise Swarm Mode
# Task: Create Swarm Mode Cluster

# Swarm Mode is built into the Docker CLI. You can find an overview the possibility commands via docker

swarm --help
docker swarm init

# Step 2 - Join Cluster
# Task
# On the second host, join the cluster by requesting access via the manager.

docker swarm join 172.17.0.21:2377
docker node ls

# Step 3 - Create Overlay Network
# Task
# The following command will create a new overlay network called skynet. All containers registered to this network can communicate with each other, regardless of which node they are deployed onto.

docker network create -d overlay skynet

# Step 4 - Deploy Service
# As containers are started you will see them using the ps command. You should see one instance of the container on each host.

docker service create --name http --network skynet --replicas 2 -p 80:80 katacoda/docker-http-server
docker service ls
docker ps
curl docker

# Step 5 - Inspect State
# Task
# You can view the list of all the tasks associated with a service across the cluster. In this case, each task is a container

docker service tasks http
docker service inspect --pretty http
docker node tasks self
docker node tasks $(docker node ls -q | tail -n1)

# Step 6 - Scale Service
# Task
# At present, we have two load-balanced containers running, which are processing our requests

curl docker
docker service scale http=5
docker ps