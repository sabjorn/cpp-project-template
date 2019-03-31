# Multi-Stage build, uses build tools from ./docker/builder/Dockerfile
FROM sabjorn/cpp-project-template_builder as builder

# Copy project files in
RUN mkdir app
COPY ./ ./app

# Build Project
ARG BUILDFLAG="-j4"
ARG TEST_ON_BUILD=false
RUN set -x \
    && mkdir -p /app/build \
    && cd /app/build \
    && cmake .. \
    && make $BUILDFLAG \
    && mkdir -p app_tests \
    && cp test_* ./app_tests \
    && if [ "$TEST_ON_BUILD" = true ]; then make test; fi

# Our actual application 
FROM debian:stretch-slim
MAINTAINER Steven A. Bjornson <info@sabjorn.net>
COPY --from=builder /app/build/app /usr/local/bin/
COPY --from=builder /app/build/app_tests /usr/local/bin/tests
COPY ./entrypoint.sh /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]