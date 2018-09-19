FROM debian:stretch-slim
MAINTAINER Steven A. Bjornson <info@sabjorn.net>

# Add GTests
RUN buildDeps='git ca-certificates' \
    && set -x \
    && apt-get update && apt-get install -y $buildDeps --no-install-recommends \
    && rm -rf /var/lib/apt/lists/* \
    && git clone --depth 1 https://github.com/google/googletest \
    && cd ./googletest/googletest \
    && cp -r ./include/gtest /usr/local/include \
    && apt-get purge -y --auto-remove $buildDeps

# Build Project
RUN mkdir app
COPY ./ ./app

# Build Projet
ARG BUILDFLAG="-j4"
RUN buildDeps='make build-essential' \
    && set -x \
    && apt-get update && apt-get install -y $buildDeps --no-install-recommends \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /app/build \
    && cd /app/build \
    && cmake .. \
    && make $BUILDFLAG \
    && apt-get purge -y --auto-remove $buildDeps

RUN runDeps='make' \
    && set -x \
    && apt-get update && apt-get install -y $runDeps --no-install-recommends \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app