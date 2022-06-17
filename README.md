# Rosetta-code stats

Suite for measuring runtime of various [rosetta-code tasks](https://rosettacode.org/wiki/Category:Programming_Tasks).

## Usage

### `./build-tasks.sh [cflags]`
Build all task producing executables in `out/`.
- `cflags` (optional) - Additional flags passed to the compiler.

### `./run-measure.sh [n-samples]`
Run all tasks and measure their runtime. Outputs to `out/<task-name>.csv`.
- `n-samples` (optional) - Number of samples to collect for each task.

### `./generate-data.sh [n-samples]`
Build all tasks for each `-O` level. Outputs to `out/data.csv`.
- `n-samples` (optional) - Number of samples to collect for each task.



