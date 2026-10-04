/* ==========================================================================
   Theme controller — dark / light, persisted
   Placeholder for the blocking snippet that must run in the document head before paint
   ========================================================================== */
window.PortfolioTheme = (function () {
  "use strict";

  var STORAGE_KEY = "sam-theme";
  var DARK = "dark";
  var LIGHT = "light";

  function systemTheme() {
    return window.matchMedia && window.matchMedia("(prefers-color-scheme: light)").matches
      ? LIGHT
      : DARK;
  }

  function stored() {
    try {
      return localStorage.getItem(STORAGE_KEY);
    } catch (err) {
      return null;
    }
  }

  function store(value) {
    try {
      localStorage.setItem(STORAGE_KEY, value);
    } catch (err) {
      /* private mode — theme still applies for this session */
    }
  }

  function current() {
    var attr = document.documentElement.getAttribute("data-theme");
    return attr === LIGHT ? LIGHT : DARK;
  }

  function apply(theme) {
    document.documentElement.setAttribute("data-theme", theme);
    var meta = document.querySelector('meta[name="theme-color"]');
    if (meta) {
      meta.setAttribute("content", theme === LIGHT ? "#f5f8ff" : "#080c1a");
    }
    return theme;
  }

  function toggle() {
    var next = current() === LIGHT ? DARK : LIGHT;
    store(next);
    return apply(next);
  }

  return {
    DARK: DARK,
    LIGHT: LIGHT,
    init: function () {
      return apply(stored() || systemTheme());
    },
    apply: apply,
    toggle: toggle,
    current: current
  };
})();
