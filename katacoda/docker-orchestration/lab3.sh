# Load Balance and Service Discover in Swarm Mode

# Learn how to use Load Balancing and Service Discovery

# Step 1 - Initialise Cluster

docker swarm init
docker swarm join 172.17.0.37:2377

# Step 2 - Port Load Balance
# Task
# The command below will create a new service called lbapp1 with two containers running. The service is exposed via port 81.

docker service create --name lbapp1 --replicas 2 -p 81:80 katacoda/docker-http-server
curl docker:81

# Step 3 - Virtual IP and Service Discovery
# Task
# This network will be a "swarm-scoped network". This means that only containers launched as a service can attach itself to the network.

docker network create -d overlay eg1
docker service create --name http --network eg1 --replicas 2 katacoda/docker-http-server

docker service create --network eg1 benhall/dig dig http
docker logs $(docker ps -aq --filter="ancestor=benhall/dig:latest")
docker service create --network eg1 alpine ping -c5 http
docker logs $(docker ps -aq --filter="ancestor=alpine:latest")
docker service inspect http -format="{{.Endpoint.VirtualIPs}}"
docker inspect --format="{{.NetworkSettings.Networks.eg1.IPAddress}}" $(docker ps -aq --filter="ancestor=katacoda/docker-http-server:latest" | head -n1)

# Step 4 - Multi-Host LB and Service Discovery
# When deploying Redis, the network can be attached. The application expects to be able to connect to a Redis instance, named Redis. To enable the application to discover the Virtual IP via the Embedded DNS we call the service Redis.
# The application is now distributed across multiple hosts.

docker network create -d overlay app1-network
docker service create --name redis --network app1-network redis:alpine
docker service create --name app1-web --network app1-network --replicas 4 -p 80:3000 katacoda/redis-node-docker-example