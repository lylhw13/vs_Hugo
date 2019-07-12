---
title: "Check_integrity_on_windows"
date: 2019-07-12T17:12:51+08:00
draft: true
---

# download Gpg4win

- download Gpg4win from https://www.gpg4win.org/get-gpg4win.html
- check integrity of Gpg4win refer to [Check integrity of Gpg4win packages](https://www.gpg4win.org/package-integrity.html)

# verify file with .sig file
refer to [How to verify downloaded file with .sig file?](https://stackoverflow.com/questions/15331015/how-to-verify-downloaded-file-with-sig-file)

put emacs-26.2-x86_64.zip and emacs-26.2-x86_64.zip.sig in the same directory.

1. find public key ID
```
$ gpg emacs-26.2-x86_64.zip.sig
gpg: WARNING: no command supplied.  Trying to guess what you mean ...
gpg: assuming signed data in 'emacs-26.2-x86_64.zip'
gpg: Signature made 04/17/19 02:42:10 China Standard Time
gpg:                using RSA key 84930FFB79B645F7DEA29AD0AC6DD3FFD1D046BD
gpg: Can't check signature: No public key
```

2.  import the public key from key server. 
```
$ gpg --recv-key 84930FFB79B645F7DEA29AD0AC6DD3FFD1D046BD
gpg: key AC6DD3FFD1D046BD: 4 signatures not checked due to missing keys
gpg: key AC6DD3FFD1D046BD: public key "Phillip Lord <phillip.lord@newcastle.ac.uk>" imported
gpg: no ultimately trusted keys found
gpg: Total number processed: 1
gpg:               imported: 1
```

3. verify signature:
```
$ gpg emacs-26.2-x86_64.zip.sig
gpg: WARNING: no command supplied.  Trying to guess what you mean ...
gpg: assuming signed data in 'emacs-26.2-x86_64.zip'
gpg: Signature made 04/17/19 02:42:10 China Standard Time
gpg:                using RSA key 84930FFB79B645F7DEA29AD0AC6DD3FFD1D046BD
gpg: Good signature from "Phillip Lord <phillip.lord@newcastle.ac.uk>" [unknown]
gpg:                 aka "Phillip Lord <phillip.lord@russet.org.uk>" [unknown]
gpg: WARNING: This key is not certified with a trusted signature!
gpg:          There is no indication that the signature belongs to the owner.
Primary key fingerprint: 8493 0FFB 79B6 45F7 DEA2  9AD0 AC6D D3FF D1D0 46BD
```

The output should say "Good signature"
