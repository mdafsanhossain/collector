#!/bin/bash

set -eo pipefail

echo "${QUAY_RHACS_ENG_RO_PASSWORD}" | docker login --username "${QUAY_RHACS_ENG_RO_USERNAME}" --password-stdin quay.io

go test $@
