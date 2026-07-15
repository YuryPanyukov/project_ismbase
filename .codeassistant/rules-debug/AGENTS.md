# Debug Mode - AGENTS.md

This file provides guidance to agents when working with code in this repository.

## Debugging Gotchas (Non-Obvious)

- **No debug configuration exists** — `.vscode/launch.json` has an empty `configurations` array; you must create a debug config before F5 debugging will work
- **Build task compiles all `.cpp` files together** — if you add a new `.cpp` file outside root or `source/`, it won't be compiled and the linker will fail silently with unresolved symbols
- **`source/point.cpp` is commented out** — if you uncomment it, the broken include `"/include/point.h"` (absolute path) will cause a compile error; the correct path is `"../include/point.h"`
- **Empty stub headers** (`edge.h`, `grid.h`, `node.h`) will cause "undefined reference" linker errors if any code tries to use classes from them — they have no implementations