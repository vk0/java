# Deploying Weave Net For Multi-host Networking

# In this scenario you will learn how to use Weave Net for networking

# Step 1 - Link Two Docker Hosts

sudo curl -L git.io/weave -o /usr/local/bin/weave
sudo chmod +x /usr/local/bin/weave
weave launch
weave launch 172.17.0.53
weave status

# Step 2 - Configure Host 1

eval $(weave env)

# Step 3 - Configure Host 2
# Similarly with the first host, to launch containers on the second host we also need to communicate via the proxy.

eval $(weave env)

# Step 4 - Start Service on Host 1

docker run --name ws -d katacoda/docker-http-server

# Step 5 - Access Service from Host 2
# We can send a HTTP using a containerized cURL install and see the response.

docker run ubuntu ping -c1 ws
docker run benhall/curl curl -sS ws