uint32_t bounded_rand(rng_t& rng, uint32_t range) {
    std::uniform_int_distribution<uint32_t> dist(0, range-1);

    return dist(rng);
}