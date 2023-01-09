#!/usr/bin/env bash
set -eou pipefail

echo "Waiting for all pods to be running $(date)"

artifacts_dir=$1

export KUBECONFIG=$artifacts_dir/kubeconfig

max_tries=1000
count=0
while true; do
    ready_containers="$(kubectl -n stackrox get pod -o jsonpath='{.items[*].status.containerStatuses[?(@.ready == true)]}')"
    not_ready_containers="$(kubectl -n stackrox get pod -o jsonpath='{.items[*].status.containerStatuses[?(@.ready == false)]}')"
    if [[ -n "$ready_containers" && -z "$not_ready_containers" ]]; then
	echo "All pods are running $(date)"
        break
    fi
    count=$((count + 1))
    if [[ "$count" -gt "$max_tries" ]]; then
        exit 1
    fi
    sleep 1
done
