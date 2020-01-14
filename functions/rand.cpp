// function random. This function can generate large numbers.

int myRand() {
    const long n = 2145678965L;
    const long a = 763214L;
    const long b = 88844L;
    const long c = 7766L;

    static long seed = 12345678L;
    long hi = seed / b;
    long lo = seed - b * hi;
    long t = a * lo - c * hi;

    if (t > 0)
        seed = t;
    else
        seed = t + n;

    return seed;
}
