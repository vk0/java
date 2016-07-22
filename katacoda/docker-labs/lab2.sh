# Deploy Static HTML Website as Container

# Learn how to run a static HTML website using Nginx

# Step 1 - Create Dockerfile
# Create your Dockerfile for building your image by copying the contents below into the editor.

FROM nginx:alpine
COPY . /usr/share/nginx/html

# Step 2 - Build Docker Image

docker build -t webserver-image:v1 .
docker images

# Step 3 - Run
docker run -d -p 80:80 webserver-image:v1
curl 0.0.0.0:80