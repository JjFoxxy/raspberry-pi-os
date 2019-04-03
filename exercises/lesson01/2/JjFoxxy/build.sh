#!/bin/bash

#docker run --rm -v $(pwd):/build -w /build arm64_build_essential make $1
docker run -v $(pwd):/build -w /build arm64_build_essential
