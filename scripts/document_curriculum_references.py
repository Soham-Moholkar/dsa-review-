#!/usr/bin/env python3
"""Refresh later-module study pages, navigation, and the root manifest.

Reference files with independent changes are rejected by the formatter. Learner
attempts and mistake logs are never written by this command.
"""
from format_curriculum_like_arrays import build
from sync_curriculum_indexes import main as indexes
from sync_repository_manifest import main as manifest


if __name__ == '__main__':
    build()
    indexes()
    manifest()
