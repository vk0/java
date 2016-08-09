# Create Cross-host Overlay Networks

# Learn how containers can communicate when running on different machines

# Step 1 - Configure Key/Value Store
# To begin you need to have a running instance of Consul that is accessible to both Docker Daemons. We'll launch this as a container on Host01.

docker run -d --name consul \
  -p 8300:8300 -p 8400:8400 -p 8500:8500 -p 53:8600/udp \
  gliderlabs/consul-server:latest -bootstrap

# Step 2 - Configure Docker Daemon on Host 1

docker run --privileged --name d1 -d \
  --net=host katacoda/dind:1.10 -H 0.0.0.0:3375 \
  --cluster-store=consul://172.17.0.50:8500 \
  --cluster-advertise=172.17.0.50:0
export DOCKER_HOST="172.17.0.50:3375"

# Step 3 - Configure Docker Daemon on Host 2

docker run --privileged --name d1 -d \
  --net=host katacoda/dind:1.10 -H 0.0.0.0:3375 \
  --cluster-store=consul://172.17.0.50:8500 \
  --cluster-advertise=172.17.0.28:0

export DOCKER_HOST="172.17.0.28:3375"

# Step 4 - Create Multihost Network

docker network create -d overlay multihost-net

# Step 5 - Start Service on Host 1

docker run -d --name ws1 --net=multihost-net katacoda/docker-http-server

# Step 6 - Access Service on Host 2

docker run --net=multihost-net benhall/curl curl -Ss ws1