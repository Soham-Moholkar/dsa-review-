# Validation report

Validated locally on 16 September 2026 using GCC 13.3.0 and Python 3.12.14.

## Results

| Check | Result |
|---|---|
| Handbook coverage | 80 entries: 40 GFG + 40 LeetCode across 10 patterns |
| Reference implementations compiled and executed | 240: brute force, intermediate, and optimal for every entry |
| Behavioral assertions | **17,374 passed; 0 failures** |
| Runtime checking | UndefinedBehaviorSanitizer, no recovery; libstdc++ assertions enabled |
| Metadata and manifest | All 80 entries agree |
| Local Markdown destinations | 488 checked before this report update; no broken destinations |
| Explained solutions | 80 `solution.md` files with worked traces and correctness arguments |
| Original attempts and personal tracker | Unchanged |

Commands:

```bash
python3 scripts/validate_structure.py
python3 scripts/test_solutions.py --sanitize
```

The behavioral run reports:

```text
TOTAL: 80 problems, 240 references, 17374 checks, 0 failing groups
```

## What the checks cover

Independent Python oracles compute expected answers on fixed examples and deterministic randomized small inputs. The seed is 20260916. Outputs are checked using the actual contract: mutated arrays, only the valid deduplicated prefix, distinct indices and matching sums for two-sum, any valid peak, normalized triplet ordering, and input preservation for LC 287. Normal and boundary cases include singleton inputs, duplicates, negative values, zeroes, missing answers, full-size windows, endpoint matches, wraparound subarrays, touching/nested intervals, and rectangular/one-row/one-column matrices.

Integer-boundary regressions cover second-largest sentinels, consecutive-value neighbour arithmetic, pair sums/complements, and cyclic placement of `INT_MIN`. Two large counting regressions use 50,000 equal elements. Large cases run only on the intermediate and optimal counting implementations; exponential and quadratic teaching baselines use small inputs.

## Corrections made

- Fixed limited-array frequency counting, including `[1]`, repeated maximum values, and values above the counted range.
- Replaced potentially overflowing `n`-addition duplicate encoding with negative counters.
- Checked cyclic-placement ranges before subtracting one, avoiding `INT_MIN - 1`.
- Guarded longest-consecutive neighbour arithmetic at both integer limits.
- Widened two-sum arithmetic before addition/subtraction and kept hash keys equally wide.
- Separated missing second-largest state from the valid `INT_MIN` value.
- Made GFG binary-search approaches consistently return the first occurrence.
- Corrected complexity descriptions for repeated linear consecutive searches, hash-plus-ordered-set 3Sum, sorting stack space, chocolate recursion, and bounded fruit-type maps.

## Limits

This verifies the documented **handbook contracts**, not every live platform's latest API or hidden test suite. See [contract differences](docs/CONTRACTS.md). Product and sum references retain the arithmetic-domain assumptions documented there. The test suite samples inputs; it is not an exhaustive proof or a performance benchmark of every maximum-size case. No claim of platform submissions or acceptance is made.

The historical DOCX is unchanged. Maintained Markdown and source files contain the corrections. GitHub Actions is configured to run structure and behavioral checks on pull requests and main pushes; the numbers above describe the local run, not an unobserved hosted run.
