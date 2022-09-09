#!/bin/bash

all_scripts=$(find . -name "*.sh")

for script in $all_scripts; do
    echo "CHECKING - $script"
    shellcheck "$script"
done