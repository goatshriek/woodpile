#!/bin/sh

autoreconf \
&& mkdir build \
&& cd build \
&& ../configure --enable-parameter-validation \
&& make \
&& make check
