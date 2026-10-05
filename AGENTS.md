# AGENTS.md

Hugo static site for the "Základy programovania" (BIAX10029) course. Uses the Hextra theme (Go module,
`github.com/imfing/hextra`). All content is written in Slovak.

## Commands

- Dev server: `hugo server --buildDrafts --disableFastRender` (serves at http://localhost:1313)
- Production build: `hugo --gc --minify` (outputs to `public/`, which is gitignored)
- Hugo version is pinned to **0.162.1 extended** in CI (`.github/workflows/*.yaml`). Use the extended build.

## Content layout

All content lives in `content/` with these sections: `assignments`, `examples`, `exercises`, `guides`, `lectures`. Each
section has an `_index.md`; exercises are nested as `exercise-N/task-N-M.md` and examples are nested by category.

- Section `_index.md` files use `cascade: { type: docs }` (see `content/exercises/_index.md` and
  `content/examples/_index.md`). The `guides`, `lectures`, and `assignments` sections currently do not set this.
- Exercise `_index.md` files use `type: 'exercise'` and a `weight` (see `content/exercises/exercise-9/_index.md`).
- Task pages use a `weight` in front matter.
- Assignments are duplicated: `content/assignments/assignment1`/`assignment2` are empty shells, while the full
  assignment text lives under `content/assignments/2025/assignment1` and `2025/assignment2`.

## Adding new content

Use `hugo new` with the provided archetypes rather than hand-writing front matter:

- `archetypes/exercise.md` — exercise section (contains `{{< pdf ... >}}` and a `cards` grid of tasks)
- `archetypes/task.md` — individual task (C++17 task template)
- `archetypes/default.md` — generic page (defaults to `draft: true`)

## Task solutions

Published solution visibility is decided per exercise (instructor-controlled) — do not bulk-change it:

- **exercise-1**: solutions are shown in `{{< details title="Rozbaľ pre ukážku riešenia" closed="true" >}}` blocks.
- **exercises 2–9**: solution code is stored as HTML comments (`<!-- ... -->`) in each `task-N-M.md`; the page
  renders only the sentence "Tu neskôr pribudne príkladné riešenie". Do not un-comment them without being asked.

## Guides

`content/guides/` holds flat tutorial pages. Conventions:

- File names are English snake_case (`git_for_beginners.md`, `gcc.md`, `c_errors.md`); front matter and all body
  content are Slovak (`date`, `title` only).
- Every guide must have a card in `content/guides/_index.md` (`cards` grid); icons must come from the theme's
  heroicons set (an unknown name fails the build, e.g. `command-line` is invalid, `terminal`/`cog`/`folder` are valid).
- Guides cross-link each other with relative paths (`../gcc/`). Anchors keep Slovak diacritics
  (e.g. `../gcc/#ladiace-informácie-a-sanitizery`).
- `/guides/git-for-beginners/` was published before the rename; it stays alive via `aliases:` in
  `git_for_beginners.md`. If you rename a guide that is already live, add an alias for the old URL.

## Example source files

Each file under `content/examples/` is a runnable C/C++ snippet paired with a Slovak `.md` page of the same basename that
contains the title, the source in a fenced code block, a download link, and a "Vysvetlenie" section. The `_index.md` lists
them as a `cards` grid grouped by category. Note: several `.c` files actually use C++ `new`; leave the code as-is.

## Shortcodes

- `{{< pdf "./file.pdf" >}}` is Hextra's built-in PDF shortcode. PDFs are stored next to the content that references
  them (e.g. `content/exercises/exercise-9/pevs-zapr-cpp.pdf`).
- Custom shortcodes in `layouts/shortcodes/`: `embed-pdf` (JS PDF.js viewer) and `iframe`. These are currently unused.

## CI / deployment

- `gh-pages.yaml` builds and deploys to GitHub Pages on push to `main` (baseURL `https://zapr.interes.group`, `CNAME`
  file present).
- `pr-build.yaml` runs a build check on PRs to `main`.
- `hugo.yaml` sets `outputs: home: [html, llms]` — the home page also emits an `llms.txt` for AI consumption.