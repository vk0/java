# Docker and Makefiles

# In this scenario you will learn how to use Make for managing docker image creation

# Step 1 - Dockerfile

# Dockerfile
FROM busybox
CMD ["date"]

docker build -t benhall/docker-make-example .

# Step 2 - Makefile

# Makefile
build:
  docker build -t benhall/docker-make-example .

# Step 4 - Additional Commands

run:
  docker run benhall/docker-make-example

# Step 5 - Setting Default Command

# Makefile
NAME = benhall/docker-make-demo

default: build

build:
    docker build -t $(NAME) .

push:
    docker push $(NAME)

debug:
    docker run --rm -it $(NAME) /bin/bash

run:
    docker run --rm $(NAME)

release: build push