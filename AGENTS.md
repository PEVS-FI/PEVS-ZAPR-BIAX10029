# AGENTS.md

Hugo static site for the "Základy programovania" (BIAX10029) course. Uses the Hextra theme (Go module,
`github.com/imfing/hextra`). All content is written in Slovak.

## Commands

- Dev server: `hugo server --buildDrafts --disableFastRender` (serves at http://localhost:1313)
- Production build: `hugo --gc --minify` (outputs to `public/`, which is gitignored)
- Hugo version is pinned to **0.148.2 extended** in CI (`.github/workflows/*.yaml`). Use the extended build.

## Content layout

All content lives in `content/` with these sections: `assignments`, `examples`, `exercises`, `guides`, `lectures`. Each
section has an `_index.md`; exercises are nested as `exercise-N/task-N-M.md`.

- Section `_index.md` files use `cascade: { type: docs }` (see `content/exercises/_index.md`).
- Exercise `_index.md` files use `type: 'exercise'` and a `weight` (see `content/exercises/exercise-9/_index.md`).
- Task pages use a `weight` in front matter.

## Adding new content

Use `hugo new` with the provided archetypes rather than hand-writing front matter:

- `archetypes/exercise.md` — exercise section (contains `{{< pdf ... >}}` and a `cards` grid of tasks)
- `archetypes/task.md` — individual task (C++17 task template with a collapsible solution block)
- `archetypes/default.md` — generic page (defaults to `draft: true`)

## Shortcodes

- `{{< pdf "./file.pdf" >}}` is Hextra's built-in PDF shortcode. PDFs are stored next to the content that references
  them (e.g. `content/exercises/exercise-9/pevs-zapr-cpp.pdf`).
- Custom shortcodes in `layouts/shortcodes/`: `embed-pdf` (JS PDF.js viewer) and `iframe`.

## CI / deployment

- `gh-pages.yaml` builds and deploys to GitHub Pages on push to `main` (baseURL `https://zapr.interes.group`, `CNAME`
  file present).
- `pr-build.yaml` runs a build check on PRs to `main`.
- `hugo.yaml` sets `outputs: home: [html, llms]` — the home page also emits an `llms.txt` for AI consumption.
