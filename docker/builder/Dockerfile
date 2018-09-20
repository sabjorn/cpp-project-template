# Container with build tools for compiling your projects
# Also works great as a development tool
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

# debug runtime dependencies
RUN buildDeps='make cmake build-essential vim' \
    && set -x \
    && apt-get update && apt-get install -y $buildDeps --no-install-recommends \
    && rm -rf /var/lib/apt/lists/*