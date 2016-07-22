# Ignoring Files During Build

# Learn how to ignore files being sent to the Docker Build Context or included in an image

# Step 1 - Docker Ignore
# The following command would include passwords.txt in our .dockerignore file and ensure that it didn't accidentally end up in a container. The .dockerignore file would be stored in source control and share with the team to ensure that everyone is consistent.

echo passwords.txt >> .dockerignore

# Step 2 - Docker Build Context
# The .dockerignore file can ensure that sensitive details are not included in a Docker Image, however they can also be used to improve the build time of images.

docker build -t no-large-file-context .
# Sending build context to Docker daemon 104.9 MB !!!

# Step 3 - Optimised Build
# In the same way we used the .dockerignore file to exclude sensitive files, we can use it to exclude files which we don't want to be sent to the Docker Build Context during build.

echo big-temp-file.img >> .dockerignore
docker build -t no-large-file-context .
# Sending build context to Docker daemon 4.096 kB !!!