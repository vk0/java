# Apply Rolling Updates Across Swarm Cluster

# Learn how to perform rolling updates to services on a Docker Swarm cluster

# Step 1 - Update Limits
# Task
# To start, deploy a HTTP service. We will use this to update/modify the container settings.

docker service create --name http --replicas 2 -p 80:80 katacoda/docker-http-server:v1
docker service update --env KEY=VALUE http
docker service update --limit-cpu 2 --limit-memory 512mb http
docker service inspect --pretty http
docker ps -a.

# Step 2 - Update Replicas
# Task
# As an alternative to docker service scale, it is possible to use the update to define update how many replicas should be running. Below will update the replicas from two to six. Docker will then reschedule the additional four containers to be deployed.

docker service update --replicas=6 http
docker service inspect --pretty http

# Step 3 - Update Image
# Task
# The following command will re-create the instances of our HTTP service with :v2 tag of the Docker Image.

docker service update --image katacoda/docker-http-server:v2 http
docker ps
curl http://docker

# Step 4 - Rolling Updates
# Task
# The two parameters are applied when running docker service update. In the example it will update one container at a time, waiting 10 seconds in-between each update. The update will be affecting the Docker Image used, but the parameters can apply to any of the possible update values

docker service update --update-delay=10s --update-parallelism=1 --image katacoda/docker-http-server:v3 http
docker ps
curl http://docker