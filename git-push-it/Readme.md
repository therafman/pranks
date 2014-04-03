# Git *Push It*

A git commit hook to surreptitiously insert a link to Salt-N-Pepa's *Push It* music video into git commit messages.

# Background
- http://qrohlf.com/posts/happy-april-first/

# Usage
In a git repo belonging to the prank target, copy the contents of `commit-msg` to `.git/hooks/commit-msg`, making sure to `chmod +x .git/hooks/commit-msg`. Note that the git hooks directory is local-only - you'll need to do this on the specific clone of the repo that you wish to prank.
