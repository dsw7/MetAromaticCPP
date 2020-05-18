from json import loads
from pytest import mark
from met_aromatic import met_aromatic

TEST_DATA = [loads(line) for line in open('test_data.json')][0:100]
TEST_CODES = [entry['_id'] for entry in TEST_DATA]
TEST_CHAIN = 'A'
TEST_DISTANCE_CUTOFF = 6.0
TEST_ANGLE_CUTOFF = 109.5
TOLERANCE = 0.1

def helper_test_norm(results_test, results_control):
    sum_test = sum(([i['norm'] for i in results_test['results']]))
    sum_control = sum([i['norm'] for i in results_control['results']])
    assert abs(sum_test - sum_control) <= TOLERANCE, "Vector norms do not match"

def helper_test_met_theta(results_test, results_control):
    sum_test = sum(([i['met_theta_angle'] for i in results_test['results']]))
    sum_control = sum([i['met_theta_angle'] for i in results_control['results']])
    assert abs(sum_test - sum_control) < TOLERANCE, "Met-theta angles do not match"

def helper_test_met_phi(results_test, results_control):
    sum_test = sum(([i['met_phi_angle'] for i in results_test['results']]))
    sum_control = sum([i['met_phi_angle'] for i in results_control['results']])
    assert abs(sum_test - sum_control) < TOLERANCE, "Met-phi angles do not match"

def helper_test_met_residue_position(results_test, results_control):
    set_test = set(i['methionine_position'] for i in results_test['results'])
    set_control = set(i['methionine_position'] for i in results_control['results'])
    assert set_test == set_control, "Methionine residue positions do not match"

def helper_test_aromatic_residue_position(results_test, results_control):
    set_test = set(i['aromatic_position'] for i in results_test['results'])
    set_control = set(i['aromatic_position'] for i in results_control['results'])
    assert set_test == set_control, "Aromatic residue positions do not match"

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
    if results_test['exit_code'] == 0:
        helper_test_norm(results_test, results_control)
        helper_test_met_theta(results_test, results_control)
        helper_test_met_phi(results_test, results_control)
        helper_test_met_residue_position(results_test, results_control)
        helper_test_aromatic_residue_position(results_test, results_control)
