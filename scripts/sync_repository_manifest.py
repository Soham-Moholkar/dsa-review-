#!/usr/bin/env python3
"""Aggregate module metadata while preserving all published global problem IDs."""
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
            entries.append({'index':item.get('global_index',offset+item['index']),'folder':item['folder'],**metadata})
    entries.sort(key=lambda x:x['index'])
    candidate={x['folder']:x for x in entries}
    if any(candidate.get(old['folder'])!=old for old in previous):
        raise ValueError('Existing root manifest entries differ; review independent edits before updating')
    if [x['index'] for x in entries]!=list(range(1,len(entries)+1)):
        raise ValueError('Global IDs are duplicated or have gaps')
    if previous!=entries:path.write_text(json.dumps(entries,indent=2)+'\n')
    print(f'Root index: {len(entries)} entries; all existing global IDs preserved.')


if __name__=='__main__':main()
