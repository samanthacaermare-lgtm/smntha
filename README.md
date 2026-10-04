<div align="center">

# SAMANTHA A. CAERMARE

**Fresh BSIT Graduate • Aspiring Software Engineer**

[![Portfolio](https://img.shields.io/badge/Portfolio-Live-6C8CE0?style=for-the-badge&logo=github&logoColor=white)](https://samanthacaermare-lgtm.github.io/sam/)
[![Email](https://img.shields.io/badge/Email-samantha__caermare%40sjp2cd.edu.ph-6C8CE0?style=for-the-badge&logo=mail&logoColor=white)](mailto:samantha_caermare@sjp2cd.edu.ph)

</div>

---

## About Me

Hi, I'm **Samantha Caermare**, a second-year **BSIT** (Bachelor of Science in Information Technology)
student. I'm still early in my learning journey, and my main goal right now is to build a stronger
foundation in technology, one project at a time.

I learn by doing — school projects, small personal builds, and a lot of trial and error. Most of what
I know so far, I picked up by writing code that didn't work first, figuring out why, and trying again.
I'm open to feedback, eager to take on new challenges, and still figuring out which corner of software
engineering I want to specialize in.

I'm not claiming mastery of anything yet. What I can tell you honestly is that I'm consistent, I
finish what I start, and I care about writing code that's readable and easy to update.

### At a Glance

| | |
|---|---|
| **Who am I?** | 2nd Year BSIT Student • Aspiring Software Engineer |
| **What can I build?** | C++ console & graphical programs • Java Swing desktop apps • Basic HTML/CSS web pages |
| **How am I developing?** | Through perseverance, continuous learning, and practical project building |
| **Learning now** | C++ • C# • Java • PHP • Web development • Git/GitHub workflow |

---

## Tech Stack

*These are the technologies I have worked with so far — still at a beginner / entry-level, and
actively building up.*

### Languages

<p>
  <a href="https://skillicons.dev/icons?c=cpp" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=cpp&theme=dark" alt="C++" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=java" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=java&theme=dark" alt="Java" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=php" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=php&theme=dark" alt="PHP" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=html" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=html&theme=dark" alt="HTML" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=css" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=css&theme=dark" alt="CSS" width="36" height="36" /></a>
</p>

| Technology | Where I've used it | Level |
|:---|:---|:---|
| **C++** | Tic-Tac-Toe (SFML graphical game) | Beginner |
| **Java** | POS desktop application (Swing) | Beginner |
| **PHP** | School exercises | Beginner |
| **HTML** | Login page, portfolio site | Beginner |
| **CSS** | Styling for the above | Beginner |

### Tools

<p>
  <a href="https://skillicons.dev/icons?c=git" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=git&theme=dark" alt="Git" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=github" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=github&theme=dark" alt="GitHub" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=vscode" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=vscode&theme=dark" alt="VS Code" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=visualstudio" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=visualstudio&theme=dark" alt="Visual Studio" width="36" height="36" /></a>
  <a href="https://skillicons.dev/icons?c=canva" target="_blank" rel="noreferrer"><img src="https://skillicons.dev/icons?c=canva&theme=dark" alt="Canva" width="36" height="36" /></a>
</p>

| Tool | Notes |
|:---|:---|
| **Visual Studio** | Used for the C++ / SFML Tic-Tac-Toe project |
| **Visual Studio Code** | Main editor for web pages, PHP, and documentation |
| **Git & GitHub** | Version control, repositories, and profile README |
| **Canva** | Posters, certificates, and event-related visuals |
| **Microsoft Office** | Reports, spreadsheets, and presentations for schoolwork |

---

## Featured Projects

### 1. POS — Point of Sale System (Java)

A desktop point-of-sale application built with **Java Swing**, designed for a fast-food style menu.
Items are selected from image buttons, tracked in a live order table, and totalled automatically.

**Category:** `Desktop Application` · `GUI Programming`

| | |
|:---|:---|
| **Description** | Swing GUI ordering system with a live item table, automatic totals, cash/change calculation, and printable receipts |
| **Technologies** | Java · Swing · `JTable` · `DefaultTableModel` · `Vector` · `DecimalFormat` · Apache NetBeans |
| **Skills demonstrated** | Event handling · Table models · Array & loop iteration · `switch` statements · Number formatting · NetBeans GUI builder |

**Features (verified from source):**
- Product grid with 6 icon buttons — Spagetti, MangoPie, Palabok, CjoyBurg, CjoyPal, Bcktmeal
- Per-item quantity counter that increments on every click
- Live `JTable` order list with `ID`, `ITEM`, `QTY`, `PRICE` columns
- Re-selecting an existing item updates its row instead of creating a duplicate
- Automatic subtotal recalculation after every change, formatted with `DecimalFormat("00.00")`
- `DELETE` button removes the selected row and resets the matching counter
- `CASH` input + `PAY` button computes and displays the change / balance
- `PRINT` builds a formatted receipt in a `JTextArea` (items, subtotal, cash, balance) and sends it to the printer

| Link | |
|:---|:---|
| **Repository** | [ADD LINK] |
| **Demo** | [ADD LINK] |
| **Screenshots** | [NEEDS VERIFICATION] |

---

### 2. TIC-TAC-TOE (C++ / SFML)

A graphical two-player Tic-Tac-Toe game written in modern C++ using the **SFML 2.6.2** multimedia
library, with a pixel-art visual style and a menu-driven flow.

**Category:** `Game Development` · `Graphical Application`

| | |
|:---|:---|
| **Description** | Two-player Tic-Tac-Toe with a pixel-art board, hover-highlighted buttons, and a menu / playing / game-over flow |
| **Technologies** | C++17 · SFML 2.6.2 · Visual Studio · `enum class` · `std::array` · `std::optional` · `std::unique_ptr` |
| **Skills demonstrated** | Classes & encapsulation · Enumerated state machines · Value semantics · Game logic separation from rendering · Hit-testing |

**Features (verified from source):**
- `TicTacToe` game-logic class fully separated from the rendering loop
- Strongly typed `enum class GameState { Menu, Playing, GameOver }`, `CellState`, and `Player`
- `std::array<CellState, 9>` board with `std::optional<Player>` winner tracking
- `makeMove()` guards against out-of-range cells, occupied cells, and moves after game over
- Win detection across all 8 possible board patterns, plus full-board draw detection
- Custom `Button` class with mouse-hover state changes and its own draw routine
- Pixel-style `X` drawn from two rotated `RectangleShape` primitives; `O` from an outlined `CircleShape`
- Custom bitmap-style font loaded from `pixel_font.ttf`
- Fixed 60 FPS render loop on a 600x700 window

| Link | |
|:---|:---|
| **Repository** | [ADD LINK] |
| **Demo** | [ADD LINK] |
| **Screenshots** | [NEEDS VERIFICATION] |

---

## Development Projects

### 3. Login Page — HTML / CSS

A clean, responsive login interface built from plain HTML and CSS, using BoxIcons for the interface
icons.

**Category:** `Web Development` · `Front-End Fundamentals`

| | |
|:---|:---|
| **Description** | Single-page login form with username and password inputs, inline icons, a Remember Me option, and account-recovery and registration links |
| **Technologies** | HTML5 · CSS3 · BoxIcons |
| **Skills demonstrated** | Semantic HTML structure · Form controls · CSS layout and styling · External stylesheet linking · Icon integration |

**Features (verified from source):**
- Username and password input fields with placeholder text and HTML5 `required` validation
- Icon overlays inside each input field (user and lock icons)
- `Remember Me` checkbox and `Forget Password` link
- `Login` submit button and a `Register` link for new accounts
- Separate external stylesheet (`main.css`) and centered layout

| Link | |
|:---|:---|
| **Live Demo** | [View Demo](https://samanthacaermare-lgtm.github.io/sam/main.html) |
| **Repository** | [ADD LINK] |
| **Screenshots** | [NEEDS VERIFICATION] |

---

## Web Development

| Project | Stack | Status |
|:---|:---|:---|
| Login Page | HTML5, CSS3, BoxIcons | Live |
| Portfolio Site | HTML5, CSS3, Vanilla JS | In progress — light/dark theme |

---

## UI/UX Design

My UI work so far is tied directly to the interfaces I build in code — layout, spacing, colour
contrast, and interaction states (for example the hover behaviour on the Tic-Tac-Toe buttons) are
things I think about while coding rather than in a separate Figma-first workflow.

Tools: **Canva** for visual assets and event materials.

| Work | Status |
|:---|:---|
| Application UI (POS order screen, Tic-Tac-Toe menu) | Implemented in code |
| Canva visuals for school events and certificates | On request |
| Standalone UI/UX case studies | [ADD LINK] |

---

## Certificates & Events

| Certificate | Status |
|:---|:---|
| General Orientation & Assembly — E-Certificate | Issued · [NEEDS VERIFICATION] — date and issuer not yet provided |
| Leadership Training — E-Certificate | Issued · [NEEDS VERIFICATION] — date and issuer not yet provided |
| E-Certificate (third document) | [NEEDS VERIFICATION] — title not yet identified |

| Event | Role | Notes |
|:---|:---|:---|
| General Orientation & Assembly | Participant | [NEEDS VERIFICATION] — organiser and date |
| Leadership Training | Participant | [NEEDS VERIFICATION] — organiser and date |
| Other school events | [NEEDS VERIFICATION] | — |

---

## Currently Learning

Building a wider foundation, one topic at a time.

**Programming fundamentals**
- Strengthening the basics: variables, control flow, loops, functions, arrays
- reading errors properly instead of guessing, and using a debugger

**Languages**
- **C++** — moving past syntax into classes, `enum class`, pointers, and file handling
- **C#** — starting now, mostly to see how a different object-oriented syntax compares
- **Java** — deeper OOP, collections, and splitting larger programs into clean classes
- **PHP** — forms, databases, and connecting a front end to a back end

**Web development**
- Responsive layouts and CSS Grid / Flexbox done properly
- JavaScript basics so my pages can actually do something
- Separating HTML structure, CSS styling, and JS behaviour

**Software engineering concepts**
- The Git/GitHub workflow: branches, commits, issues, and pull requests that mean something
- Writing code others can read — naming, small functions, and comments that explain *why*
- Documentation as part of the work, not an afterthought

**Building practical applications**
- Finishing projects end to end, including the boring parts: setup instructions, README, and testing
- Reworking older projects so the code is cleaner than the first version

---

## Developer Mindset

Software development, to me, is a loop — and the loop matters more than any single breakthrough:

**Learn → Build → Make mistakes → Understand what went wrong → Improve → Try again → Grow**

Some of my best progress has come from the broken versions. I'd rather ship something imperfect
that I understand completely than something polished that I copied without learning why it works.

What I bring to that loop:

- **Perseverance** — I keep going when something doesn't work the first time
- **Curiosity** — I want to know how and why, not just how to make the error message disappear
- **Continuous learning** — I finish a project and immediately start learning the thing that would
  make it better
- **Honesty about skill level** — I'd rather show you working code and real progress than claim
  experience I haven't built yet

I'm looking for an entry-level Software Engineering role or internship where I can learn from a
mentor team, contribute to real code, and keep building toward becoming a proper software engineer.

---

## Contact

<div align="center">

[![GitHub](https://img.shields.io/badge/GitHub-samanthacaermare--lgtm-6C8CE0?style=for-the-badge&logo=github&logoColor=white)](https://github.com/samanthacaermare-lgtm)
[![Email](https://img.shields.io/badge/Email-samantha__caermare%40sjp2cd.edu.ph-6C8CE0?style=for-the-badge&logo=mail&logoColor=white)](mailto:samantha_caermare@sjp2cd.edu.ph)

**Open to entry-level Software Engineering roles, internships, and collaborations.**

</div>

---

<div align="center">

*Portfolio with light and dark themes → [samanthacaermare-lgtm.github.io/sam](https://samanthacaermare-lgtm.github.io/sam/)*

*Last updated: [NEEDS VERIFICATION]*

</div>#   s m n t h a  
 