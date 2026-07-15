# Ask Mode - AGENTS.md

This file provides guidance to agents when working with code in this repository.

## Documentation Context (Non-Obvious)

- **`source/` directory is misleading** — it contains only one file (`point.cpp`) which is entirely commented out; the actual implementations live in headers (`include/point.h`) or root-level `.cpp` files
- **`include/` directory has 4 headers**, but only `point.h` has real content; `edge.h`, `grid.h`, `node.h` are empty stubs — they represent planned but unimplemented classes
- **No Makefile or CMakeLists.txt** — the project uses a VS Code task as its sole build system; there is no portable build configuration
- **Include style is inconsistent** — `mathutils.h` is included bare (`#include "mathutils.h"`) while `point.h` is included with path (`#include "include/point.h"`); this is a project-specific quirk, not a convention