# Securely Joining Swarm Mode Cluster

# Learn how to ensure that your Swarm Mode cluster is secure

# Step 1 - Initialise Swarm Mode
# Initialise the cluster using

docker swarm init --secret mypassword

# Step 2 - Join Cluster using password

docker swarm join 172.17.0.38:2377
docker swarm join 172.17.0.38:2377 --secret test
docker swarm join 172.17.0.38:2377 --secret mypassword
docker node ls

# Step 3 - Disable Auto Accept
# When initialising the cluster, specify the auto-accept to none to force both workers and managers to require acceptance after joining.

docker swarm init --auto-accept=none --secret mypassword

# Step 4 - Join without Auto-Accept
# Join the cluster as before with the password as before.

docker swarm join 172.17.0.38:2377 --secret mypassword


# Step 5 - Manually Accept Nodes
# With the pending node, someone is required to use the Docker CLI to accept the node.
# Task
# The first task is to identify the ID or Hostname of the pending node. This is done via the CLI using docker node ls

docker node accept $(docker node ls -q | tail -n1)
docker node accept $(docker node ls -q | head -n1)

# Step 6 - Deploy Service
# The accepted node is now able to start processing requests and deploying containers
# Task
# Deploy a HTTP server. After a few moments you should see it deployed onto the newly accepted host.

docker service create --replicas 2 -p 80:80 katacoda/docker-http-server
docker ps
