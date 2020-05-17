#!/usr/bin/python3
import sys
from json import dumps
from met_aromatic import met_aromatic


def test():
    test_code = sys.argv[1]
    test_chain = "A"
    test_distance_cutoff = 6.0
    test_angle_cutoff = 109.5
    results = met_aromatic(
        test_code,
        test_chain,
        test_distance_cutoff,
        test_angle_cutoff
    )
    return results


if __name__ == '__main__':
    print(dumps(test(), indent=4))
