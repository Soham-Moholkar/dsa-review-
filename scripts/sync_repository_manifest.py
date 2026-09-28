#!/usr/bin/env python3
"""Aggregate the 80 Arrays entries and 100 later entries in one root index."""
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]


def main():
    path=ROOT/'repository_manifest.json'
    previous=json.loads(path.read_text())
    arrays=previous[:80]
    if len(arrays)!=80 or [x['index'] for x in arrays]!=list(range(1,81)):
        raise ValueError('Refusing to change the accepted Arrays/Vectors manifest')
    entries=list(arrays)
    for module,offset in (('02_Strings',80),('04_Stacks_and_Queues',125)):
        manifest=json.loads((ROOT/module/'problem_manifest.json').read_text())
        for item in manifest:
            metadata=json.loads((ROOT/item['folder']/'metadata.json').read_text())
            entries.append({'index':offset+item['index'],'folder':item['folder'],**metadata})
    if len(previous)>80 and previous[80:]!=entries[80:]:
        raise ValueError('Root manifest has independent edits; refusing to overwrite them')
    if previous!=entries:
        path.write_text(json.dumps(entries,indent=2)+'\n')
    print('Root index: 80 Arrays/Vectors + 45 Strings + 55 Stacks/Queues entries.')


if __name__=='__main__':main()
