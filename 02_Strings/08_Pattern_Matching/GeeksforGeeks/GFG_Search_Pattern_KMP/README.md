# GeeksforGeeks: Search Pattern (KMP Algorithm)

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://www.geeksforgeeks.org/problems/search-pattern0205/1)

## Problem summary

Build the prefix table and reuse matched information instead of restarting after a mismatch.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | GeeksforGeeks |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Strings |
| Pattern | Pattern Matching |
| Starter signature | `vector<int> search(string &pat, string &txt)` |

## Recognition cue

Build the prefix table and reuse matched information instead of restarting after a mismatch.

## Invariant

The prefix table stores the longest proper border of each processed prefix.

## Prerequisites

naive matching; prefix/suffix definitions.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Compare the pattern at each text position | O(nm) | O(1) plus result |
| Better | Same efficient method (no distinct intermediate) | O(n + m) | O(m) plus result |
| Optimal | Lps/prefix table reference | O(n + m) | O(m) plus result |

The levels compare actual code. Some basic exercises reuse the efficient approach when a separate intermediate algorithm would only be artificial. Time/space use the assumptions in the live prompt; `n` is input length unless the problem says otherwise. Output memory is listed separately where relevant.

## Files

- `01_original_attempt.cpp` — your exact learner starter; do not replace it with reference code.
- `02_brute_force.cpp` — baseline or explicitly identified identical efficient method.
- `03_better_approach.cpp` — intermediate tradeoff where meaningful.
- `04_optimal_solution.cpp` — preferred reference under the local contract.
- `mistakes.md` — your own error log, kept separate from generated notes.
- `testcases.md` — starter cases and space for your personal cases.
- `revision_notes.md` — pattern reminder and blank spaced-review log.
- `metadata.json` — machine-readable classification and approach costs.

## Attempt protocol

Read the live prompt, add two of your own tests, and attempt it in `01_original_attempt.cpp` before reading the [explained reference](solution.md). Record only mistakes you actually made.
