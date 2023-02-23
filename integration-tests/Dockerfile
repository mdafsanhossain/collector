FROM quay.io/rhacs-eng/apollo-ci:collector-0.3.56-1-g1069e986ae

ENV TEST_ROOT=$GOPATH/src/github.com/stackrox/collector/integration-tests/

WORKDIR $TEST_ROOT

COPY go.mod .
COPY go.sum .

RUN go mod download

COPY integration_test.go .
COPY suites suites

COPY scripts/test-runner.sh .

ENTRYPOINT ["./test-runner.sh"]
