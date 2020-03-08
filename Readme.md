# Readme.md

SHBrowser is WebKit and GTK based web browser project.

---

1. Dependency

- GTKMM
- GTK+


Generate Makefiles

```

cmake -G "Unix Makefiles" -DPORT=GTK -DUSE_WPE_RENDERER=OFF

```

---

Build

```

make -j{core}

```
