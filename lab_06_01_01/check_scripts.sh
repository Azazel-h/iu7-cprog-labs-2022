#!/bin/bash
echo -- START --
find . -name '*.sh' -print0 |
    while IFS= read -r -d '' script; do
        echo "CHECKING - $script"
        shellcheck "$script"
    done
echo -- ENDED --