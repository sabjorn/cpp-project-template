# Multi-Stage build, uses build tools from ./docker/builder/Dockerfile
FROM sabjorn/cpp-project-template_builder as builder

# Copy project files in
RUN mkdir app
COPY ./ ./app

# Build Project
ARG BUILDFLAG="-j4"
ARG TEST=true
RUN set -x \
    && mkdir -p /app/build \
    && cd /app/build \
    && cmake .. \
    && make $BUILDFLAG \
    && if [ "$TEST" = true ]; then make test; fi

# TODO: Run Tests

# Our actual application 
FROM debian:stretch-slim
MAINTAINER Steven A. Bjornson <info@sabjorn.net>
COPY --from=builder /app/build/app /usr/local/bin/
ENTRYPOINT ["app"]