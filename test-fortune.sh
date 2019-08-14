#!/bin/bash

# Output fortune like echo, with real cowsay and cowsay++.
fortune | tee >(./bin_d/cowsay) >(cowsay -n)