# Arrays and Vectors DSA Revision Repository — Soham

A C++17 study and revision repository based on the **Arrays and Vectors DSA Pattern Handbook**, with explained solutions and executable checks for all 80 entries.

**Start here:** [Study guide](docs/START_HERE.md) · [Problem index](INDEX.md) · [Contract differences](docs/CONTRACTS.md) · [Validation report](VALIDATION_REPORT.md)

## Coverage

- **10 pattern groups**
- **80 platform entries**
- **40 GeeksforGeeks folders**
- **40 LeetCode folders**
- Brute-force, better, and optimal C++ references for every entry
- A plain-language explanation, worked trace, and correctness argument in every `solution.md`
- Automated behavioral checks for all **240 reference implementations**
- Original-attempt slots, mistake logs, test cases, metadata, and spaced-revision tables

## Important rule about original attempts

The repository never fabricates your personal code. `01_original_attempt.cpp` is a placeholder until your exact attempt is available. The one exact attempt already captured in the earlier sample is retained for **LeetCode 217 — Contains Duplicate**.

## Folder format

```text
Pattern/
├── GeeksforGeeks/
│   └── Problem/
└── LeetCode/
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
5. Compare brute, better, and optimal approaches.
6. Re-code after two days and one week.

## Accuracy note

Problem titles and pattern grouping follow the uploaded handbook. Problem summaries, signatures, and reference implementations are study material; platform prompts and signatures can be revised, so verify the live prompt before submitting.

## Check the solutions

Requires Python 3.9+ and g++ with C++17 support. Run from this repository's root:

```bash
python3 scripts/validate_structure.py
python3 scripts/test_solutions.py --problem LC_1_Two_Sum --sanitize
python3 scripts/test_solutions.py --sanitize
```

The runner compares results with independent Python oracles and checks in-place outputs, valid index pairs, valid peaks, and LC 287 input preservation. A fixed random seed makes failures reproducible. Brute-force inputs stay small so educational exponential solutions remain runnable. GitHub Actions runs these checks on pull requests and pushes to main.

`01_original_attempt.cpp` and the progress tracker describe **your practice**, not the existence of a reference solution. They are deliberately not marked solved by an automated solution audit. See [START_HERE](docs/START_HERE.md) for a standalone driver and revision workflow.
