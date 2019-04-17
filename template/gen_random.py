#!/usr/bin/python3
from sys import *
from kg.generators import * ### @import
from formatter import * ### @import

A = 10**9

@listify
def gen_random(rand, *args):
    T, N = map(int, args[:2])
    for cas in range(T):
        n = rand.randint(1, N)
        yield [rand.randint(-A, A) for i in range(n)]


if __name__ == '__main__':
    write_to_file(print_to_file, gen_random, argv[1:], stdout)
