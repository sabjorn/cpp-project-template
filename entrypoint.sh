#!/usr/bin/env bash

INPUT=$(echo "$1" | tr '[:upper:]' '[:lower:]')
if [ "$INPUT" == "tests" ]; then
    for f in /usr/local/bin/tests/*; do $f; done;
else
    app
fi