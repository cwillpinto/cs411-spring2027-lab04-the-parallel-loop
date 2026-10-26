# CS411 Spring 2027 · Lab 4: The Parallel Loop

Read the included handout. Complete the TODO in `src/transform.cpp`; keep the sequential reference path and the `transform_image` API.

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/lab4
```

The unchanged starter builds, but its public test fails because it has not used multiple OpenMP workers. The program prints CSV rows for 1, 2, 4, and 8 requested workers. Use those rows for your timing evidence; run more than once before interpreting scaling.

## Work in your own GitHub repository

The instructor starter is an upstream source. Keep your completed work in a repository under your own GitHub account, then submit the repository URL and the evidence listed in the assignment handout through Blackboard.

If Blackboard links a template repository, choose **Use this template**, create the new repository under your account, and clone that new repository. Check `git remote -v` before pushing; `origin` must be your repository.

For a direct clone, first create an empty repository under your account. Replace the placeholders below with the starter link supplied in Blackboard and your own empty repository URL:

```sh
git clone <instructor-starter-url>
cd <cloned-directory>
git remote rename origin upstream
git remote add origin <your-empty-repository-url>
git remote -v
git push -u origin HEAD
```

Commit and push your completed work to your own `origin`. Do not push to the instructor's upstream repository. Use the exact submission files and verification commands in the assignment handout.
