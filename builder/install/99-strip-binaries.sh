#!/usr/bin/env bash

while read f; do
	[[ -f "$f" ]] || continue
	if ! [[ -x "$f" || "$f" =~ .*\.so(\.|$) || "$f" =~ .*\.a(\.|$) ]]; then
		continue
	fi

	strip --strip-unneeded "$f"
done < <(find /usr/local -type f)
