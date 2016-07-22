# Dockerizing Node.js

# Learn how to deploy Node.js applications as containers

# Step 1 - Base Image
# Task: Define Base Environment, Creating a Dockerfile
# Set the FROM :, RUN and WORKDIR on separate lines to configure the base environment for deploying your application.

FROM node:0.10.38
RUN mkdir -p /home/scrapbook/tutorial/app
WORKDIR /home/scrapbook/tutorial/app

# Step 2 - NPM Install
# Task: Add Dockerfile Lines

COPY package.json /home/scrapbook/tutorial/app/package.json
RUN npm install

# Step 3 - Configuring Application
# Task: Deploy Application

COPY . /home/scrapbook/tutorial/app
EXPOSE 3000
CMD [ "npm", "start" ]

# Step 4 - Building & Launching Container

docker build -t my-nodejs-app .
docker images
docker run -d --name my-running-app -p 3000:3000 my-nodejs-app
curl localhost:3000

# Step 5 - Environment Variables

docker run -d --name my-production-running-app -e NODE_ENV=production -p 3000:3000 my-nodejs-app