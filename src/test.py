from json import loads
from pytest import mark


TEST_DATA_NO_EXCEPTIONS = [loads(line) for line in open('test_data_valid_results.json')]
TEST_DATA_EXCEPTIONS = [loads(line) for line in open('test_data_invalid_results.json')]


@mark.parametrize(
    'code',
    [item['_id'] for item in TEST_DATA_NO_EXCEPTIONS]
)
def test_met_aromatic_valid_results(code):
    test_results = None
    for entry in TEST_DATA_NO_EXCEPTIONS:
        if code == entry['_id']:
            test_results = entry['results']
        else:
            pass

    if test_results:
        print(test_results)

    # TODO: add assertion here

@mark.parametrize(
    'code',
    [item['_id'] for item in TEST_DATA_EXCEPTIONS]
)
def test_met_aromatic_invalid_results(code):
    test_results = None
    for entry in TEST_DATA_EXCEPTIONS:
        if code == entry['_id']:
            test_results = entry['exception']
        else:
            pass

    if test_results:
        print(test_results)

    # TODO: add assertion here
