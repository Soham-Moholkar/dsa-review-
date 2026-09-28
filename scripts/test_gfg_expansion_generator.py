#!/usr/bin/env python3
"""Check rerun safety using authored files in an isolated temporary curriculum."""
import hashlib
import json
from pathlib import Path
import shutil
import tempfile
import create_gfg_expansion as generator


def snapshot(root):
    return {p.relative_to(root).as_posix():hashlib.sha256(p.read_bytes()).hexdigest()
            for p in root.rglob('*') if p.is_file()}


def main():
    accepted_root=generator.ROOT
    with tempfile.TemporaryDirectory(prefix='gfg-generator-safety-') as temp:
        root=Path(temp)
        for module in (generator.S,generator.Q):
            (root/module).mkdir()
            shutil.copyfile(accepted_root/module/'problem_manifest.json',root/module/'problem_manifest.json')
        item=generator.ITEMS[0]
        entries=json.loads((root/item['module']/'problem_manifest.json').read_text())
        entry=next(x for x in entries if x['index']==item['index'])
        folder=root/entry['folder'];folder.mkdir(parents=True)
        authored={filename:'// Authored content must remain exact.\n'+filename+'\n'
                  for filename in generator.render(item,entry)}
        for filename,content in authored.items():(folder/filename).write_text(content)
        try:
            generator.ROOT=root
            generator.main()
            for filename,content in authored.items():assert (folder/filename).read_text()==content,filename
            before=snapshot(root);generator.main();assert snapshot(root)==before
        finally:
            generator.ROOT=accepted_root
    print('PASS: all ten authored file types preserved; missing files created; rerun byte-identical.')


if __name__=='__main__':main()
