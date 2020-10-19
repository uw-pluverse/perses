import unittest


class TestCheckCopyright(unittest.TestCase):

    def test_sanity_failure_msg_should_be_pretty_printed(self):
        with open("test/org/perses/reduction/sanity_failure_msg_test/sanity_failure_log.txt") as f:
            error_message = ''.join(f.read().split())
        start = error_message.find("*")
        end = error_message.rfind("*")
        result = error_message[start:end].find("Theinitialsanitycheckfailed")
        flag = False if result == -1 else True
        self.assertTrue(flag)


if __name__ == '__main__':
    unittest.main()
