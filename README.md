# Rosetta-code stats

Suite for measuring runtime of various [rosetta-code tasks](https://rosettacode.org/wiki/Category:Programming_Tasks).

## Usage

To build all tasks, run `./build-tasks.sh`. You may specify additional compile flags, i.e. `-O2`.

To generate runtime data for current build, run `./run-measure.sh`.

To generate runtime data for all optimization levels run `./generate-data.sh` and collect `out/data.csv` with the results.


