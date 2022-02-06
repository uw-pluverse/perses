import unittest


class SanityFailureMsgTest(unittest.TestCase):

    def test_sanity_failure_msg_should_be_pretty_printed(self):
        with open("test/org/perses/reduction/sanity_failure_msg_test/sanity_failure_log.txt") as f:
            error_message = ''.join(f.read().split())
        start = error_message.find("****")
        end = error_message.rfind("****")
        message_segment = error_message[start:end]
        self.assertIn(
            "The initial sanity check failed.".replace(" ", ""),
            error_message
        )
        self.assertIn(
            "The files have been saved, and you can check them at".replace(" ", ""),
            message_segment
        )
        self.assertIn(
            "MARK=".replace(" ", ""),
            error_message
        )
        self.assertIn(
            "exit 1".replace(" ", ""),
            error_message
        )
        self.assertIn(
            "<empty>",
            error_message
        )


if __name__ == '__main__':
    unittest.main()
