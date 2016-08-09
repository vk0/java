# Deploy ELK stack and aggregate container logs

# Learn how to deploy the ELK (Elastic, Logstash, Kibana) stack and start aggregating container logs

# Step 1 - Start Elasticsearch
# It's important to set the environment variable LOGSPOUT=ignore when launching your ELK infrastructure. This indicates that LogSpout shouldn't be aggregating the logs for this container.

docker run -d \
  -p 9200:9200 \
  -p 9300:9300 \
  --name elk_es \
  -e LOGSPOUT=ignore \
  elasticsearch:1.5.2

# Step 2 - Start Kibana

docker run -d \
  -p 5601:5601 \
  --link elk_es:elasticsearch \
  --name kibana \
  -e LOGSPOUT=ignore \
  kibana:4.1.2

# Step 3 - Start Logstash

# Task 1
# The first task is to create a data container storing our configuration file. More details on Data Containers is covered in our scenario.

docker create -v /config --name logstash_config busybox; docker cp logstash.conf logstash_config:/config/

# Task 2
# The second task is to launch the Logstash instance using the Data Container with volumes-from.

docker run -d \
  -p 5000:5000 \
  -p 5000:5000/udp \
   --volumes-from logstash_config \
  --link elk_es:elasticsearch \
  --name logstash \
  -e LOGSPOUT=ignore \
  logstash:2.1.1  -f /config/logstash.conf

# Step 4 - Start Logspout

ip=$(ping -c 1 docker | awk -F '[()]' '/PING/{print $2}')

docker run -d \
  -v /var/run/docker.sock:/tmp/docker.sock \
  --name logspout \
  -e LOGSPOUT=ignore \
  -e DEBUG=true \
  --publish=$ip:8000:80 \
  gliderlabs/logspout:master syslog://$ip:5000

# Step 5 - Wait for Kibana to load
# You can check the health of ElasticSearch using

curl 'http://docker:9200/_cat/health?v'

# Step 6 - Generate Logs
# Task
# Launch the following bash script. Logspout will detect when it starts and push the logs into Logstash.

docker run -d ubuntu bash -c 'for i in {0..60}; do echo "Logging Message $i"; sleep 1; done'

# Step 7 - View Logs

curl docker:8000/logs
docker logs logstash