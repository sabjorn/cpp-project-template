# Multi-Stage build, uses build tools from ./docker/builder/Dockerfile
FROM sabjorn/cpp-project-template_builder as builder

# Copy project files in
RUN mkdir app
COPY ./ ./app

# Build Project
ARG BUILDFLAG="-j4"
RUN set -x \
    && mkdir -p /app/build \
    && cd /app/build \
    && cmake .. \
    && mkdir /poop \
    && make $BUILDFLAG

# TODO: Run Tests

# Our actual application 
FROM debian:stretch-slim
MAINTAINER Steven A. Bjornson <info@sabjorn.net>
COPY --from=builder /app/build/app /usr/local/bin/
ENTRYPOINT ["app"]