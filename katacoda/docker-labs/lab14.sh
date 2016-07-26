# Load Balancing Containers

# Learn how you can use NGINX to load balance containers using Service Discovery & Docker's Metadata

# Step 1 - NGINX Proxy
# Because we're using a DEFAULT_HOST, any requests which come in will be directed to the container that has been assigned the HOST proxy.example.

docker run -d -p 80:80 -e DEFAULT_HOST=proxy.example -v /var/run/docker.sock:/tmp/docker.sock:ro --name nginx jwilder/nginx-proxy

# Step 2 - Single Host
# Starting Container
# For Nginx-proxy to start sending requests to a container you need to specify the VIRTUAL_HOST environment variable. This variable defines the domain where requests will come from and should be handled by the container.
# In this scenario we'll set our HOST to match our DEFAULT_HOST so it will accept all requests.

docker run -d -p 80 -e VIRTUAL_HOST=proxy.example katacoda/docker-http-server

# Step 3 - Cluster
# Launch a second container using the same command as we did before.
# If we execute a request to our proxy using curl http://docker then the request will be handled by our first container. A second HTTP request will return a different machine name meaning it was handled by our second container.

docker run -d -p 80 -e VIRTUAL_HOST=proxy.example katacoda/docker-http-server

# Step 4 - Generated NGINX Configuration
# While nginx-proxy automatically creates and configures NGINX for us, if you're interested in what the final configuration looks like then you can output the complete config file with docker exec as shown below.

docker exec nginx cat /etc/nginx/conf.d/default.conf