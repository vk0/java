# Building Container Images

# Learn how to build and launch your own container images

# Step 1 - Base Images
# Task: Creating a Dockerfile

FROM nginx:1.9

# Step 2 - Running Commands
# Task
# A new index.html file has been created for you which we want to serve from our container. On the next line after the FROM command, use the COPY command to copy index.html into a directory called /usr/share/nginx/html

COPY index.html /usr/share/nginx/html/index.html

# Step 3 - Exposing Ports

EXPOSE 80

# Step 4 - Default Commands

CMD ["nginx", "-g", "daemon off;"]

# Step 5 - Building Containers

docker build -t my-nginx-image:latest .

# Step 6 - Launching New Image

docker run -d -p 80:80 my-nginx-image
curl localhost