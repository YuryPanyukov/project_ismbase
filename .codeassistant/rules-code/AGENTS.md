# Code Mode - AGENTS.md

This file provides guidance to agents when working with code in this repository.

## Coding Rules (Non-Obvious)

- `source/point.cpp` is **dead code** — all `Point` methods are inline in `include/point.h`; do NOT uncomment `source/point.cpp` without fixing the broken include path (`"/include/point.h"` → `"../include/point.h"`)
- `include/edge.h`, `include/grid.h`, `include/node.h` are **empty stubs** — they exist as placeholders but have no header guards or content; any code referencing them will fail to compile
- Include paths are **inconsistent** in the codebase: `main.cpp` uses both `#include "mathutils.h"` (bare) and `#include "include/point.h"` (path-qualified); prefer one style and stick to it
- All `*.cpp` files in root **and** `source/` are compiled together by the VS Code build task — you cannot add a new `.cpp` file outside these directories and expect it to be linked
- No `using namespace std` — always use explicit `std::` prefix