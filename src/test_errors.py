from met_aromatic import met_aromatic

TEST_CHAIN = 'A'
TEST_DISTANCE_CUTOFF = 6.0
TEST_ANGLE_CUTOFF = 109.5

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
