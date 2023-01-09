#!/usr/bin/env bash
set -eou pipefail

json_config_file=$1

DIR="$(cd "$(dirname "$0")" && pwd)"

json_config_file_prefix="$(echo $json_config_file | sed 's|.json||')"
for num_ports in 100 200 400 800 1600 3200 6400 12800; do
	new_json_config_file="${json_config_file_prefix}_num_ports_${num_ports}.json"
	test_dir="$(cat "$json_config_file" | jq .test_dir | tr -d \")"
	new_test_dir="\"${test_dir}${num_ports}\""
	new_json_config="$(cat "$json_config_file" | jq .load.open_close_ports_load.num_ports="$num_ports")"
	new_json_config="$(echo "$new_json_config" | jq .test_dir="$new_test_dir")"
	echo "$new_json_config" > "$new_json_config_file"
	"$DIR"/performance-test.sh "$new_json_config_file"
done

