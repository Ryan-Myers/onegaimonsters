#!/bin/bash

for f in assets/overlays/data_801E0560/*.bin
do
    echo $f
    hexyl --length=16 $f
done
