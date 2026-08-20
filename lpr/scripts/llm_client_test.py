#!/usr/bin/env python3

import unittest
import json
import tempfile
import os
import sys
import importlib.util
from shutil import rmtree
from unittest.mock import patch, MagicMock

# The default LLM client imports the third-party `openai` package at module load
# time, and that package is not part of the hermetic build. Make the module
# importable without it by injecting a stand-in when it is genuinely absent;
# tests that exercise the real client behavior are skipped in that case.
HAS_OPENAI = importlib.util.find_spec("openai") is not None
if not HAS_OPENAI:
    sys.modules["openai"] = MagicMock()

from lpr.scripts.llm_client import main

class TestLLMClient(unittest.TestCase):
    def setUp(self):
        self.test_dir = tempfile.mkdtemp()

    def tearDown(self):
        rmtree(self.test_dir)

    def write_input_file(self, message):
        fd, input_path = tempfile.mkstemp(dir=self.test_dir, suffix=".json")
        os.close(fd)
        with open(input_path, 'w') as f:
            json.dump({"message": message}, f)
        return input_path

    def read_output_file(self, path):
        if os.path.exists(path):
            with open(path, 'r') as f:
                return f.read()
        return None

    @patch('lpr.scripts.llm_client.OpenAI')
    def test_normal_operation(self, mock_openai):
        input_path = self.write_input_file("Test message")
        output_path = os.path.join(self.test_dir, "output.json")

        mock_client = mock_openai.return_value
        mock_response = MagicMock()
        mock_response.choices = [
            MagicMock(message=MagicMock(content=f"Response {i}"))
            for i in range(1, 6)  # Generate 5 mock responses
        ]
        mock_client.chat.completions.create.return_value = mock_response

        sys.argv = [
            'llm_client.py',
            '--input-file', input_path,
            '--output-file', output_path,
            '--num-completions', '5'
        ]
        main()

        output_string = self.read_output_file(output_path)
        output_json = json.loads(output_string)
        self.assertEqual(output_json, [
            "Response 1", "Response 2", "Response 3",
            "Response 4", "Response 5"
        ])

    def test_missing_input_file(self):
        output_path = os.path.join(self.test_dir, "output.json")

        sys.argv = [
            'llm_client.py',
            '--input-file', '/nonexistent/file',
            '--output-file', output_path
        ]

        # Verify error exit
        with self.assertRaises(SystemExit):
            main()

        # Verify output contents
        output_string = self.read_output_file(output_path)
        self.assertEqual(output_string, "Error: [Errno 2] No such file or directory: '/nonexistent/file'")

    @unittest.skipUnless(HAS_OPENAI, "requires the real openai package")
    def test_invalid_base_url(self):
        input_path = self.write_input_file("Test message")
        output_path = os.path.join(self.test_dir, "output.json")

        sys.argv = [
            'llm_client.py',
            '--input-file', input_path,
            '--output-file', output_path,
            '--base-url', 'http://invalid-url'
        ]

        # Verify error exit
        with self.assertRaises(SystemExit):
            main()

        # Verify output contents
        output_string = self.read_output_file(output_path)
        self.assertEqual(output_string, "Error: Connection error.")

if __name__ == '__main__':
    unittest.main()
