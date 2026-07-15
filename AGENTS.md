# AGENTS.md

This file provides guidance to agents when working with code in this repository.

## Build & Run

- **Build**: `Ctrl+Shift+B` triggers VS Code task: `g++ -g *.cpp source/*.cpp -o <activeFile>.exe`
- **Compiler**: MSYS2 UCRT64 `g++` at `C:\msys64\ucrt64\bin\g++.exe`, C++ standard `gnu++17`
- **No Makefile/CMake** — build is VS Code task only; all `*.cpp` in root and `source/` are compiled together
- **No test framework** exists — no testing setup at all

## Code Structure Gotchas

- `source/point.cpp` is **entirely commented out** — the `Point` class methods are defined inline in `include/point.h` instead
- `source/point.cpp` contains a **broken include**: `#include "/include/point.h"` (leading `/` makes it an absolute path — would fail if uncommented); correct form is `#include "../include/point.h"` or `#include "include/point.h"`
- `include/edge.h`, `include/grid.h`, `include/node.h` are **empty stubs** (no header guards, no content)
- `main.cpp` mixes include styles: `#include "mathutils.h"` (local) and `#include "include/point.h"` (path-qualified) — inconsistent

## Conventions (Discovered from Code)

- **Header guards**: Use `#ifndef`/`#define`/`#endif` style (uppercase, underscore-separated, e.g., `POINT_H`)
- **Naming**: Classes are PascalCase (`Point`); methods/functions are camelCase (`getX`, `add`); member variables are lowercase single letters (`x`, `y`)
- **Default parameters**: Used in constructors (`Point(double x = 0.0, double y = 0.0)`)
- **Inline implementation**: Simple class methods defined directly in header (constructor, destructor)
- **No `using namespace std`** — explicit `std::` prefix used throughout