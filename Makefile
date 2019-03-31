NAMESPACE := sabjorn
PROJECT := cpp-project-template
PLATFORM := linux
ARCH := amd64
DOCKER_IMAGE := $(NAMESPACE)/$(PROJECT)

GITSHA := $(shell git rev-parse --short HEAD)
IMAGE_LIST := $(shell docker images --format '{{.Repository}}:{{.Tag}}' | grep '$(DOCKER_IMAGE):')

all: help  
   
help:
	@echo "---" 
	@echo "IMAGE: $(DOCKER_IMAGE)"  
	@echo "GITSHA: $(GITSHA)" 
	@echo "---" 
	@echo "build/run app:"
	@echo "make build - build Docker app image"
	@echo "make tests - run app tests in Docker image"
	@echo "make run - run app in Docker image"
	@echo "make tag - tag app Docker image as latest"
	@echo "make clean - remove ALL app Docker image"
	@echo "---"
	@echo "Dev"
	@echo "make debug - enter app Docker image with bash"
	@echo "make builder - build 'builder' Docker image with bash"
	@echo "make run_builder - enter 'builder' Docker image with bash (C++ development container)"
	@echo "make clean_all - remove ALL Docker images (app and builder)"
	@echo ""

builder:
	docker build -t $(DOCKER_IMAGE)_builder -f Dockerfile.builder .

build: builder
	docker build -t $(DOCKER_IMAGE):$(GITSHA) -f Dockerfile .

tests: build
	@echo "this will run tests eventually"

run: build
	docker run -it --rm --name=$(PROJECT) $(DOCKER_IMAGE):$(GITSHA)

run_builder: builder
	docker run -it --rm --name=$(PROJECT)_builder $(DOCKER_IMAGE)_builder bash

debug:
	docker run -it --rm --name=$(PROJECT) --entrypoint="" $(DOCKER_IMAGE):$(GITSHA)	bash

tag:
	docker tag $(DOCKER_IMAGE):$(GITSHA) $(DOCKER_IMAGE):$(latest)

clean:
	docker rmi -f $(IMAGE_LIST)

clean_all: clean
	docker rmi -f $(DOCKER_IMAGE)_builder