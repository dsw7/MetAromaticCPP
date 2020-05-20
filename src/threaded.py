from time import time
from concurrent import futures
from numpy import array_split
from pymongo import MongoClient
from tqdm import tqdm
from met_aromatic import met_aromatic


MAX_WORKERS = 5


class RunParallelJobs:
    def __init__(self, workers):
        data = [line.strip('\n') for line in open('C:/cygwin64/tmp/random_codes.txt')]
        self.blocks = array_split(data, workers)
        self.test_chain = "A"
        self.test_distance_cutoff = 6.0
        self.test_angle_cutoff = 109.5
        self.collection = MongoClient(port=27017)['load_test']['load_test']

    def worker(self, block):
        for code in tqdm(block):
            results = met_aromatic(
                code,
                self.test_chain,
                self.test_distance_cutoff,
                self.test_angle_cutoff
            )
            self.collection.insert(results)

    def deploy_jobs(self):
        with futures.ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:

            start_time = time()
            workers = [
                executor.submit(self.worker, block) for block in self.blocks
            ]

            if futures.wait(workers, return_when=futures.ALL_COMPLETED):
                print(time() - start_time)


if __name__ == '__main__':
    RunParallelJobs(MAX_WORKERS).deploy_jobs()
