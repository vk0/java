# Adding Docker Metadata & Labels

# Create Labels and other Docker Metadata to tag your containers

# Step 1 - Docker Containers
Single Label
# To add a single label you use the l = option. The example below assigns a label called user with an ID to the container. This would allow us to query for all the containers running related to that particular user.

docker run -l user=12345 -d redis

# External File
# If you're adding multiple labels then these can come from a external file. The file needs to have a label on each line and then these will be attached to the running container.
# This line creates two labels in the file, one for the user and the second assigning a role.

echo 'user=123461' >> labels
echo 'role=cache' >> labels
docker run --label-file=labels -d redis

# Step 2 - Docker Images
# Single Label
# Within a Dockerfile you can assign a label using the LABEL instruction. Below the label vendor is created with the name Scrapbook.

LABEL vendor=Scrapbook

# Multiple Labels
# If we want to assign multiple labels then we can use the format below with a label on each line, joined together using a back-slash ("\"). Notice we're using the DNS notation format for labels which are related to third party tooling.

LABEL vendor=Scrapbook \ com.joinscrapbook.version=0.0.5 \ com.joinscrapbook.build-date=2015-07-01T10:47:29Z \ com.joinscrapbook.course=Docker

# Step 3 - Inspect
# Using the -f option you can filter the JSON response to just the Labels section we're interested in.

docker inspect -f "{{json .Config.Labels }}" rd
docker inspect -f "{{json .ContainerConfig.Labels }}" scrapbook-label-example

# Step 4 - Query By Label

docker ps --filter "label=user=scrapbook"
docker images --filter "label=vendor=Scrapbook"

# Step 5 - Daemon labels
# Labels are not only applied to images and containers but also the Docker Daemon itself. When you launch an instance of the daemon you can assign it labels to help identify how it should be used, for example if it's a development or production server or if it's more suited to particular roles such running databases.

docker -d \
-H unix:///var/run/docker.sock \
--label com.joinscrapbook.environment="production" \
--label com.joinscrapbook.storage="ssd"