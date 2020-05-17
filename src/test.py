from json import loads
from pytest import mark
from met_aromatic import met_aromatic

TEST_DATA = [loads(line) for line in open('test_data.json')][25:50]
TEST_CODES = [entry['_id'] for entry in TEST_DATA]
TEST_CHAIN = 'A'
TEST_DISTANCE_CUTOFF = 6.0
TEST_ANGLE_CUTOFF = 109.5

@mark.parametrize('results_control', TEST_DATA, ids=TEST_CODES)
def test_met_aromatic(results_control):
    results_test = met_aromatic(
        results_control['_id'],
        TEST_CHAIN,
        TEST_DISTANCE_CUTOFF,
        TEST_ANGLE_CUTOFF
    )

    assert results_test['exit_status'] == results_control['exit_status']
    assert results_test['exit_code'] == results_control['exit_code']

def test_invalid_angle_exit_code():
    assert met_aromatic(
        '1rcy',
        TEST_CHAIN,
        TEST_DISTANCE_CUTOFF,
        361.00
    )['exit_code'] == 3

def test_invalid_angle_exit_status():
    assert met_aromatic(
        '1rcy',
        TEST_CHAIN,
        TEST_DISTANCE_CUTOFF,
        361.00
    )['exit_status'] == "Invalid cutoff angle"

def test_invalid_angle_exit_code_negative():
    assert met_aromatic(
        '1rcy',
        TEST_CHAIN,
        TEST_DISTANCE_CUTOFF,
        -361.00
    )['exit_code'] == 3

def test_invalid_angle_exit_status_negative():
    assert met_aromatic(
        '1rcy',
        TEST_CHAIN,
        TEST_DISTANCE_CUTOFF,
        -361.00
    )['exit_status'] == "Invalid cutoff angle"

def test_invalid_distance_exit_code():
    assert met_aromatic(
        '1rcy',
        TEST_CHAIN,
        -1.00,
        TEST_ANGLE_CUTOFF
    )['exit_code'] == 3

def test_invalid_distance_exit_status():
    assert met_aromatic(
        '1rcy',
        TEST_CHAIN,
        -1.00,
        TEST_ANGLE_CUTOFF
    )['exit_status'] == "Invalid cutoff distance"

def test_invalid_pdb_code_exit_code():
    assert met_aromatic(
        'abcd',
        TEST_CHAIN,
        TEST_DISTANCE_CUTOFF,
        TEST_ANGLE_CUTOFF
    )['exit_code'] == 4

def test_invalid_pdb_code_exit_status():
    assert met_aromatic(
        'abcd',
        TEST_CHAIN,
        TEST_DISTANCE_CUTOFF,
        TEST_ANGLE_CUTOFF
    )['exit_status'] == "PDB entry does not exist"
