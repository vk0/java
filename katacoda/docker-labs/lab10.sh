# Persisting Data Using Volumes

# Learn how to persist and share data between containers using Volumes

# Step 1 - Data Volumes

docker run  -v /docker/redis-data:/data --name r1 -d redis redis-server --appendonly yes
cat data | docker exec -i r1 redis-cli --pipe
ls /docker/redis-data
docker run  -v /docker/redis-data:/backup ubuntu ls /backup

# Step 2 - Shared Volumes

docker run --volumes-from r1 -it ubuntu ls /data

# Step 3 - Read-only Volumes

docker run -v /docker/redis-data:/data:ro -it ubuntu rm -rf /data