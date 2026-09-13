ARG BASE_IMAGE=ghcr.io/zephyrproject-rtos/zephyr-build:latest
FROM ${BASE_IMAGE}

USER root

ARG UID=1000
ARG GID=1000

RUN groupmod -g ${GID} user && \
    usermod -u ${UID} -g ${GID} user && \
    chown -R user:user /workdir

RUN pip install --no-cache-dir \
    grpcio-tools \
    codechecker

RUN apt-get update && \
    apt-get install --no-install-recommends -y \
    clang \
    clang-tidy \
    build-essential \
    curl \
    doxygen \
    gcc-multilib && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

USER user
WORKDIR /workdir

CMD ["/bin/bash"]
