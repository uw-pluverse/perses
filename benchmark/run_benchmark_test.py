import unittest
import tempfile
from shutil import rmtree
from run_benchmark import *


class BenchmarkTest(unittest.TestCase):

    tmp_dir = None
    subjects = 'clang-22382'

    def setUp(self) -> None:
        self.tmp_dir = tempfile.mkdtemp()

    def tearDown(self) -> None:
        rmtree(self.tmp_dir)

    def test_extract_info_properties(self):
        src, script = extract_info_properties(subject_name=self.subjects)
        self.assertEqual(os.path.basename(src), 'small.c')
        self.assertEqual(os.path.basename(script), 'r.sh')

    def test_filename_generator(self):
        # bench basename should be extracted from the path
        bench = '../dummy_folder/dummy-bench'
        reducer, iteration, timemark = 'hdd', 0, '20200202'

        report, log = filename_generator(bench, reducer, iteration, timemark)
        self.assertEqual(report, 'tmp_dummy-bench_hdd_20200202_itr0.json')


if __name__ == '__main__':
    unittest.main()
