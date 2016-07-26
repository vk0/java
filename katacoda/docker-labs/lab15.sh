# Orchestration using Docker Compose

# Learn how to use Docker Compose to orchestration multi-container applications

# Step 1 - Defining First Container
# Task: Defining First Container
# Docker Compose is based on a docker-compose.yml file. This file defines all of the containers and settings you need to launch your set of clusters.

# docker-compose.yml
web:
  build: .

# Dockerfile
FROM ocelotuproar/alpine-node:5.7.1-onbuild
EXPOSE 3000

# Step 2 - Defining Settingss
# docker-compose.yml

links:
    - redis

ports:
    - "3000"
    - "8000"

# Step 3 - Defining Second Container
# Define the second container with the name redis which uses the image redis. Following the YAML format, the container details would be:

redis:
    image: redis:alpine
    volumes:
        - /var/redis/data:/data

# Step 4 - Docker Up
# Launch your application using

docker-compose up -d

# Step 5 - Docker Management

docker-compose ps
docker-compose logs

# Step 6 - Docker Scale
# Scale the number of web containers you're running using the command

docker-compose scale web=3
docker-compose scale web=1

# Step 7 - Docker Stop
# As when we launched the application, to stop a set of containers you can use the command

docker-compose stop
docker-compose rm

