# Create Data Containers

# Learn how to use Data Containers and volumes-from property

# Step 1 - Create Container
# Task
# Create a Data Container for storing configuration files using

docker create -v /config --name dataContainer busybox

# Step 2 - Copy Files

docker cp config.conf dataContainer:/config/

# Step 3 - Mount Volumes From

docker run --volumes-from dataContainer ubuntu ls /config

# Step 4 - Export / Import Containers

docker export dataContainer > dataContainer.tar.gz
docker import dataContainer.tar.gz