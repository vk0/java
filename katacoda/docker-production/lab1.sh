# Launch Private Docker Registry

# Learn how to launch a private Docker Registry with SSL

# Step 1 - Starting Registry
# It's important to mount the volume /var/lib/registry. This is where the Registry will store all of the pushed images. Mounting the directory will allow you to restart and upgrade the container in future.

docker run -d -e \
 VIRTUAL_HOST=registry.test.training.katacoda.com \
 -v /opt/registry/data:/var/lib/registry \
 -p 5000:5000 \
 --name registry registry:2

 # Step 2 - SSL

docker create -v /etc/nginx/certs --name nginx_certs busybox
docker cp certs/registry.test.training.katacoda.com.crt nginx_certs:/etc/nginx/certs/
docker cp certs/registry.test.training.katacoda.com.key nginx_certs:/etc/nginx/certs/

# Step 3 - Starting NGINX Proxy
# We prefer using nginx-proxy in front of the Registry as we find it easier to map domains and ports to the Registry. This also allows us to load balance and provide high availability.

docker run -d -p 80:80 -p 443:443 \
  --volumes-from nginx_certs \
  -v /var/run/docker.sock:/tmp/docker.sock:ro \
  --name nginx \
  benhall/nginx-registry-proxy:1.9.6

# Step 4 - Testing
# We can test access to the registry using curl. The response should provide headers, for example Docker-Distribution-API-Version, indicating the request was processed by the Registry server.

curl -i https://registry.test.training.katacoda.com/v2/

# Step 5 - Pushing Images

docker tag redis registry.test.training.katacoda.com/redis
docker push registry.test.training.katacoda.com/redis

# Step 6 - Pulling Images

docker pull registry.test.training.katacoda.com/redis
