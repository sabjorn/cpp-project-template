# Cpp Project Template
## About
This is a small project to be used as the base for C++ projects. The goal is to have a useful tool for quickly and easily starting a C++ project.

## Docker
A **Dockerfile** is included in the top level of this project to automatically build and run the C++ application.

This project uses a `Makefile` to automate the build/test/run stages.

### Make
All `make` commands should be run from the top level of the project.

A help message will appear by running:

```bash
make
```

#### Run
This will build all necessary parts and run the application as a Docker container:

```bash
make run
```

#### Clean
Remove Docker application image:

```bash
make clean
```

### Dev Image
This project uses the [multi-stage build](https://docs.docker.com/develop/develop-images/multistage-build) process (saving image size). This `builder` image can be used as a **development image**. This image contains all the build tools necessary to compile a simple C++ project, including the `GTest` suite.

This will build and run the builder image, entering thorough `bash`:

```bash
make run_builder
```