from os import path
from json import loads
from pytest import mark
from met_aromatic import met_aromatic


TEST_DATA = [loads(line) for line in open('test_data.json')][25:50]
TEST_CODES = [entry['_id'] for entry in TEST_DATA]
TEST_CHAIN = 'A'
TEST_DISTANCE_CUTOFF = 6.0
TEST_ANGLE_CUTOFF = 109.5


@mark.parametrize('results_control', TEST_DATA, ids=TEST_CODES)
def test_me(results_control):
    results_test = met_aromatic(
        results_control['_id'].encode(),
        TEST_CHAIN.encode(),
        TEST_DISTANCE_CUTOFF,
        TEST_ANGLE_CUTOFF
    )

    if not results_control['exit_status']:
        exit_status_control = 'Success'
    else:
        exit_status_control = results_control['exit_status']

    assert results_test['exit_status'] == exit_status_control
