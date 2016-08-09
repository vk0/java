# Deploying Weave Scope for Container Visualisation

# Learn about container visibility & monitoring using Scope

# Step 1 - Deploy Application
# To begin with, launch two linked containers to demonstrate a website/database architecture.

docker run -d --name redis redis
docker run -d --link redis:redis katacoda/redis-node-docker-example

# Step 2 - Launch Scope
# Weave Scope runs as a container and is accessed via HTTP.

sudo wget -O /usr/local/bin/scope \
https://github.com/weaveworks/scope/releases/download/latest_release/scope
sudo chmod a+x /usr/local/bin/scope
sudo scope launch

# Step 3 - Visualise using Scope

# As new containers are launched, Scope will automatically update to reflect the live architecture.
# Try launching additional front-end containers to see the results.

docker run -d --link redis:redis katacoda/redis-node-docker-example

# Step 4 - Inspecting Containers
# By clicking on a node (the hexagon in Scope) you can find out more information about the container.

# Step 5 - Sample Application
# As applications become more complicated, Scope enables you to view and manage how they're structured and their performance.
# To demonstrate this, Weave has created a Microservice reference application. Launch the reference architecture using Docker Compose.
# https://github.com/weaveworks/weaveDemo

docker-compose -f docker-compose-weavesock.yml up -d