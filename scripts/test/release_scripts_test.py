#!/usr/bin/env python3

import unittest

import generate_release_notes


class TagParsingTest(unittest.TestCase):

    def test_parse_tag(self):
        self.assertEqual(generate_release_notes.parse_tag('v2.7'), (2, 7))
        self.assertEqual(generate_release_notes.parse_tag('v10.3'), (10, 3))
        self.assertIsNone(generate_release_notes.parse_tag('v2.10'))
        self.assertIsNone(generate_release_notes.parse_tag('v2'))
        self.assertIsNone(generate_release_notes.parse_tag('2.7'))
        self.assertIsNone(generate_release_notes.parse_tag('v2.7-rc1'))

    def test_next_release_tag(self):
        self.assertEqual(generate_release_notes.next_release_tag('v2.7'), 'v2.8')
        self.assertEqual(generate_release_notes.next_release_tag('v2.9'), 'v3.0')
        self.assertEqual(generate_release_notes.next_release_tag('v9.9'), 'v10.0')

    def test_parse_latest_tag_from_ls_remote(self):
        lines = [
            'aaaa\trefs/tags/v2.3',
            'bbbb\trefs/tags/v2.7',
            'cccc\trefs/tags/v2.7^{}',
            'dddd\trefs/tags/some-other-tag',
        ]
        self.assertEqual(
            generate_release_notes.parse_latest_tag_from_ls_remote(lines), 'v2.7')

    def test_parse_latest_tag_orders_by_version_not_lexicographically(self):
        lines = ['x\trefs/tags/v2.9', 'y\trefs/tags/v10.0']
        self.assertEqual(
            generate_release_notes.parse_latest_tag_from_ls_remote(lines), 'v10.0')

    def test_parse_latest_tag_requires_a_release_tag(self):
        with self.assertRaises(Exception):
            generate_release_notes.parse_latest_tag_from_ls_remote(
                ['x\trefs/tags/not-a-version'])


class UpstreamPatternTest(unittest.TestCase):

    def test_accepts_the_canonical_repo(self):
        for url in [
                'git@github.com:uw-pluverse/perses.git',
                'https://github.com/uw-pluverse/perses',
                'https://github.com/uw-pluverse/perses.git',
        ]:
            self.assertTrue(
                generate_release_notes.UPSTREAM_PATTERN.search(url), url)

    def test_rejects_forks_and_the_pre_rename_name(self):
        for url in [
                'git@github.com:someone/perses.git',
                'git@github.com:perses-project/perses.git',
                'git@github.com:uw-pluverse/perses-fork.git',
                'git@github.com:uw-pluverse/not-perses.git',
        ]:
            self.assertFalse(
                generate_release_notes.UPSTREAM_PATTERN.search(url), url)


class NotesRenderingTest(unittest.TestCase):

    def test_groups_by_conventional_type(self):
        notes = generate_release_notes.render_notes('v2.8', [
            'feat(snap): add the snapcraft packaging',
            'fix: handle empty files',
            'perf: cache the parse trees',
            'refactor!: rename the reduction entry point',
            'docs: update the readme',
            'chore: bump dependencies',
            'An externally merged pull request',
        ])
        self.assertEqual(notes.splitlines(), [
            'Perses v2.8',
            '',
            '## Breaking changes',
            '- rename the reduction entry point',
            '',
            '## New features',
            '- add the snapcraft packaging',
            '',
            '## Bug fixes',
            '- handle empty files',
            '',
            '## Improvements',
            '- cache the parse trees',
            '',
            '## Other changes',
            '- An externally merged pull request',
        ])

    def test_empty_range_is_a_maintenance_release(self):
        notes = generate_release_notes.render_notes('v2.8', ['docs: readme'])
        self.assertIn('Maintenance release.', notes)
        self.assertNotIn('##', notes)


if __name__ == '__main__':
    unittest.main()
