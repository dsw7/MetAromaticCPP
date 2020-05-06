from met_aromatic import met_aromatic

if __name__ == '__main__':
    TEST_CODE = "1rcy"
    TEST_CHAIN = "A"
    TEST_DISTANCE_CUTOFF = 6.0
    met_aromatic(TEST_CODE.encode(), TEST_CHAIN.encode(), TEST_DISTANCE_CUTOFF)
