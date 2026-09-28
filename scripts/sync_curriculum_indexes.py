#!/usr/bin/env python3
"""Render navigation from manifests; stage order and stable IDs are separate."""
import json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
FILES=('02_brute_force.cpp','03_better_approach.cpp','04_optimal_solution.cpp')


def stage(item): return item['category'].split('_',1)[1].replace('_',' ')
def global_id(item): return item.get('global_index',80+item['index'])
def order(items): return sorted(items,key=lambda x:(x['category'],x['index']))


def main():
    modules={module:json.loads((ROOT/module/'problem_manifest.json').read_text()) for module in ('02_Strings','04_Stacks_and_Queues')}
    index=ROOT/'INDEX.md'
    root_rows=[index.read_text().split('## 02 Strings —',1)[0].rstrip(),'']
    for module,items in modules.items():
        title='02 Strings' if module=='02_Strings' else '04 Stacks & Queues'
        ordered=order(items)
        rows=['| Module ID | Stage | Platform | Problem | Difficulty | Folder |','|---:|---|---|---|---|---|']
        for item in ordered:
            rel=Path(item['folder']).relative_to(module).as_posix()
            rows.append(f'| {item["index"]} | {stage(item)} | {item["platform"]} | {item["title"]} | {item["difficulty"]} | [{Path(rel).name}]({rel}/) |')
        path=ROOT/module/'README.md';text=path.read_text();before,after=text.split('## Ordered problem list\n\n',1)
        suffix='\n\n## Reference policy'+after.split('## Reference policy',1)[1] if '## Reference policy' in after else '\n'
        path.write_text(before+'## Ordered problem list\n\n'+'\n'.join(rows)+suffix)
        root_rows += [f'## {title} — {len(items)} completed reference entries','',f'[Module theory and navigation]({module}/) · [Manifest]({module}/problem_manifest.json). Stable problem IDs preserve existing tracker records; read in stage order.','',
                      '| Global ID | Module ID | Stage | Platform | Problem | Difficulty | Folder |','|---:|---:|---|---|---|---|---|']
        for item in ordered:
            folder=item['folder'];root_rows.append(f'| {global_id(item)} | {item["index"]} | {stage(item)} | {item["platform"]} | {item["title"]} | {item["difficulty"]} | [{Path(folder).name}]({folder}/) |')
        root_rows.append('')
        for category in sorted({x['category'] for x in items}):
            entries=[x for x in ordered if x['category']==category]
            stage_path=ROOT/module/category/'README.md'
            intro=stage_path.read_text().split('Work through these in order:',1)[0].rstrip()
            lines=[intro,'','Work through these in order:','']
            for position,item in enumerate(entries,1):
                rel=Path(item['folder']).relative_to(module+'/'+category).as_posix()
                lines.append(f'{position}. [{item["title"]}]({rel}/) — {item["difficulty"]}; stable module ID {item["index"]}')
            lines+=['','## Platform and references','','| Module ID | Platform | Problem | References |','|---:|---|---|---|']
            for item in entries:
                rel=Path(item['folder']).relative_to(module+'/'+category).as_posix()
                refs=' · '.join(f'[{label}]({rel}/{filename})' for label,filename in zip(('Brute','Better','Optimal'),FILES))
                lines.append(f'| {item["index"]} | {item["platform"]} | [{item["title"]}]({rel}/) | {refs} |')
            stage_path.write_text('\n'.join(lines)+'\n')
        gfg=[x for x in ordered if x['platform']=='GeeksforGeeks']
        guide=[f'# GeeksforGeeks practice — {title}','','Every row below has a complete ten-file practice folder, an unsolved learner starter, and three implemented study references. Attempt the problem before opening the reference files.','',f'**{len(gfg)} GFG practice folders** across {len({x["category"] for x in items})} stages. These entries are included in the main curriculum, index, tests, and progress tracker.','',
               '| Module ID | Stage | Exercise folder | Live problem |','|---:|---|---|---|']
        for item in gfg:
            rel=Path(item['folder']).relative_to(module).as_posix()
            guide.append(f'| {item["index"]} | {stage(item)} | [{item["title"]}]({rel}/) | [GeeksforGeeks]({item["url"]}) |')
        guide += ['','Check the local contract before submitting: GFG signatures, sentinels, and index bases may differ from a related LeetCode exercise. Repeated patterns are deliberate transfer practice; your earlier attempts remain separate.','']
        (ROOT/module/'GFG_PRACTICE.md').write_text('\n'.join(guide))
    index.write_text('\n'.join(root_rows))
    print('Navigation updated: 63 Strings, 67 Stacks/Queues; 60 first-class GFG folders.')


if __name__=='__main__':main()
