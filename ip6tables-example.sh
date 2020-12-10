#!/bin/bash

ip6tables -A PREROUTING -t mangle -p tcp --syn -s 2001:1000::/32 -j NFQUEUE --queue-num 0
ip6tables -A PREROUTING -t mangle -p tcp --syn -d 2001:2000::/32 -j NFQUEUE --queue-num 0
ip6tables -A PREROUTING -t nat -s 2001:1000::/32 -p tcp -j REDIRECT --to 5000
ip6tables -A PREROUTING -t nat -d 2001:2000::/32 -p tcp -j REDIRECT --to 5000

