FROM muslcc/x86_64:x86_64-linux-musl

RUN apk add --no-cache \
    alpine-sdk \
    bash \
    curl wget git openssh-client \
    make automake libtool cmake autoconf pcre-dev perl-utils \
    musl-dev \
    bison \
    tar bzip2 gzip unzip \
    file \
    rsync \
    sed \
    upx \
    go
