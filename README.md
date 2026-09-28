# Soham's DSA Textbook

A long-term, C++17-first personal textbook for learning data structures and algorithms through original attempts, progressively improved approaches, explicit mistake logs, executable checks, and spaced revision.

**Start here:** [Study guide](docs/START_HERE.md) · [Problem index](INDEX.md) · [Progress tracker](PROGRESS_TRACKER.md) · [Contract differences](docs/CONTRACTS.md) · [Validation report](VALIDATION_REPORT.md)

## Textbook roadmap

| Module | Status |
|---|---|
| 01 Arrays & Vectors | Completed / reference module |
| 02 Strings | Completed reference curriculum — 45 unsolved learner starters |
| 03 Linked Lists | Planned |
| 04 Stacks & Queues | Completed reference curriculum — 55 unsolved learner starters (30 Stack, 25 Queue/Deque) |
| 05 Recursion & Backtracking | Planned |
| 06 Trees & BST | Planned |
| 07 Heaps / Priority Queue | Planned |
| 08 Graphs | Planned |
| 09 Greedy | Planned |
| 10 Dynamic Programming | Planned |

## Arrays & Vectors coverage

- **10 pattern groups**
- **80 platform entries**
- **40 GeeksforGeeks folders**
- **40 LeetCode folders**
- Brute-force, better, and optimal C++ references for every entry
- A detailed beginner appendix at the end of every reference file: signature, variables, line-by-line walkthrough, C++ keywords and STL calls, dry run, correctness, complexity, edge cases, and common mistakes
- A plain-language explanation, worked trace, and correctness argument in every `solution.md`
- Automated behavioral checks for all **240 reference implementations**
- Original-attempt slots, mistake logs, test cases, metadata, and spaced-revision tables

The [Strings module](02_Strings/) has 45 ordered problems (9 GeeksforGeeks, 36 LeetCode) and 135 implemented C++ reference files. The [Stacks & Queues module](04_Stacks_and_Queues/) has 55 problems across 11 stages (21 GeeksforGeeks, 26 LeetCode, 8 repository exercises), with 165 implemented references. Every original learner starter remains untouched and personally unsolved. Reference availability is separate from personal progress. Linked Lists remains planned as module 03.

For more GeeksforGeeks practice, use the [Strings GFG companions](02_Strings/GFG_PRACTICE.md) and [Stacks & Queues GFG companions](04_Stacks_and_Queues/GFG_PRACTICE.md). They link to additional live problems while preserving the numbered curriculum and your attempts.

Strings and Stacks/Queues now follow the completed Arrays/Vectors layout: each stage has `GeeksforGeeks/`, `LeetCode/`, or `Exercises/` platform folders. Every problem has the same ten study files, including `solution.md`, `revision_notes.md`, `metadata.json`, `testcases.md`, and the three consistently named reference approaches. The root `repository_manifest.json` indexes all **180** problems; each later module's own manifest retains its ordered curriculum and starter contracts.

## Non-negotiable rule about original attempts

The repository never fabricates or replaces your personal code. `01_original_attempt.cpp` remains a starter until your exact attempt is available. A reference solution being present never means that you personally solved the problem.

## Folder format

```text
Module/Stage/
├── GeeksforGeeks/
│   └── Problem/
├── LeetCode/
│   └── Problem/
└── Exercises/                 # repository exercises in Stacks & Queues
    └── Problem/
        ├── README.md
        ├── solution.md
        ├── 01_original_attempt.cpp
        ├── 02_brute_force.cpp
        ├── 03_better_approach.cpp
        ├── 04_optimal_solution.cpp
        ├── mistakes.md
        ├── testcases.md
        ├── revision_notes.md
        └── metadata.json
```

## Study workflow

1. Open the problem folder but do not read the reference code.
2. Solve on GFG or LeetCode.
3. Paste the exact first attempt into `01_original_attempt.cpp`.
4. Record the exact mistake in `mistakes.md`.
5. Ask for a hint before requesting a full solution.
6. Compare brute, better, and optimal approaches.
7. Re-code after two days, one week, and one month.
8. Update the progress tracker honestly; reference availability is separate from mastery.

## Accuracy note

Problem titles and pattern grouping in the first module follow the uploaded handbook. Problem summaries, signatures, and reference implementations are study material; platform prompts and signatures can be revised, so verify the live prompt before submitting.

## Check the solutions

Requires Python 3.9+ and g++ with C++17 support. Run from this repository's root:

```bash
python3 scripts/validate_structure.py
python3 scripts/test_solutions.py --problem LC_1_Two_Sum --sanitize
python3 scripts/test_solutions.py --sanitize
python3 scripts/test_curriculum_references.py --sanitize
```

The runner compares results with independent Python oracles and checks in-place outputs, valid index pairs, valid peaks, and LC 287 input preservation. A fixed random seed makes failures reproducible. Brute-force inputs stay small so educational exponential solutions remain runnable. GitHub Actions runs these checks on pull requests and pushes to main.

To rebuild the Arrays/Vectors code appendices, run `python3 scripts/add_detailed_cpp_comments.py`. For the later curricula, use `python3 scripts/format_curriculum_like_arrays.py` and then `python3 scripts/sync_repository_manifest.py`. The formatting script checks generated reference code against its source before writing, and never writes learner attempts or mistake logs. Structure validation checks that each reference has exactly one complete appendix.

`01_original_attempt.cpp` and the progress tracker describe **your practice**, not the existence of a reference solution. They are deliberately not marked solved by an automated solution audit. See [START_HERE](docs/START_HERE.md) for a standalone driver and revision workflow.
