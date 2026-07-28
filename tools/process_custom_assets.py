#!/usr/bin/env python3
import argparse
import json
import os
from pathlib import Path

from converters.pal16dis import pal16dis
from converters.pal16dis_chunked import pal16dis_chunked
from converters.vtxdis import vtxdis

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "GAFE01_00",  # USA Rev 0
    "GAFU01_00",  # Australia Rev 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "--source-root",
    type=Path,
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)

args = parser.parse_args()
version = str(args.version)
version_num = VERSIONS.index(version)
source_root = args.source_root
build_root = Path(os.getcwd())
out_dir = build_root / version
print(out_dir)

def process_asset(asset):
    #steps = config.custom_build_steps.setdefault("pre-compile", [])

    match asset.get("custom_type"):
        case None:
            return

        case "pal16":
            os.makedirs(os.path.dirname(out_dir / "include" / asset["header"]), exist_ok=True)
            pal16dis(out_dir / "bin" / asset["binary"], out_dir / "include" / asset["header"])

        case "pal16c":
            os.makedirs(os.path.dirname(out_dir / "include" / asset["header"]), exist_ok=True)
            pal16dis_chunked(out_dir / "bin" / asset["binary"], out_dir / "include" / asset["header"])

        case "vtx":
            os.makedirs(os.path.dirname(out_dir / "include" / asset["header"]), exist_ok=True)
            vtxdis(out_dir / "bin" / asset["binary"], out_dir / "include" / asset["header"])

        case _:
            print("Unknown asset type: " + asset["custom_type"])



# Parse the config and process all assets
config_path = out_dir / "config.json"
if config_path.exists():
    config_data = json.load(open(config_path))
    for asset in config_data.get("extract", []):
        process_asset(asset)
    for module in config_data.get("modules", []):
        for asset in module.get("extract", []):
            process_asset(asset)
    
    open("custom_assets_done.txt", 'a').close()