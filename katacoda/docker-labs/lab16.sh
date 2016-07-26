# See Container Metrics With Docker Stats

# Gain insights into CPU, Memory and Network IO of your running containers

# Step 1 - Single Container
# The environment has a container running with the name nginx. You can find the stats for the container by using:

docker stats nginx

# Step 2 - Multiple Containers

docker ps -q | xargs docker stats