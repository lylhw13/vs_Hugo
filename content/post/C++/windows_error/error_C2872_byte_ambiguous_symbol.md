---
title: "Error_C2872_byte_ambiguous_symbol"
date: 2020-10-20T09:43:02+08:00
draft: true
---

this is a workaround that should work for everyone, granted with some modifications needed.

This only happens if you're using "/std:c++17". Up to "/std:c++14" there's no issue. That's because "std::byte" was added in c++17. This also only happens if "using namespace std;" is declared BEFORE the offending Windows header.

Include the offending Windows header(s) before "using namespace std;"o. This allows the Windows header to be processed when "std::byte" isn't in the global scope, so there's no ambiguity.

If you continue using "using namespace std;" and you need to use either type byte, there's still a way to do it.

To use "std::byte", type it that way. This one place, you don't get to avoid "std::".

To use the Windows header "byte", type it "::byte".

No ambiguity either way.