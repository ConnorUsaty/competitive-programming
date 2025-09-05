int minOperations(int n) {
    int res = 0;
    for (size_t i=0; i<16; ++i)
        if (__builtin_popcount(n + (1<<i)) < __builtin_popcount(n)) {
            n += 1 << i;
            ++res;
        }
    return res + __builtin_popcount(n);
}

// always better to add a power of 2 iff it decreases popcount