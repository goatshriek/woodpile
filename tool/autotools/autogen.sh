#!/bin/sh

autoreconf \
&& mkdir build \
&& cd build \
&& ../configure --enable-parameter-validation --enable-allocation-validation --enable-all-hashers \
&& make \
&& make check
