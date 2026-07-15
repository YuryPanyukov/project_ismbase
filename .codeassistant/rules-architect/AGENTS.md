# Architect Mode - AGENTS.md

This file provides guidance to agents when working with code in this repository.

## Architecture Constraints (Non-Obvious)

- **No build system portability** — the project relies entirely on a VS Code task (`tasks.json`) pointing to a hardcoded MSYS2 UCRT64 `g++` path (`C:\msys64\ucrt64\bin\g++.exe`); this will not build on any system without that exact toolchain installed
- **Flat compilation model** — all `.cpp` files in root and `source/` are compiled into a single binary; there is no modular build, no library separation, and no incremental compilation
- **Stub headers indicate planned architecture** — `edge.h`, `grid.h`, `node.h` are empty, suggesting the project intends to model a graph/grid structure (edges, nodes, grid) but only `Point` (2D coordinate) is implemented so far
- **`Point` class is header-only** despite having a dedicated `source/point.cpp` — the `.cpp` file is dead code; any architectural changes to `Point` must be made in `include/point.h`
- **No test infrastructure** — any testing strategy must be built from scratch; there is no test framework, test directory, or CI configuration