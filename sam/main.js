/* ==========================================================================
   Portfolio behaviour — theme toggle, mobile nav, scroll reveal, typewriter,
   copy-to-clipboard. No dependencies.
   ========================================================================== */
(function () {
  "use strict";

  var reduceMotion = window.matchMedia
    ? window.matchMedia("(prefers-reduced-motion: reduce)").matches
    : false;

  /* ------------------------------------------------------------------
     1. Theme toggle
     ------------------------------------------------------------------ */
  function initTheme() {
    var toggle = document.getElementById("themeToggle");
    if (!toggle) return;

    function sync(theme) {
      toggle.setAttribute("aria-checked", String(theme === "light"));
      toggle.setAttribute(
        "title",
        theme === "light" ? "Switch to dark mode" : "Switch to light mode"
      );
    }

    sync(window.PortfolioTheme.current());

    toggle.addEventListener("click", function () {
      sync(window.PortfolioTheme.toggle());
    });

    // Follow the OS only while the visitor has not made an explicit choice.
    var mq = window.matchMedia ? window.matchMedia("(prefers-color-scheme: light)") : null;
    if (mq && mq.addEventListener) {
      mq.addEventListener("change", function (e) {
        var stored = null;
        try { stored = localStorage.getItem("sam-theme"); } catch (err) { stored = null; }
        if (!stored) {
          sync(window.PortfolioTheme.apply(e.matches ? "light" : "dark"));
        }
      });
    }
  }

  /* ------------------------------------------------------------------
     2. Mobile navigation
     ------------------------------------------------------------------ */
  function initNav() {
    var toggle = document.getElementById("navToggle");
    var links = document.getElementById("navLinks");
    if (!toggle || !links) return;

    function setOpen(open) {
      links.setAttribute("data-open", String(open));
      toggle.setAttribute("aria-expanded", String(open));
      toggle.setAttribute("aria-label", open ? "Close navigation menu" : "Open navigation menu");
    }

    setOpen(false);

    toggle.addEventListener("click", function () {
      setOpen(links.getAttribute("data-open") !== "true");
    });

    links.addEventListener("click", function (e) {
      if (e.target.closest("a")) setOpen(false);
    });

    document.addEventListener("keydown", function (e) {
      if (e.key === "Escape") setOpen(false);
    });

    document.addEventListener("click", function (e) {
      if (!e.target.closest(".nav") && !e.target.closest("#navLinks")) setOpen(false);
    });
  }

  /* ------------------------------------------------------------------
     3. Header border on scroll
     ------------------------------------------------------------------ */
  function initHeader() {
    var header = document.getElementById("siteHeader");
    if (!header) return;

    function update() {
      header.setAttribute("data-scrolled", String(window.scrollY > 12));
    }

    update();
    window.addEventListener("scroll", update, { passive: true });
  }

  /* ------------------------------------------------------------------
     4. Scroll reveal
     ------------------------------------------------------------------ */
  function initReveal() {
    var items = document.querySelectorAll(".reveal");
    if (!items.length) return;

    if (reduceMotion || !("IntersectionObserver" in window)) {
      items.forEach(function (el) { el.classList.add("is-visible"); });
      return;
    }

    var io = new IntersectionObserver(
      function (entries) {
        entries.forEach(function (entry, i) {
          if (!entry.isIntersecting) return;
          var el = entry.target;
          var delay = Number(el.dataset.revealDelay || 0);
          window.setTimeout(function () { el.classList.add("is-visible"); }, delay);
          io.unobserve(el);
        });
      },
      { rootMargin: "0px 0px -8% 0px", threshold: 0.12 }
    );

    items.forEach(function (el, index) {
      if (!el.dataset.revealDelay) {
        el.dataset.revealDelay = String((index % 4) * 70);
      }
      io.observe(el);
    });
  }

  /* ------------------------------------------------------------------
     5. Typewriter (hero role)
     ------------------------------------------------------------------ */
  function initTypewriter() {
    var el = document.getElementById("typedRole");
    if (!el || reduceMotion) return;

    var phrases = [
      "Fresh BSIT Graduate",
      "2nd Year BSIT Student",
      "Aspiring Software Engineer",
      "Beginner-Level Programmer"
    ];

    var phrase = 0;
    var chars = 0;
    var deleting = false;

    function tick() {
      var target = phrases[phrase];
      chars += deleting ? -1 : 1;
      el.textContent = target.slice(0, chars);

      var delay = deleting ? 45 : 85;
      if (!deleting && chars === target.length) {
        deleting = true;
        delay = 1900;
      } else if (deleting && chars === 0) {
        deleting = false;
        phrase = (phrase + 1) % phrases.length;
        delay = 320;
      }
      window.setTimeout(tick, delay);
    }

    el.textContent = "";
    window.setTimeout(tick, 260);
  }

  /* ------------------------------------------------------------------
     6. Copy email
     ------------------------------------------------------------------ */
  function initCopyEmail() {
    var btn = document.getElementById("copyEmail");
    var note = document.getElementById("copiedNote");
    if (!btn || !note) return;

    var resetTimer = null;

    function flash(message) {
      note.textContent = message;
      note.setAttribute("data-show", "true");
      window.clearTimeout(resetTimer);
      resetTimer = window.setTimeout(function () {
        note.setAttribute("data-show", "false");
      }, 2400);
    }

    btn.addEventListener("click", function () {
      var email = btn.dataset.email;
      if (!email) return;

      if (navigator.clipboard && navigator.clipboard.writeText) {
        navigator.clipboard.writeText(email).then(
          function () { flash("Copied to clipboard"); },
          function () { flash(email); }
        );
        return;
      }

      var helper = document.createElement("textarea");
      helper.value = email;
      helper.setAttribute("readonly", "");
      helper.style.position = "absolute";
      helper.style.left = "-9999px";
      document.body.appendChild(helper);
      helper.select();
      try {
        document.execCommand("copy");
        flash("Copied to clipboard");
      } catch (err) {
        flash(email);
      }
      document.body.removeChild(helper);
    });
  }

  /* ------------------------------------------------------------------
     7. Current-year stamp
     ------------------------------------------------------------------ */
  function initYear() {
    document.querySelectorAll("[data-year]").forEach(function (el) {
      el.textContent = String(new Date().getFullYear());
    });
  }

  function boot() {
    if (window.PortfolioTheme) window.PortfolioTheme.init();
    initTheme();
    initNav();
    initHeader();
    initReveal();
    initTypewriter();
    initCopyEmail();
    initYear();
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", boot);
  } else {
    boot();
  }
})();
