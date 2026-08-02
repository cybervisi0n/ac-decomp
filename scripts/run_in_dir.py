#!/usr/bin/env python3

import subprocess
import sys


def main() -> int:
    if len(sys.argv) < 3:
        print(f"usage: {sys.argv[0]} DIRECTORY COMMAND [ARG ...]", file=sys.stderr)
        return 2

    return subprocess.run(sys.argv[2:], cwd=sys.argv[1], check=False).returncode


if __name__ == "__main__":
    raise SystemExit(main())
