# Advent of Code 2021

This is my attempt at the Advent of Code 2021 challenges by using C++.
I'll try to use Meson to organise my solutions as I want to try my hands at it.

The rest of this document will be my daily log of this challenge.

## Day 1
As expected, I spent more energy setting up Meson than solving the actual challenge. I'm only partly satisfied with the solution I came up with.
The `DepthWindow` class could be made more generic (able to handle more than 3 values and other types of values) with some template crafting.
There may also be facilities in the standard library to replace this entirely that I wasn't able to discover.
Also, reading an input file line by line took me a surprising amount of time to come with the solution I ended up with (which look quite trivial in
the end).

I feel a bit bad with the final result (everything in one `main.cpp` file, non-generic code & poor error handling) but all of that is to be throwaway
code in the end anyway so maybe I should shut that little voice in my head down :-).