# Read Vault Secrets from Containers
#
# Learn how to read secrets from Hashicorp Vault from inside Docker Containers using Volume Drivers

# Step 1 - Start Vault

> cat start-vault.sh
docker create -v /config --name config busybox; docker cp vault.hcl config:/config/;
docker run -d --name consul -p 8500:8500 consul:v0.6.4 agent -dev -client=0.0.0.0
docker run -d --name vault-dev --link consul:consul -p 8200:8200 --volumes-from config cgswong/vault:0.5.3
 server -config=/config/vault.hcl

 > cat unseal-vault.sh
export VAULT_ADDR=http://127.0.0.1:8200
docker exec -it vault-dev vault init -address=${VAULT_ADDR} > keys.txt
docker exec -it vault-dev vault unseal -address=${VAULT_ADDR} $(grep 'Key 1:' keys.txt | awk '{print $NF}'
)
docker exec -it vault-dev vault unseal -address=${VAULT_ADDR} $(grep 'Key 2:' keys.txt | awk '{print $NF}'
)
docker exec -it vault-dev vault unseal -address=${VAULT_ADDR} $(grep 'Key 3:' keys.txt | awk '{print $NF}'
)

# The final stage is to obtain the access token; this is outputted when we initialised and unsealed the vault.

export VAULT_TOKEN=$(grep 'Initial Root Token:' keys.txt | awk '{print substr($NF, 1, length($NF)-1)}')

# By logging in we can now start storing and persisting data

vault auth -address=${VAULT_ADDR} ${VAULT_TOKEN}

# Step 2 - Create Data
# Save Data
# Run the following command to write data into the Vault. Vault will encrypt the data before storing it in Consul. The name of the key is db-password which we're storing under the collection app-1. By grouping secrets around applications makes them easier to manage. It also allows you to add restrictions to only allow certain users to access certain groups.

vault write -address=${VAULT_ADDR} \
  secret/app-1/db-password value=mysecretpassword

# Note: If you're using the CLI to populate Vault, ensure you don't persist the commands to your bash history file. You can write data to Vault in multiple ways. For example via a file with

vault write secret/password value=@data.txt.

# Step 3 - Configure Docker Volume Driver

sudo nohup ./docker-volume-libsecret \
  --addr $VAULT_ADDR \
  --backend vault \
  --store-opt token=$VAULT_TOKEN </dev/null &>/dev/null &

# Start Container

  docker run -ti --rm \
  --volume-driver libsecret \
  -v secret/app-1/:/secrets \
  alpine ash

# Step 4 - Read Secrets

cat secrets/db-password

# The Volume Driver only provides read access to Vault. If we try to create new keys or change the value it will result in an error.

echo 'Will this be stored?' > secrets/db-password

# Users also cannot list all contents of Vault, this is by design and ensures that attackers cannot easily view all the available content.

ls /secrets