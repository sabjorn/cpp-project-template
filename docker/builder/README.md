## About
This Dockerfile is used to build a container with all the necessary tools for building and testing a C++ project.

## Usage
### Multi-Stage Build
Building the container will allow the **application image** (top level `Dockerfile`) to create a much lighter image.

Build this container (from this directory) with:

```
docker build -t sabjorn/cpp-project-template_builder .
```

or, from the top level of the projet with:

```
docker build -t sabjorn/cpp-project-template_builder ./docker/builder/
```

### Development
This container can also be used for development (it containes all the build tools) by running it with the top directory of this project volumed in:

```
docker run -it --rm -v <absolute path to top level of project>:/app sabjorn/cpp-project-template_builder bash
```