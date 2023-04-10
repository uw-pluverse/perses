import unittest
import tempfile
from convert_result_to_csv import *
from shutil import rmtree

benchmark_result = {
    "Bench": "gcc-00000",
    "perses": "20210101-000000",
    "Environment": "--query-cache-type COMPACT_QUERY_CACHE",
    "Origin token count": 10000,
    "Iteration": 0,
    "Query": 2000,
    "Time": 1000,
    "Token_remaining": 200,
    "Ret_code": 0
}

class SnapshotGeneratorTest(unittest.TestCase):

    tmp_dir = None
    dummy_json_1 = None
    dummy_json_2 = None
    dummy_log_1 = None

    def setUp(self) -> None:
        self.tmp_dir = tempfile.mkdtemp()
        json_dump = json.dumps(benchmark_result)
        self.dummy_json_1 = os.path.join(self.tmp_dir, 'tmp_gcc-00000_perses_20210101-000000_itr0.json')
        with open(self.dummy_json_1, 'w') as file:
            file.write(json_dump)
        self.dummy_json_2 = os.path.join(self.tmp_dir, 'tmp_gcc-00001_perses_20210101-000000_itr0.json')
        open(self.dummy_json_2, 'a').close()
        self.dummy_log_1 = os.path.join(self.tmp_dir, 'tmp_gcc-00000_perses_20210101-000000_itr0.log')
        open(self.dummy_log_1, 'a').close()

    def tearDown(self) -> None:
        rmtree(self.tmp_dir)

    def test_get_file_list(self):
        l = get_file_list(self.tmp_dir)
        self.assertEqual(len(l), 2)
        self.assertEqual(set(l), {self.dummy_json_1, self.dummy_json_2})

    def test_extract_from_json(self):
        header_row_1 = ['Bench', 'Query', 'Time', 'Token_remaining']
        header_row_2 = ['Bench']
        header_row_3 = []
        row_1 = extract_from_json(self.dummy_json_1, header_row_1)
        row_2 = extract_from_json(self.dummy_json_1, header_row_2)
        row_3 = extract_from_json(self.dummy_json_1, header_row_3)

        self.assertEqual(len(row_1), len(header_row_1))
        self.assertEqual(row_1, ["gcc-00000", 2000, 1000, 200])
        self.assertEqual(row_2, ["gcc-00000"])
        self.assertEqual(row_3, [])

    # TODO: currently program exits 128 when bazel calls 'git ...'
    # def test_csv_filename_generator(self):
    #     flag = None
    #     name = csv_filename_generator(flag)
    #     self.assertTrue(len(name.split('_')), 3)
    #     flag = 'test'
    #     name = csv_filename_generator(flag)
    #     self.assertTrue(len(name.split('_')), 4 and 'test' in name)

    def test_write_to_csv(self):
        rows = [['a', 'b'], ['c', 'd']]
        csv_f = write_to_csv(self.tmp_dir, rows, 'test.csv')
        self.assertTrue(os.path.exists(csv_f))
        with open(csv_f, 'r') as file:
            reader = csv.reader(file)
            for i, row in enumerate(reader):
                self.assertEqual(row, rows[i])

    def test_extract_config(self):
        config = extract_config(self.dummy_json_1)
        self.assertEqual(config, benchmark_result['Environment'])

    # def test_output_manager(self):
    #     rows = [['a', 'b'], ['c', 'd']]
    #     flag = 'test'
    #     config = benchmark_result['Environment']
    #     csv_f = output_manager(self.tmp_dir, rows, flag, config)
    #     snap_folder, csv_basename = os.path.split(csv_f)
    #     files = os.listdir(snap_folder)
    #     self.assertEqual(len(files), 2)
    #     self.assertTrue('config' in files)
    #     self.assertTrue(csv_basename in files)


if __name__ == '__main__':
    unittest.main()
