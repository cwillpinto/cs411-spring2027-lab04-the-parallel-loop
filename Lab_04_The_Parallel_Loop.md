# Lab 4: The Parallel Loop

**CS 411: Computing Paradigms - Spring 2027**  
**Week 4: February 1-7, 2027**  
**Due:** February 7, 2027  
**Value:** 100 points

**Starter repository:** [Open the Spring 2027 starter](https://github.com/cwillpinto/cs411-spring2027-lab04-the-parallel-loop)

## Purpose

Convert a sequential image transform into a correct OpenMP loop. Prove that iterations are independent, preserve the checksum, and measure where speedup stops improving.

## Learning objectives

- Distinguish SIMD from MIMD execution
- Identify loop-carried dependencies
- Use an OpenMP reduction safely

## Before you begin

1. Review the Week 4 slide deck and assigned VoiceThread or reading.
2. Create your own repository from the Spring 2027 template linked in Blackboard. The starter includes a sequential reference, an incomplete parallel path, a CSV-producing benchmark, and public CTest checks.
3. Configure with `cmake -S . -B build`, build with `cmake --build build`, and run `ctest --test-dir build --output-on-failure` before editing. The test fails at the OpenMP TODO. Save this initial result in `Lab4_Terminal.txt`.

## Part A Classify the workload (25 points)

Decide whether the loop is a reasonable parallel target.

- In `Lab4_Analysis.md` or PDF, mark each read and write by iteration in the pixel transform. Explain why writing `result.pixels[i]` is independent across iterations.
- Identify `checksum` as the shared aggregate and explain why an unguarded `checksum += ...` would race.
- Classify the loop as data parallelism on a shared-memory MIMD machine. Contrast that with SIMD in one concrete sentence.

## Part B Parallelize (45 points)

Use OpenMP without changing observable output.

- Complete the parallel branch in `src/transform.cpp` with an OpenMP `parallel for` over independent pixels. Honor the requested worker count and report the number of workers actually observed.
- Use an OpenMP reduction for the 64-bit checksum. Keep each output pixel equal to the sequential result.
- Preserve the sequential reference path and the `transform_image` API. Empty input must remain valid.

## Part C Measure (30 points)

Compare correctness before performance.

- After CTest passes, run the `lab4` executable at least three times. It prints CSV rows for 1, 2, 4, and 8 requested workers; save one complete run as `Lab4_Timing.csv` and all commands/output as `Lab4_Terminal.txt`.
- Report checksum, observed worker count, elapsed time, and speedup relative to the 1-worker row. Explain why checksum equality is checked before interpreting time.
- Identify the first point where scaling flattens, if it does, and connect that observation to thread overhead or memory bandwidth. If it does not flatten, explain what additional data would locate the limit.

## Verification

- `cmake --build build` succeeds after a clean configure.
- `ctest --test-dir build --output-on-failure` passes, including the multiple-worker check.
- Parallel output pixels and checksums match the sequential reference for the public edge cases.

## What to submit

Submit your own repository URL and:

1. Your own repository URL (created from the Spring 2027 template).
2. `src/transform.cpp` and the unchanged public `tests/transform_tests.cpp` in that repository.
3. `Lab4_Analysis.pdf` or `Lab4_Analysis.md`.
4. `Lab4_Timing.csv` and `Lab4_Terminal.txt`.

## Rubric

| Criterion | Points |
| --- | ---: |
| Dependency analysis | 20 |
| Execution-model explanation | 10 |
| Correct OpenMP implementation | 35 |
| Reduction and checksum evidence | 20 |
| Timing interpretation | 15 |
| **Total** | **100** |

## AI usage and academic integrity

Add an **AI Usage** section to the required analysis file. Name each tool and list the prompts or interactions that affected the work. If you did not use AI, write `AI Usage: None.` You must be able to explain and defend every submitted design and line of code.

## Late work

Late work may be accepted for up to three calendar days with a 25 percent deduction per day, following the course syllabus.
