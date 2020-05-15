from os import path
from json import loads
from pytest import mark
from met_aromatic import met_aromatic


SIZE = 5
TEST_DATA = [loads(line) for line in open('test_data.json')][0:5]
TEST_CODES = [entry['_id'] for entry in TEST_DATA]
TEST_CHAIN = 'A'
TEST_DISTANCE_CUTOFF = 6.0
TEST_ANGLE_CUTOFF = 109.5


@mark.parametrize('entry', TEST_DATA, ids=TEST_CODES)
def test_me(entry):
    test_code = entry['_id']
    control = met_aromatic(
        test_code.encode(),
        TEST_CHAIN.encode(),
        TEST_DISTANCE_CUTOFF,
        TEST_ANGLE_CUTOFF
    )

    assert control['exit_status'] == entry['exit_status']
