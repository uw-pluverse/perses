import unittest
from analyze_cache_profiling import *


class AnalyzeCacheProfilingTest(unittest.TestCase):
    def test_extract_entries(self):
        data = ["0000 100\n", "0002 200\n"]
        timestamp, cache = extract_entries(data)
        self.assertEqual(len(timestamp), 2)
        self.assertEqual(timestamp, [0, 2])
        self.assertEqual(cache, [100, 200])

    def test_average_usage(self):
        data = ["0000 100\n", "0002 200\n"]
        timestamp, cache = extract_entries(data)
        avg = average_usage(timestamp, cache)
        self.assertEqual(avg, 150)  # 50 = (200+100)//2

    def test_average_dict_item(self):
        key = 'a'
        orig_dict, update_dict = dict(), dict()
        orig_dict[key] = 50
        update_dict[key] = 100
        average_dict_item(orig_dict, update_dict, key)
        self.assertEqual(orig_dict[key], 75)  # (50+100)/2


if __name__ == '__main__':
    unittest.main()
