#!/bin/sh

autoreconf \
&& mkdir build \
&& cd build \
&& ../configure --enable-parameter-validation --enable-allocation-validation \
&& make \
&& make check
