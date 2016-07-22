# Optimise Builds With Docker OnBuild

# Learn how to optimise your Dockerfile using OnBuild

# Step 1 - OnBuild
# Below is the Node.js OnBuild Dockerfile. Unlike in our previous scenario the application specify commands have been prefixed with ONBUILD.

FROM node:0.10.34
RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app
ONBUILD COPY package.json /usr/src/app/
ONBUILD RUN npm install
ONBUILD COPY . /usr/src/app
CMD [ "npm", "start" ]

# Step 2 - Application Dockerfile
# The create advantage of OnBuild images is that our Dockerfile is now much simpler and can be easily re-used across multiple projects without having to re-run the same steps improving build times.

FROM node:0.10.38-onbuild
EXPOSE 3000

# Step 3 - Building & Launching Container
docker build -t my-nodejs-app .
docker run -d --name my-running-app -p 3000:3000 my-nodejs-app
curl localhost:3000