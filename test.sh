#!/bin/bash

# Test for 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
echo "Testing with 100 random numbers..."
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

# Test for 500 random numbers
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
echo "Testing with 500 random numbers..."
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG