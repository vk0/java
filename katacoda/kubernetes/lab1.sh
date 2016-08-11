
# Launch A Single Node Cluster

# Learn how to launch a Kubernetes cluster including DNS and Kube UI

# Step 1 - Etcd

docker run -d --name=etcd \
    --net=host \
    gcr.io/google_containers/etcd:2.2.1 \
    /usr/local/bin/etcd \
    --listen-client-urls=http://0.0.0.0:4001 \
    --advertise-client-urls=http://0.0.0.0:4001 \
    --data-dir=/var/etcd/data

# Step 2 - API Server

docker run -d --name=api \
    --net=host --pid=host --privileged=true \
    gcr.io/google_containers/hyperkube:v1.2.2 \
    /hyperkube apiserver \
    --insecure-bind-address=0.0.0.0 \
    --service-cluster-ip-range=10.0.0.1/24 \
    --etcd_servers=http://127.0.0.1:4001 \
    --cluster_name=kubernetes --v=2

# Step 3 - Master

docker run -d --name=kubs \
  --volume=/:/rootfs:ro \
  --volume=/sys:/sys:ro \
  --volume=/dev:/dev \
  --volume=/var/lib/docker/:/var/lib/docker:rw \
  --volume=/var/lib/kubelet/:/var/lib/kubelet:rw \
  --volume=/var/run:/var/run:rw \
  --net=host \
  --pid=host \
  --privileged=true \
  gcr.io/google_containers/hyperkube:v1.2.2 \
  /hyperkube kubelet \
  --containerized \
  --hostname-override="0.0.0.0" \
  --address="0.0.0.0" \
  --cluster_dns=10.0.0.10 --cluster_domain=cluster.local \
  --api-servers=http://localhost:8080 \
  --config=/etc/kubernetes/manifests-multis

# Step 4 - Proxy

docker run -d --name=proxy\
    --net=host \
    --privileged \
    gcr.io/google_containers/hyperkube:v1.2.2 \
    /hyperkube proxy \
    --master=http://0.0.0.0:8080 --v=2

# Step 5 - Kubectl
# The kubectl is the command line client used to communicate with the Master.

curl -o ~/.bin/kubectl http://storage.googleapis.com/kubernetes-release/release/v1.2.2/bin/linux/amd64/kubectl
chmod u+x ~/.bin/kubectl
export KUBERNETES_MASTER=http://host01:8080

# Step 6 - KubeDNS / SkyDNS
# For now use the create command to create the namespace and launch the containers.

cat kube-system.json
{
  "kind": "Namespace",
  "apiVersion": "v1",
  "metadata": {
    "name": "kube-system"
  }
}

cat skydns-svc.yaml
apiVersion: v1
kind: Service
metadata:
  name: kube-dns
  namespace: kube-system
  labels:
    k8s-app: kube-dns
    kubernetes.io/cluster-service: "true"
    kubernetes.io/name: "KubeDNS"
spec:
  selector:
    k8s-app: kube-dns
  clusterIP:  10.0.0.10
  ports:
  - name: dns
    port: 53
    protocol: UDP
  - name: dns-tcp
    port: 53
    protocol: TCP

kubectl create -f ~/kube-system.json
kubectl create -f ~/skydns-rc.yaml
kubectl create -f ~/skydns-svc.yaml

# Step 7 - Kube UI

kubectl create -f ~/dashboard.yaml

# https://2886795303-8080-ollie01.environments.katacoda.com/api/v1/proxy/namespaces/kube-system/services/kubernetes-dashboard

# Step 8 - Health Checks


> curl http://host01:4001/version
{"etcdserver":"2.2.1","etcdcluster":"2.2.0"}

> curl http://host01:8080/version
{
  "major": "1",
  "minor": "2",
  "gitVersion": "v1.2.2",
  "gitCommit": "528f879e7d3790ea4287687ef0ab3f2a01cc2718",
  "gitTreeState": "clean"
}
> export KUBERNETES_MASTER=http://host01:8080

> kubectl cluster-info
Kubernetes master is running at http://host01:8080
KubeDNS is running at http://host01:8080/api/v1/proxy/namespaces/kube-system/services/kube-dns

> kubectl get nodes
NAME      STATUS    AGE
0.0.0.0   Ready     5m