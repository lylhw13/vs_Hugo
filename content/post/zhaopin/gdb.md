---
title: "Gdb"
date: 2020-08-13T11:11:11+08:00
draft: true
---

# starting and quitting
```gdb
gcc -g hello.c -o hello     // compile your code with symbolic debugging information included
gdb hello.exe               // start debug
help command                // get help
run [arg1] [arg2] [...]     // run the currently loaded program with the given command line arguments
quit                        //  exit the debugger 
file exename                // load an executable file by name
```

# Breakpoints and Watchpoints
```gdb
break location      // Set a breakpoint at a location, line number, or file (e.g. "main", "5", or "hello.c:23")
watch expression	// Break when a variable is written to
rwatch expression	// Break when a variable is read from
awatch expression	// Break when a variable is written to or read from
info break          // Display breakpoint and watchpoint information and numbers
info watch          // Same as info break
clear location	    // Clear a breakpoint from a location
delete num	        // Delete a breakpoint or watchpoint by number
```

# Stepping and Running
```gdb
next	    // Run to the next line of this function
step	    // Step into the function on this line, if possible
stepi	    // Step a single assembly instruction
continue	// Keep running from here
CTRL-C	    // Stop running, wherever you are
finish	    // Run until the end of the current function
advance location	// Advance to a location, line number, or file (e.g. "somefunction", "5", or "hello.c:23")
jump location	    // Just like continue, except jump to a particular location first.
```

# Examining and Modifying Variables
```gdb
display expression	    // Display the value of a variable or expression every step of the program—the expression must make sense in the current scope
info display	        // Show a list of expressions currently being displayed and their numbers
undisplay num	        // Stop showing an expression identified by its number (see info display)
print expression	    // Print the value of a variable or expression
printf formatstr expressionlist	        // Do some formatted output with printf() e.g. printf "i = %d, p = %s\n", i, p
set variable expression	                // Set a variable to value, e.g. set variable x=20
set (expression)	                    // Works like set variable
```

# Misc Commands
```gdb
RETURN	        // Hit RETURN to repeat the last command
backtrace	    // Show the current stack
bt	            // Alias for backtrace
attach pid	    // Attach to an already-running process by its PID
info registers	    // Dump integer registers to screen
info all-registers	// Dump all registers to screen
```