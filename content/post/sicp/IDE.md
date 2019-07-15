---
title: "IDE"
date: 2019-07-13T15:06:07+08:00
draft: true
---

# install racket

```sh
brew cask install racket
```

# install SICP Collections
<https://docs.racket-lang.org/sicp-manual/Installation.html>

1. Open the Package Manager: in DrRacket choose the menu "File" then choose "Package Manager...".

2. In the tab "Do What I Mean" find the text field and enter: sicp

3. Finally click the "Install" button.

4. Test it. Make sure DrRacket has "Determine language from source" in the bottom left corner. Write the following program and click run:
    ```scheme
    #lang sicp
    (inc 42)
    ```
    The expected output is 43.
