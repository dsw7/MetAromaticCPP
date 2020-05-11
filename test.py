from met_aromatic import met_aromatic


def test():
    test_code = "1uri"
    test_chain = "A"
    test_distance_cutoff = 6.0
    test_angle_cutoff = 109.5
    return met_aromatic(
    	test_code.encode(),
    	test_chain.encode(),
    	test_distance_cutoff,
    	test_angle_cutoff
    )


if __name__ == '__main__':
	return_value = test()
	print(return_value)