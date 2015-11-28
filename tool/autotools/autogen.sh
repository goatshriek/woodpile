#!/bin/sh

autoreconf \
&& mkdir build \
&& cd build \
&& ../configure --enable-conditional-validation \
&& make \
&& make check
