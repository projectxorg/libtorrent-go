#!/usr/bin/env bash

set -ex
if [ ! -f "openssl-${OPENSSL_VERSION}.tar.gz" ]; then
  wget -q https://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz
fi
echo "$OPENSSL_SHA256  openssl-${OPENSSL_VERSION}.tar.gz" | sha256sum -c -
tar -xzf openssl-${OPENSSL_VERSION}.tar.gz
rm openssl-${OPENSSL_VERSION}.tar.gz
cd openssl-${OPENSSL_VERSION}/
CROSS_COMPILE=${CROSS_TRIPLE}- ./Configure threads no-shared ${OPENSSL_OPTS} --prefix=${CROSS_ROOT}
make -j $(cat /proc/cpuinfo | grep processor | wc -l) 
make install 
rm -rf `pwd`
