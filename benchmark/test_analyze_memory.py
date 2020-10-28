#!/usr/bin/env python3

import os
import unittest
import tempfile
import analyze_memory

MINI_MEMORY_LOG = '''Timestamp        NGCMN    NGCMX     NGC     S0C   S1C       EC      OGCMN      OGCMX       OGC         OC       MCMN     MCMX      MC     CCSMN    CCSMX     CCSC    YGC    FGC   CGC 
         1800.2      0.0 31424512.0 10313728.0    0.0 163840.0 10149888.0        0.0 31424512.0  8036352.0  8036352.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    391     0    22
         1860.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         1920.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         1980.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         2040.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         2100.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         2160.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         2220.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         2280.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22
         2340.2      0.0 31424512.0 10530816.0    0.0 155648.0 10375168.0        0.0 31424512.0  7819264.0  7819264.0      0.0 1064960.0  16384.0      0.0 1048576.0   1792.0    392     0    22'''


class TestAnalyzeMemory(unittest.TestCase):

    def test_read_file(self):
        tmp_memory_log = tempfile.mkstemp()[1]
        print(tmp_memory_log)
        with open(tmp_memory_log, 'w+') as f:
            f. write(MINI_MEMORY_LOG)
        lines_returned = analyze_memory.read_file(tmp_memory_log)
        os.unlink(tmp_memory_log)
        lines_correct = MINI_MEMORY_LOG.split('\n')
        self.assertEqual(lines_returned, lines_correct)

    def test_get_average_heap_usage(self):
        average_returned = analyze_memory.get_average_heap_usage(MINI_MEMORY_LOG.split('\n'))
        average_correct = int(10530816+7819264)

        self.assertEqual(average_correct, average_returned)


if __name__ == '__main__':
    unittest.main()
