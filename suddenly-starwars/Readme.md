# Suddenly... Star Wars!

A piece of applescript which will take over the currently running instance of OSX Terminal (or create a new one if Terminal isn't running) and use it to display ASCII Star Wars. Fun to use when you have SSH access to the account that's currently logged in on the screen.

# Background
- http://qrohlf.com/posts/happy-april-first/

# Requirements
- The target machine must be running OSX
- A user account must be logged in on the target machine
- you must be able to ssh into the target machine as the currently logged-in user

# Usage
Transfer the `starwars.applescript` file to the target, then ssh in and run it with 

```bash
osascript starwars.applescript
```
