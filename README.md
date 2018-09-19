# Cpp Project Template
## About
This is a small project to be used as the base for C++ projects. The goal is to have a useful tool for quickly and easily starting a C++ project.

## Docker
### "Microservice"
A **Dockerfile** is included in the top level of this project to automatically build and run the C++ application.

#### Build
First, build the `builder` docker container:

```
docker build -t sabjorn/cpp-project-template_builder ./docker/builder/
```

This will be used as part of a [multi-stage build](https://docs.docker.com/develop/develop-images/multistage-build) process (saving image size) AND can also be used as a development container.

Next, build the application docker iamge:

```
docker build -t sabjorn/cpp-project-template_app .
```

#### Run
After building the container, run the container by using the command:

```
docker run -it --rm sabjorn/cpp-project-template_app
```