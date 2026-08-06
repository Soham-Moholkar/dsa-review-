from pathlib import Path

root = Path(__file__).resolve().parents[1]
required = {
    "README.md", "01_original_attempt.cpp", "02_brute_force.cpp",
    "03_better_approach.cpp", "04_optimal_solution.cpp", "mistakes.md",
    "testcases.md", "revision_notes.md", "metadata.json"
}
problem_folders = [p.parent for p in root.rglob("metadata.json") if p.name == "metadata.json"]
missing = []
for folder in problem_folders:
    absent = required - {p.name for p in folder.iterdir()}
    if absent:
        missing.append((folder, sorted(absent)))
print(f"Problem folders: {len(problem_folders)}")
if missing:
    for folder, files in missing:
        print(folder, files)
    raise SystemExit(1)
print("Structure validation passed.")
