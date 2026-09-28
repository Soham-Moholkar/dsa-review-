# Repository exercise: Detect Redundant Brackets

[Explained solution, worked trace, and local test command](solution.md) · [Live problem](https://github.com/Soham-Moholkar/dsa-review-/blob/main/04_Stacks_and_Queues/03_Parentheses_and_Expressions/Exercises/EX_Detect_Redundant_Brackets/README.md)

## Problem summary

Input has single-letter operands, binary + - * /, balanced parentheses, and no spaces. A pair is redundant when it encloses no operator or repeats a whole already grouped expression.

This is a study summary, not a verbatim copy of the platform statement. Confirm the live signature and constraints before submitting an adapted copy.

## Classification

| Field | Value |
|---|---|
| Platform | Repository exercise |
| Problem number | — |
| Study difficulty | Medium |
| Main topic | Stacks and Queues |
| Pattern | Parentheses and Expressions |
| Starter signature | `bool hasRedundantBrackets(string expression)` |

## Recognition cue

Distinguish grouping that changes an expression from an unnecessary pair.

## Invariant

A closed group is redundant when no operator lies inside its matching pair.

## Prerequisites

valid brackets; operators.

## Approach progression

| Level | Approach | Time | Extra space |
|---|---|---:|---:|
| Original | Your untouched first attempt | Not assessed until added | Not assessed |
| Brute force | Same efficient method (no distinct baseline) | O(n) | O(n) |
| Better | Same efficient method (no distinct intermediate) | O(n) | O(n) |
| Optimal | Parentheses reference | O(n) | O(n) |

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
