#!/usr/bin/bash

for $i in 'seq 00 99'; do
    eval $(./crack_digit digits/1_$i.pbm);
done
